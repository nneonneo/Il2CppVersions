#!/usr/bin/env python3
import glob
import os
import re
import subprocess
import shutil

def parseversion(v):
    x = re.findall(r'^(\d+)\.(\d+)\.(\d+)([a-z])(\d+)$', v)
    if x:
        return (int(x[0]), int(x[1]), int(x[2]), x[3], int(x[4]))
    x = re.findall(r'^(\d+)\.(\d+)\.(\d+)$', v)
    if x:
        return (int(x[0]), int(x[1]), int(x[2]), '', 0)

def split_class_structure(version, contents):
    ''' Split the Il2CppClass structure into pieces such that "specializable" fields (e.g. vtable)
        end up in between shared substructures. These specializable fields will be given their own
        types in type-specific class structures from the Inspector.

        This reduces duplication between class structures, which gives the reverse engineer central
        structures to modify should any changes to the other fields be necessary.'''

    # Dumb parser for the constrained syntax used in the Il2CppClass structure
    contents = contents.strip().split('\n')
    fields = []
    for row in contents:
        m = re.match(r'^(.+?)([a-zA-Z_]\w*)(|\s*:\s*\d+|\[\d+\]);$', row.strip())
        if not m:
            raise ValueError("failed to parse struct member %s" % row)
        ftype, fname, fsuffix = m.groups()
        fields.append((ftype.strip(), fname, fsuffix))

    # Figure out if the alignment of cctor_thread requires padding on 32-bit.
    # We need to do this because splitting the structure may change the alignment of the substructure.
    # Note that on 64-bit, cctor_thread will be either size_t or uint64_t so it is naturally aligned.
    # As of 2019.3.7, there are no other 64-bit aligned fields on 32-bit to worry about.
    size32 = 0
    for ftype, fname, fsuffix in fields:
        if fname == 'cctor_thread':
            if size32 % 8 != 0:
                cctor_thread_padding = True
            else:
                cctor_thread_padding = False
            break
        if '*' in ftype or ftype in ('size_t',):
            size32 += 4
        elif ftype in ('uint32_t', 'int32_t', 'GenericContainerIndex', 'CustomAttributeIndex'):
            size32 += 4
        elif ftype == 'Il2CppType':
            # one data member and one bitfield
            size32 += 8
        else:
            raise Exception("Size for field %s %s%s unknown!" % (ftype, fname, fsuffix))
    else:
        raise Exception("Field cctor_thread not found!")

    # Walk fields and generate structures.
    # Specializable fields will be represented by strings; substructures as lists.
    pieces = []
    for ftype, fname, fsuffix in fields:
        field = '    %s %s%s;' % (ftype, fname, fsuffix)
        if fname == 'cctor_thread':
            # There's no universal preprocessor define for 32-bit systems, so
            # we just have to define our own. Unfortunate but necessary.
            nfield = '#ifdef IS_32BIT\n'
            if cctor_thread_padding:
                nfield += '    uint32_t cctor_thread__padding;\n'
            # The start offset for the containing substructure might be 4 mod 8,
            # in which case declaring cctor_thread as uint64_t would again
            # introduce the wrong padding (and possibly add incorrect padding
            # at the end of this substructure by making the whole substructure
            # 8-byte aligned). To avoid this, we split this field into low and
            # high halves.
            nfield += '    uint32_t cctor_thread;\n'
            if 'int64_t' in ftype:
                nfield += '    uint32_t cctor_thread__hi;\n'
            nfield += '#else\n'
            nfield += field + '\n'
            nfield += '#endif'
            field = nfield

        if fname in ('interfaceOffsets', 'static_fields', 'rgctx_data', 'vtable'):
            # Strictly speaking, interfaceOffsets doesn't need to be here (it's
            # always iterated over so specializing it doesn't help). However, it
            # appears between vtable and static_fields in many older structures,
            # so "specializing" it means generating one less shared substructure.
            pieces.append(field)
        else:
            # Generic field - add to the last substructure or start a new one
            if len(pieces) == 0 or not isinstance(pieces[-1], list):
                pieces.append([])
            pieces[-1].append(field)

    # Create structure definitions
    substructs = ''
    classstruct = ''
    counter = 0
    for piece in pieces:
        if isinstance(piece, str):
            classstruct += piece + '\n'
        else:
            classstruct += '    struct Il2CppClass_%d _%d;\n' % (counter, counter)
            substructs += '''
typedef struct Il2CppClass_%d {
''' % counter + '\n'.join(piece) + '''
} Il2CppClass_%d;
''' % counter
            counter += 1

    return substructs + '''
typedef struct __attribute__((aligned(8))) Il2CppClass_Merged {
''' + classstruct + '''} Il2CppClass_Merged;
'''

def process_header(version, header):
    # force UNIX line endings for consistency
    header = header.replace('\r\n', '\n')
    # remove some unused static const variables
    header = re.sub(r'(?m)^.*?const\s+.*?kIl2CppU?Int\w+(Min|Max)\s*=\s*.+\n', '', header)
    header = re.sub(r'(?m)^.*?const\s+.*?kIl2CppNewLine.+\n', '', header)
    # remove useless pragmas
    header = re.sub(r'(?m)^\s*#pragma\s+once\s*\n', '', header)
    header = re.sub(r'(?m)^\s*#pragma\s+warning.+\n', '', header)
    # remove some C++-isms from older versions of the header (before they made it C compatible)
    header = re.sub(r'(?m)^template[^;]+;\n', '', header)
    header = re.sub(r'\bmutable\s+', '', header)
    # remove blank lines
    header = re.sub(r'(?m)^[ \t]*\n', '', header)

    # IDA needs array sizes to be macros or literals, and doesn't understand const ints
    header = header.replace('[kPublicKeyByteLength]', '[8]')
    # Older versions used TypeInfo; change it to Il2CppClass for consistency with newer headers
    header = re.sub(r'\bTypeInfo\b', 'Il2CppClass', header)
    # Decompilation of array accesses only works properly when VLA arrays have nonzero length
    header = header.replace('vtable[0]', 'vtable[32]')
    # Change all structs/enums/unions to use typedef for C compatibility
    header = re.sub(r'(?m)^(struct|union|enum)\s+(\w+)\s*\{([^\}]+(?:union\s*\{[^\}]+\}[^\}]*)*)^\};',
                    r'typedef \1 \2\n{\3} \2;', header)
    # Change all forward declarations into typedefs too
    header = re.sub(r'(?m)^struct(\s+)(\w+)\s*;', r'typedef struct\1\2 \2;', header)
    # Split the Il2CppClass structure into substructures so we can specialize certain fields
    # for e.g. vtable slot naming/typing
    m = re.search(r'struct\s+Il2CppClass\s*{\s*([^}]+)\n}(?:\s*Il2CppClass)?\s*;', header)
    if not m:
        raise Exception("struct Il2CppClass not found in %s" % version)
    header = header.replace(m.group(0), m.group(0) + '\n' + split_class_structure(version, m.group(1)))

    # Add only the necessary bits from object-internals.h; this is stable across all versions
    # (object-internals.h contains a lot of other C++ crap which would need to be stripped for IDA,
    # and may pull in extra headers that would bloat our generated header)
    header += '''
struct MonitorData;
struct Il2CppObject {
    struct Il2CppClass *klass;
    struct MonitorData *monitor;
};
typedef int32_t il2cpp_array_lower_bound_t;
struct Il2CppArrayBounds {
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
};
struct Il2CppArray {
    struct Il2CppObject obj;
    struct Il2CppArrayBounds *bounds;
    il2cpp_array_size_t max_length;
    /* vector must be 8-byte aligned.
       On 64-bit platforms, this happens naturally.
       On 32-bit platforms, sizeof(obj)=8, sizeof(bounds)=4 and sizeof(max_length)=4 so it's also already aligned. */
    void *vector[32];
};
struct Il2CppString {
    struct Il2CppObject object;
    int32_t length;
    uint16_t chars[32];
};
'''

    return header

for dir in glob.glob('../group*/il2cpp-*'):
    version = dir.split('il2cpp-')[1]
    dir = os.path.join(dir, 'libil2cpp')
    fn = os.path.join(dir, 'class-internals.h')
    if not os.path.exists(fn):
        fn = os.path.join(dir, 'il2cpp-class-internals.h')

    # We preprocess the file using dummy (empty) standard library headers
    # so that we only see the Il2Cpp-specific stuff.
    header = subprocess.check_output(['cpp', '-P', '-I', 'dummy', '-I', dir, fn]).decode()
    header = process_header(version, header)
    open('%s.h' % version, 'w').write(header)

    # Copy API function exports header
    shutil.copyfile(os.path.join(dir, 'il2cpp-api-functions.h'), os.path.join('../api', '%s.h' % version))

    # Differences with MSVC are all minor and irrelevant (up to 2019.3.7):
    # - __attribute__((aligned(8)))  ==>  __declspec(align(8))
    # - uint16_t Il2CppChar  ==>  wchar_t Il2CppChar (no actual change in size)
    # - char Il2CppNativeChar  ==>  wchar_t Il2CppNativeChar (affects signature of one function call: Il2CppSetFindPlugInCallback)
    # - SynchronizationContextCallback becomes __stdcall qualified
    # - Il2CppHStringHeader changes size (reserved chunk changes size)
    # But, it's good to check in case the config defines affect the structures we care about.
#    header = subprocess.check_output(['/mnt/c/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Tools/MSVC/14.16.27023/bin/Hostx86/x86/cl.exe', '/EP', '/I', 'dummy', '/I', dir, fn])
#    header = process_header(version, header)
#    open('%s.i' % version, 'w').write(header)
