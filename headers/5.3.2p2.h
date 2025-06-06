typedef void (*methodPointerType)();
typedef int32_t il2cpp_array_size_t;
typedef uint32_t Il2CppMethodSlot;
const int ipv6AddressSize = 16;
typedef int32_t il2cpp_hresult_t;
typedef enum Il2CppTypeEnum
{
 IL2CPP_TYPE_END = 0x00,
 IL2CPP_TYPE_VOID = 0x01,
 IL2CPP_TYPE_BOOLEAN = 0x02,
 IL2CPP_TYPE_CHAR = 0x03,
 IL2CPP_TYPE_I1 = 0x04,
 IL2CPP_TYPE_U1 = 0x05,
 IL2CPP_TYPE_I2 = 0x06,
 IL2CPP_TYPE_U2 = 0x07,
 IL2CPP_TYPE_I4 = 0x08,
 IL2CPP_TYPE_U4 = 0x09,
 IL2CPP_TYPE_I8 = 0x0a,
 IL2CPP_TYPE_U8 = 0x0b,
 IL2CPP_TYPE_R4 = 0x0c,
 IL2CPP_TYPE_R8 = 0x0d,
 IL2CPP_TYPE_STRING = 0x0e,
 IL2CPP_TYPE_PTR = 0x0f,
 IL2CPP_TYPE_BYREF = 0x10,
 IL2CPP_TYPE_VALUETYPE = 0x11,
 IL2CPP_TYPE_CLASS = 0x12,
 IL2CPP_TYPE_VAR = 0x13,
 IL2CPP_TYPE_ARRAY = 0x14,
 IL2CPP_TYPE_GENERICINST= 0x15,
 IL2CPP_TYPE_TYPEDBYREF = 0x16,
 IL2CPP_TYPE_I = 0x18,
 IL2CPP_TYPE_U = 0x19,
 IL2CPP_TYPE_FNPTR = 0x1b,
 IL2CPP_TYPE_OBJECT = 0x1c,
 IL2CPP_TYPE_SZARRAY = 0x1d,
 IL2CPP_TYPE_MVAR = 0x1e,
 IL2CPP_TYPE_CMOD_REQD = 0x1f,
 IL2CPP_TYPE_CMOD_OPT = 0x20,
 IL2CPP_TYPE_INTERNAL = 0x21,
 IL2CPP_TYPE_MODIFIER = 0x40,
 IL2CPP_TYPE_SENTINEL = 0x41,
 IL2CPP_TYPE_PINNED = 0x45,
 IL2CPP_TYPE_ENUM = 0x55
} Il2CppTypeEnum;
typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
const TypeIndex kTypeIndexInvalid = -1;
const TypeDefinitionIndex kTypeDefinitionIndexInvalid = -1;
const DefaultValueDataIndex kDefaultValueIndexNull = -1;
const EventIndex kEventIndexInvalid = -1;
const FieldIndex kFieldIndexInvalid = -1;
const MethodIndex kMethodIndexInvalid = -1;
const PropertyIndex kPropertyIndexInvalid = -1;
const GenericContainerIndex kGenericContainerIndexInvalid = -1;
const GenericParameterIndex kGenericParameterIndexInvalid = -1;
const RGCTXIndex kRGCTXIndexInvalid = -1;
const StringLiteralIndex kStringLiteralIndexInvalid = -1;
typedef uint32_t EncodedMethodIndex;
typedef enum Il2CppMetadataUsage
{
 kIl2CppMetadataUsageInvalid,
 kIl2CppMetadataUsageTypeInfo,
 kIl2CppMetadataUsageIl2CppType,
 kIl2CppMetadataUsageMethodDef,
 kIl2CppMetadataUsageFieldInfo,
 kIl2CppMetadataUsageStringLiteral,
 kIl2CppMetadataUsageMethodRef,
} Il2CppMetadataUsage;
static inline Il2CppMetadataUsage GetEncodedIndexType (EncodedMethodIndex index)
{
 return (Il2CppMetadataUsage)((index & 0xE0000000) >> 29);
}
static inline uint32_t GetDecodedMethodIndex (EncodedMethodIndex index)
{
 return index & 0x1FFFFFFFU;
}
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppTypeDefinitionMetadata Il2CppTypeDefinitionMetadata;
typedef union Il2CppRGCTXDefinitionData
{
 int32_t rgctxDataDummy;
 MethodIndex methodIndex;
 TypeIndex typeIndex;
} Il2CppRGCTXDefinitionData;
typedef enum Il2CppRGCTXDataType
{
 IL2CPP_RGCTX_DATA_INVALID,
 IL2CPP_RGCTX_DATA_TYPE,
 IL2CPP_RGCTX_DATA_CLASS,
 IL2CPP_RGCTX_DATA_METHOD
} Il2CppRGCTXDataType;
typedef struct Il2CppRGCTXDefinition
{
 Il2CppRGCTXDataType type;
 Il2CppRGCTXDefinitionData data;
} Il2CppRGCTXDefinition;
typedef struct Il2CppInterfaceOffsetPair
{
 TypeIndex interfaceTypeIndex;
 int32_t offset;
} Il2CppInterfaceOffsetPair;
typedef struct Il2CppTypeDefinition
{
 StringIndex nameIndex;
 StringIndex namespaceIndex;
 CustomAttributeIndex customAttributeIndex;
 TypeIndex byvalTypeIndex;
 TypeIndex byrefTypeIndex;
 TypeIndex declaringTypeIndex;
 TypeIndex parentIndex;
 TypeIndex elementTypeIndex;
 RGCTXIndex rgctxStartIndex;
 int32_t rgctxCount;
 GenericContainerIndex genericContainerIndex;
 MethodIndex delegateWrapperFromManagedToNativeIndex;
 int32_t marshalingFunctionsIndex;
 uint32_t flags;
 FieldIndex fieldStart;
 MethodIndex methodStart;
 EventIndex eventStart;
 PropertyIndex propertyStart;
 NestedTypeIndex nestedTypesStart;
 InterfacesIndex interfacesStart;
 VTableIndex vtableStart;
 InterfacesIndex interfaceOffsetsStart;
 uint16_t method_count;
 uint16_t property_count;
 uint16_t field_count;
 uint16_t event_count;
 uint16_t nested_type_count;
 uint16_t vtable_count;
 uint16_t interfaces_count;
 uint16_t interface_offsets_count;
 uint32_t bitfield;
 uint32_t token;
} Il2CppTypeDefinition;
typedef struct Il2CppFieldDefinition
{
 StringIndex nameIndex;
 TypeIndex typeIndex;
 CustomAttributeIndex customAttributeIndex;
 uint32_t token;
} Il2CppFieldDefinition;
typedef struct Il2CppFieldDefaultValue
{
 FieldIndex fieldIndex;
 TypeIndex typeIndex;
 DefaultValueDataIndex dataIndex;
} Il2CppFieldDefaultValue;
typedef struct Il2CppFieldMarshaledSize
{
 FieldIndex fieldIndex;
 TypeIndex typeIndex;
 int32_t size;
} Il2CppFieldMarshaledSize;
typedef struct Il2CppFieldRef
{
 TypeIndex typeIndex;
 FieldIndex fieldIndex;
} Il2CppFieldRef;
typedef struct Il2CppParameterDefinition
{
 StringIndex nameIndex;
 uint32_t token;
 CustomAttributeIndex customAttributeIndex;
 TypeIndex typeIndex;
} Il2CppParameterDefinition;
typedef struct Il2CppParameterDefaultValue
{
 ParameterIndex parameterIndex;
 TypeIndex typeIndex;
 DefaultValueDataIndex dataIndex;
} Il2CppParameterDefaultValue;
typedef struct Il2CppMethodDefinition
{
 StringIndex nameIndex;
 TypeDefinitionIndex declaringType;
 TypeIndex returnType;
 ParameterIndex parameterStart;
 CustomAttributeIndex customAttributeIndex;
 GenericContainerIndex genericContainerIndex;
 MethodIndex methodIndex;
 MethodIndex invokerIndex;
 MethodIndex delegateWrapperIndex;
 RGCTXIndex rgctxStartIndex;
 int32_t rgctxCount;
 uint32_t token;
 uint16_t flags;
 uint16_t iflags;
 uint16_t slot;
 uint16_t parameterCount;
} Il2CppMethodDefinition;
typedef struct Il2CppEventDefinition
{
 StringIndex nameIndex;
 TypeIndex typeIndex;
 MethodIndex add;
 MethodIndex remove;
 MethodIndex raise;
 CustomAttributeIndex customAttributeIndex;
 uint32_t token;
} Il2CppEventDefinition;
typedef struct Il2CppPropertyDefinition
{
 StringIndex nameIndex;
 MethodIndex get;
 MethodIndex set;
 uint32_t attrs;
 CustomAttributeIndex customAttributeIndex;
 uint32_t token;
} Il2CppPropertyDefinition;
typedef struct Il2CppMethodSpec
{
 MethodIndex methodDefinitionIndex;
 GenericInstIndex classIndexIndex;
 GenericInstIndex methodIndexIndex;
} Il2CppMethodSpec;
typedef struct Il2CppStringLiteral
{
 uint32_t length;
 StringLiteralIndex dataIndex;
} Il2CppStringLiteral;
typedef struct Il2CppGenericMethodIndices
{
 MethodIndex methodIndex;
 MethodIndex invokerIndex;
} Il2CppGenericMethodIndices;
typedef struct Il2CppGenericMethodFunctionsDefinitions
{
 GenericMethodIndex genericMethodIndex;
 Il2CppGenericMethodIndices indices;
} Il2CppGenericMethodFunctionsDefinitions;
const int kPublicKeyByteLength = 8;
typedef struct Il2CppAssemblyName
{
 StringIndex nameIndex;
 StringIndex cultureIndex;
 StringIndex hashValueIndex;
 StringIndex publicKeyIndex;
 uint32_t hash_alg;
 int32_t hash_len;
 uint32_t flags;
 int32_t major;
 int32_t minor;
 int32_t build;
 int32_t revision;
 uint8_t publicKeyToken[8];
} Il2CppAssemblyName;
typedef struct Il2CppImageDefinition
{
 StringIndex nameIndex;
 AssemblyIndex assemblyIndex;
 TypeDefinitionIndex typeStart;
 uint32_t typeCount;
 MethodIndex entryPointIndex;
 uint32_t token;
} Il2CppImageDefinition;
typedef struct Il2CppAssembly
{
 ImageIndex imageIndex;
 CustomAttributeIndex customAttributeIndex;
 int32_t referencedAssemblyStart;
 int32_t referencedAssemblyCount;
 Il2CppAssemblyName aname;
} Il2CppAssembly;
typedef struct Il2CppMetadataUsageList
{
 uint32_t start;
 uint32_t count;
} Il2CppMetadataUsageList;
typedef struct Il2CppMetadataUsagePair
{
 uint32_t destinationIndex;
 uint32_t encodedSourceIndex;
} Il2CppMetadataUsagePair;
#pragma pack(push, p1,4)
typedef struct Il2CppGlobalMetadataHeader
{
 int32_t sanity;
 int32_t version;
 int32_t stringLiteralOffset;
 int32_t stringLiteralCount;
 int32_t stringLiteralDataOffset;
 int32_t stringLiteralDataCount;
 int32_t stringOffset;
 int32_t stringCount;
 int32_t eventsOffset;
 int32_t eventsCount;
 int32_t propertiesOffset;
 int32_t propertiesCount;
 int32_t methodsOffset;
 int32_t methodsCount;
 int32_t parameterDefaultValuesOffset;
 int32_t parameterDefaultValuesCount;
 int32_t fieldDefaultValuesOffset;
 int32_t fieldDefaultValuesCount;
 int32_t fieldAndParameterDefaultValueDataOffset;
 int32_t fieldAndParameterDefaultValueDataCount;
 int32_t fieldMarshaledSizesOffset;
 int32_t fieldMarshaledSizesCount;
 int32_t parametersOffset;
 int32_t parametersCount;
 int32_t fieldsOffset;
 int32_t fieldsCount;
 int32_t genericParametersOffset;
 int32_t genericParametersCount;
 int32_t genericParameterConstraintsOffset;
 int32_t genericParameterConstraintsCount;
 int32_t genericContainersOffset;
 int32_t genericContainersCount;
 int32_t nestedTypesOffset;
 int32_t nestedTypesCount;
 int32_t interfacesOffset;
 int32_t interfacesCount;
 int32_t vtableMethodsOffset;
 int32_t vtableMethodsCount;
 int32_t interfaceOffsetsOffset;
 int32_t interfaceOffsetsCount;
 int32_t typeDefinitionsOffset;
 int32_t typeDefinitionsCount;
 int32_t rgctxEntriesOffset;
 int32_t rgctxEntriesCount;
 int32_t imagesOffset;
 int32_t imagesCount;
 int32_t assembliesOffset;
 int32_t assembliesCount;
 int32_t metadataUsageListsOffset;
 int32_t metadataUsageListsCount;
 int32_t metadataUsagePairsOffset;
 int32_t metadataUsagePairsCount;
 int32_t fieldRefsOffset;
 int32_t fieldRefsCount;
 int32_t referencedAssembliesOffset;
 int32_t referencedAssembliesCount;
} Il2CppGlobalMetadataHeader;
#pragma pack(pop, p1)
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppArrayType
{
 const Il2CppType* etype;
 uint8_t rank;
 uint8_t numsizes;
 uint8_t numlobounds;
 int *sizes;
 int *lobounds;
} Il2CppArrayType;
typedef struct Il2CppGenericInst
{
 uint32_t type_argc;
 const Il2CppType **type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
 const Il2CppGenericInst *class_inst;
 const Il2CppGenericInst *method_inst;
} Il2CppGenericContext;
typedef struct Il2CppGenericParameter
{
 GenericContainerIndex ownerIndex;
 StringIndex nameIndex;
 GenericParameterConstraintIndex constraintsStart;
 int16_t constraintsCount;
 uint16_t num;
 uint16_t flags;
} Il2CppGenericParameter;
typedef struct Il2CppGenericContainer
{
 int32_t ownerIndex;
 int32_t type_argc;
 int32_t is_method;
 GenericParameterIndex genericParameterStart;
} Il2CppGenericContainer;
typedef struct Il2CppGenericClass
{
 TypeDefinitionIndex typeDefinitionIndex;
 Il2CppGenericContext context;
 Il2CppClass *cached_class;
} Il2CppGenericClass;
typedef struct Il2CppGenericMethod
{
 const MethodInfo* methodDefinition;
 Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct Il2CppType
{
 union {
  void* dummy;
  TypeDefinitionIndex klassIndex;
  const Il2CppType *type;
  Il2CppArrayType *array;
  GenericParameterIndex genericParameterIndex;
  Il2CppGenericClass *generic_class;
 } data;
 unsigned int attrs : 16;
 Il2CppTypeEnum type : 8;
 unsigned int num_mods : 6;
 unsigned int byref : 1;
 unsigned int pinned : 1;
} Il2CppType;
typedef enum {
 IL2CPP_CALL_DEFAULT,
 IL2CPP_CALL_C,
 IL2CPP_CALL_STDCALL,
 IL2CPP_CALL_THISCALL,
 IL2CPP_CALL_FASTCALL,
 IL2CPP_CALL_VARARG
} Il2CppCallConvention;
typedef enum Il2CppCharSet
{
 CHARSET_ANSI,
 CHARSET_UNICODE
} Il2CppCharSet;
typedef struct PInvokeArguments
{
 const char* moduleName;
 const char* entryPoint;
 Il2CppCallConvention callingConvention;
 Il2CppCharSet charSet;
 int parameterSize;
 bool isNoMangle;
} PInvokeArguments;
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppAppDomain Il2CppAppDomain;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppAppContext Il2CppAppContext;
typedef struct Il2CppNameToTypeDefinitionIndexHashTable Il2CppNameToTypeDefinitionIndexHashTable;
typedef enum Il2CppTypeNameFormat
{
 IL2CPP_TYPE_NAME_FORMAT_IL,
 IL2CPP_TYPE_NAME_FORMAT_REFLECTION,
 IL2CPP_TYPE_NAME_FORMAT_FULL_NAME,
 IL2CPP_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED
} Il2CppTypeNameFormat;
extern bool g_il2cpp_is_fully_initialized;
typedef struct {
 Il2CppImage *corlib;
 Il2CppClass *object_class;
 Il2CppClass *byte_class;
 Il2CppClass *void_class;
 Il2CppClass *boolean_class;
 Il2CppClass *sbyte_class;
 Il2CppClass *int16_class;
 Il2CppClass *uint16_class;
 Il2CppClass *int32_class;
 Il2CppClass *uint32_class;
 Il2CppClass *int_class;
 Il2CppClass *uint_class;
 Il2CppClass *int64_class;
 Il2CppClass *uint64_class;
 Il2CppClass *single_class;
 Il2CppClass *double_class;
 Il2CppClass *char_class;
 Il2CppClass *string_class;
 Il2CppClass *enum_class;
 Il2CppClass *array_class;
 Il2CppClass *delegate_class;
 Il2CppClass *multicastdelegate_class;
 Il2CppClass *asyncresult_class;
 Il2CppClass *manualresetevent_class;
 Il2CppClass *typehandle_class;
 Il2CppClass *fieldhandle_class;
 Il2CppClass *methodhandle_class;
 Il2CppClass *systemtype_class;
 Il2CppClass *monotype_class;
 Il2CppClass *exception_class;
 Il2CppClass *threadabortexception_class;
 Il2CppClass *thread_class;
 Il2CppClass *appdomain_class;
 Il2CppClass *appdomain_setup_class;
 Il2CppClass *field_info_class;
 Il2CppClass *method_info_class;
 Il2CppClass *property_info_class;
 Il2CppClass *event_info_class;
 Il2CppClass *mono_event_info_class;
 Il2CppClass *stringbuilder_class;
 Il2CppClass *stack_frame_class;
 Il2CppClass *stack_trace_class;
 Il2CppClass *marshal_class;
 Il2CppClass *typed_reference_class;
 Il2CppClass *marshalbyrefobject_class;
 Il2CppClass *generic_ilist_class;
 Il2CppClass *generic_icollection_class;
 Il2CppClass *generic_ienumerable_class;
 Il2CppClass *generic_nullable_class;
 Il2CppClass *customattribute_data_class;
 Il2CppClass *version;
 Il2CppClass *culture_info;
 Il2CppClass *async_call_class;
 Il2CppClass *assembly_class;
 Il2CppClass *assembly_name_class;
 Il2CppClass *enum_info_class;
 Il2CppClass *mono_field_class;
 Il2CppClass *mono_method_class;
 Il2CppClass *mono_method_info_class;
 Il2CppClass *mono_property_info_class;
 Il2CppClass *parameter_info_class;
 Il2CppClass *module_class;
 Il2CppClass *pointer_class;
 Il2CppClass *system_exception_class;
 Il2CppClass *argument_exception_class;
 Il2CppClass *wait_handle_class;
 Il2CppClass *safe_handle_class;
 Il2CppClass *sort_key_class;
} Il2CppDefaults;
extern Il2CppDefaults il2cpp_defaults;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct Il2CppObject Il2CppObject;
typedef struct MemberInfo MemberInfo;
typedef struct CustomAttributesCache
{
 int count;
 Il2CppObject** attributes;
} CustomAttributesCache;
typedef struct CustomAttributeTypeCache
{
 int count;
 Il2CppClass** attributeTypes;
} CustomAttributeTypeCache;
typedef void (*CustomAttributesCacheGenerator)(CustomAttributesCache*, CustomAttributeTypeCache*);
const int THREAD_STATIC_FIELD_OFFSET = -1;
typedef struct FieldInfo
{
 const char* name;
 const Il2CppType* type;
 Il2CppClass *parent;
 int32_t offset;
 CustomAttributeIndex customAttributeIndex;
 uint32_t token;
} FieldInfo;
typedef struct PropertyInfo
{
 Il2CppClass *parent;
 const char *name;
 const MethodInfo *get;
 const MethodInfo *set;
 uint32_t attrs;
 CustomAttributeIndex customAttributeIndex;
 uint32_t token;
} PropertyInfo;
typedef struct EventInfo
{
 const char* name;
 const Il2CppType* eventType;
 Il2CppClass* parent;
 const MethodInfo* add;
 const MethodInfo* remove;
 const MethodInfo* raise;
 CustomAttributeIndex customAttributeIndex;
 uint32_t token;
} EventInfo;
typedef struct ParameterInfo
{
 const char* name;
 int32_t position;
 uint32_t token;
 CustomAttributeIndex customAttributeIndex;
 const Il2CppType* parameter_type;
} ParameterInfo;
typedef void* (*InvokerMethod)(const MethodInfo*, void*, void**);
typedef union Il2CppRGCTXData
{
 void* rgctxDataDummy;
 const MethodInfo* method;
 const Il2CppType* type;
 Il2CppClass* klass;
} Il2CppRGCTXData;
typedef struct MethodInfo
{
 methodPointerType method;
 InvokerMethod invoker_method;
 const char* name;
 Il2CppClass *declaring_type;
 const Il2CppType *return_type;
 const ParameterInfo* parameters;
 union
 {
  const Il2CppRGCTXData* rgctx_data;
  const Il2CppMethodDefinition* methodDefinition;
 };
 union
 {
  const Il2CppGenericMethod* genericMethod;
  const Il2CppGenericContainer* genericContainer;
 };
 CustomAttributeIndex customAttributeIndex;
 uint32_t token;
 uint16_t flags;
 uint16_t iflags;
 uint16_t slot;
 uint8_t parameters_count;
 uint8_t is_generic : 1;
 uint8_t is_inflated : 1;
} MethodInfo;
typedef struct Il2CppRuntimeInterfaceOffsetPair
{
 Il2CppClass* interfaceType;
 int32_t offset;
} Il2CppRuntimeInterfaceOffsetPair;
typedef struct Il2CppClass
{
 const Il2CppImage* image;
 void* gc_desc;
 const char* name;
 const char* namespaze;
 const Il2CppType* byval_arg;
 const Il2CppType* this_arg;
 Il2CppClass* element_class;
 Il2CppClass* castClass;
 Il2CppClass* declaringType;
 Il2CppClass* parent;
 Il2CppGenericClass *generic_class;
 const Il2CppTypeDefinition* typeDefinition;
 FieldInfo* fields;
 const EventInfo* events;
 const PropertyInfo* properties;
 const MethodInfo** methods;
 Il2CppClass** nestedTypes;
 Il2CppClass** implementedInterfaces;
 const MethodInfo** vtable;
 Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
 void* static_fields;
 const Il2CppRGCTXData* rgctx_data;
 struct Il2CppClass** typeHierarchy;
 uint32_t cctor_started;
 uint32_t cctor_finished;
 __attribute__((aligned(8))) uint64_t cctor_thread;
 GenericContainerIndex genericContainerIndex;
 CustomAttributeIndex customAttributeIndex;
 uint32_t instance_size;
 uint32_t actualSize;
 uint32_t element_size;
 int32_t native_size;
 uint32_t static_fields_size;
 uint32_t thread_static_fields_size;
 int32_t thread_static_fields_offset;
 uint32_t flags;
 uint32_t token;
 uint16_t method_count;
 uint16_t property_count;
 uint16_t field_count;
 uint16_t event_count;
 uint16_t nested_type_count;
 uint16_t vtable_count;
 uint16_t interfaces_count;
 uint16_t interface_offsets_count;
 uint8_t typeHierarchyDepth;
 uint8_t rank;
 uint8_t minimumAlignment;
 uint8_t packingSize;
 uint8_t valuetype : 1;
 uint8_t initialized : 1;
 uint8_t enumtype : 1;
 uint8_t is_generic : 1;
 uint8_t has_references : 1;
 uint8_t init_pending : 1;
 uint8_t size_inited : 1;
 uint8_t has_finalize : 1;
 uint8_t has_cctor : 1;
 uint8_t is_blittable : 1;
 uint8_t is_import : 1;
} Il2CppClass;

typedef struct Il2CppClass_0 {
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    const Il2CppType* byval_arg;
    const Il2CppType* this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass * generic_class;
    const Il2CppTypeDefinition* typeDefinition;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
} Il2CppClass_0;

typedef struct Il2CppClass_1 {
    struct Il2CppClass** typeHierarchy;
    uint32_t cctor_started;
    uint32_t cctor_finished;
#ifdef IS_32BIT
    uint32_t cctor_thread__padding;
    uint32_t cctor_thread;
    uint32_t cctor_thread__hi;
#else
    __attribute__((aligned(8))) uint64_t cctor_thread;
#endif
    GenericContainerIndex genericContainerIndex;
    CustomAttributeIndex customAttributeIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t packingSize;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import : 1;
} Il2CppClass_1;

typedef struct __attribute__((aligned(8))) Il2CppClass_Merged {
    struct Il2CppClass_0 _0;
    const MethodInfo** vtable;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct Il2CppClass_1 _1;
} Il2CppClass_Merged;

typedef struct Il2CppTypeDefinitionSizes
{
 uint32_t instance_size;
 int32_t native_size;
 uint32_t static_fields_size;
 uint32_t thread_static_fields_size;
} Il2CppTypeDefinitionSizes;
typedef struct Il2CppDomain
{
 Il2CppAppDomain* domain;
 Il2CppObject* setup;
 Il2CppAppContext* default_context;
 const char* friendly_name;
 uint32_t domain_id;
} Il2CppDomain;
typedef struct Il2CppImage
{
 const char* name;
 AssemblyIndex assemblyIndex;
 TypeDefinitionIndex typeStart;
 uint32_t typeCount;
 MethodIndex entryPointIndex;
 Il2CppNameToTypeDefinitionIndexHashTable* nameToClassHashTable;
 uint32_t token;
} Il2CppImage;
typedef struct Il2CppMarshalingFunctions
{
 methodPointerType marshal_to_native_func;
 methodPointerType marshal_from_native_func;
 methodPointerType marshal_cleanup_func;
} Il2CppMarshalingFunctions;
typedef struct Il2CppCodeRegistration
{
 uint32_t methodPointersCount;
 const methodPointerType* methodPointers;
 uint32_t delegateWrappersFromNativeToManagedCount;
 const methodPointerType** delegateWrappersFromNativeToManaged;
 uint32_t delegateWrappersFromManagedToNativeCount;
 const methodPointerType* delegateWrappersFromManagedToNative;
 uint32_t marshalingFunctionsCount;
 const Il2CppMarshalingFunctions* marshalingFunctions;
 uint32_t genericMethodPointersCount;
 const methodPointerType* genericMethodPointers;
 uint32_t invokerPointersCount;
 const InvokerMethod* invokerPointers;
 CustomAttributeIndex customAttributeCount;
 const CustomAttributesCacheGenerator* customAttributeGenerators;
} Il2CppCodeRegistration;
typedef struct Il2CppMetadataRegistration
{
 int32_t genericClassesCount;
 Il2CppGenericClass* const * genericClasses;
 int32_t genericInstsCount;
 const Il2CppGenericInst* const * genericInsts;
 int32_t genericMethodTableCount;
 const Il2CppGenericMethodFunctionsDefinitions* genericMethodTable;
 int32_t typesCount;
 const Il2CppType* const * types;
 int32_t methodSpecsCount;
 const Il2CppMethodSpec* methodSpecs;
 FieldIndex fieldOffsetsCount;
 const int32_t* fieldOffsets;
 TypeDefinitionIndex typeDefinitionsSizesCount;
 const Il2CppTypeDefinitionSizes* typeDefinitionsSizes;
 const size_t metadataUsagesCount;
 void** const* metadataUsages;
} Il2CppMetadataRegistration;
typedef struct Il2CppRuntimeStats
{
 uint64_t new_object_count;
 uint64_t initialized_class_count;
 uint64_t method_count;
 uint64_t class_static_data_size;
 uint64_t generic_instance_count;
 uint64_t generic_class_count;
 uint64_t inflated_method_count;
 uint64_t inflated_type_count;
 bool enabled;
} Il2CppRuntimeStats;
extern Il2CppRuntimeStats il2cpp_runtime_stats;
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppType Il2CppType;
typedef struct EventInfo EventInfo;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppArray Il2CppArray;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppProfiler Il2CppProfiler;
typedef struct Il2CppObject Il2CppObject;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppReflectionType Il2CppReflectionType;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppThread Il2CppThread;
typedef struct Il2CppAsyncResult Il2CppAsyncResult;
typedef enum Il2CppProfileFlags
{
 IL2CPP_PROFILE_NONE = 0,
 IL2CPP_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
 IL2CPP_PROFILE_ASSEMBLY_EVENTS = 1 << 1,
 IL2CPP_PROFILE_MODULE_EVENTS = 1 << 2,
 IL2CPP_PROFILE_CLASS_EVENTS = 1 << 3,
 IL2CPP_PROFILE_JIT_COMPILATION = 1 << 4,
 IL2CPP_PROFILE_INLINING = 1 << 5,
 IL2CPP_PROFILE_EXCEPTIONS = 1 << 6,
 IL2CPP_PROFILE_ALLOCATIONS = 1 << 7,
 IL2CPP_PROFILE_GC = 1 << 8,
 IL2CPP_PROFILE_THREADS = 1 << 9,
 IL2CPP_PROFILE_REMOTING = 1 << 10,
 IL2CPP_PROFILE_TRANSITIONS = 1 << 11,
 IL2CPP_PROFILE_ENTER_LEAVE = 1 << 12,
 IL2CPP_PROFILE_COVERAGE = 1 << 13,
 IL2CPP_PROFILE_INS_COVERAGE = 1 << 14,
 IL2CPP_PROFILE_STATISTICAL = 1 << 15,
 IL2CPP_PROFILE_METHOD_EVENTS = 1 << 16,
 IL2CPP_PROFILE_MONITOR_EVENTS = 1 << 17,
 IL2CPP_PROFILE_IOMAP_EVENTS = 1 << 18,
 IL2CPP_PROFILE_GC_MOVES = 1 << 19
} Il2CppProfileFlags;
typedef enum Il2CppGCEvent
{
 IL2CPP_GC_EVENT_START,
 IL2CPP_GC_EVENT_MARK_START,
 IL2CPP_GC_EVENT_MARK_END,
 IL2CPP_GC_EVENT_RECLAIM_START,
 IL2CPP_GC_EVENT_RECLAIM_END,
 IL2CPP_GC_EVENT_END,
 IL2CPP_GC_EVENT_PRE_STOP_WORLD,
 IL2CPP_GC_EVENT_POST_STOP_WORLD,
 IL2CPP_GC_EVENT_PRE_START_WORLD,
 IL2CPP_GC_EVENT_POST_START_WORLD
} Il2CppGCEvent;
typedef enum Il2CppStat
{
 IL2CPP_STAT_NEW_OBJECT_COUNT,
 IL2CPP_STAT_INITIALIZED_CLASS_COUNT,
 IL2CPP_STAT_METHOD_COUNT,
 IL2CPP_STAT_CLASS_STATIC_DATA_SIZE,
 IL2CPP_STAT_GENERIC_INSTANCE_COUNT,
 IL2CPP_STAT_GENERIC_CLASS_COUNT,
 IL2CPP_STAT_INFLATED_METHOD_COUNT,
 IL2CPP_STAT_INFLATED_TYPE_COUNT,
} Il2CppStat;
typedef enum StackFrameType
{
 FRAME_TYPE_MANAGED = 0,
 FRAME_TYPE_DEBUGGER_INVOKE = 1,
 FRAME_TYPE_MANAGED_TO_NATIVE = 2,
 FRAME_TYPE_SENTINEL = 3
} StackFrameType;
typedef enum Il2CppRuntimeUnhandledExceptionPolicy
{
 IL2CPP_UNHANDLED_POLICY_LEGACY,
 IL2CPP_UNHANDLED_POLICY_CURRENT
} Il2CppRuntimeUnhandledExceptionPolicy;
typedef struct Il2CppStackFrameInfo
{
 const MethodInfo *method;
} Il2CppStackFrameInfo;
typedef struct {
 void* (*malloc_func)(size_t size);
 void (*free_func)(void *ptr);
 void* (*calloc_func)(size_t nmemb, size_t size);
 void* (*realloc_func)(void *ptr, size_t size);
} Il2CppMemoryCallbacks;
typedef void (*register_object_callback)(void** arr, int size, void* userdata);
typedef void (*WorldChangedCallback)();
typedef void (*Il2CppFrameWalkFunc) (const Il2CppStackFrameInfo *info, void *user_data);
typedef void (*Il2CppProfileFunc) (Il2CppProfiler* prof);
typedef void (*Il2CppProfileMethodFunc) (Il2CppProfiler* prof, const MethodInfo *method);
typedef void (*Il2CppProfileAllocFunc) (Il2CppProfiler* prof, Il2CppObject *obj, Il2CppClass *klass);
typedef void (*Il2CppProfileGCFunc) (Il2CppProfiler* prof, Il2CppGCEvent event, int generation);
typedef void (*Il2CppProfileGCResizeFunc) (Il2CppProfiler* prof, int64_t new_size);
typedef const char* (*Il2CppSetFindPlugInCallback)(const char*);
typedef struct Il2CppMetadataField
{
 uint32_t offset;
 uint32_t typeIndex;
 const char* name;
 bool isStatic;
} Il2CppMetadataField;
typedef enum Il2CppMetadataTypeFlags
{
 kNone = 0,
 kValueType = 1 << 0,
 kArray = 1 << 1,
 kArrayRankMask = 0xFFFF0000
} Il2CppMetadataTypeFlags;
typedef struct Il2CppMetadataType
{
 Il2CppMetadataTypeFlags flags;
 Il2CppMetadataField* fields;
 uint32_t fieldCount;
 uint32_t staticsSize;
 uint8_t* statics;
 uint32_t baseOrElementTypeIndex;
 char* name;
 const char* assemblyName;
 uint64_t typeInfoAddress;
 uint32_t size;
} Il2CppMetadataType;
typedef struct Il2CppMetadataSnapshot
{
 uint32_t typeCount;
 Il2CppMetadataType* types;
} Il2CppMetadataSnapshot;
typedef struct Il2CppManagedMemorySection
{
 uint64_t sectionStartAddress;
 uint32_t sectionSize;
 uint8_t* sectionBytes;
} Il2CppManagedMemorySection;
typedef struct Il2CppManagedHeap
{
 uint32_t sectionCount;
 Il2CppManagedMemorySection* sections;
} Il2CppManagedHeap;
typedef struct Il2CppStacks
{
 uint32_t stackCount;
 Il2CppManagedMemorySection* stacks;
} Il2CppStacks;
typedef struct NativeObject
{
 uint32_t gcHandleIndex;
 uint32_t size;
 uint32_t instanceId;
 uint32_t classId;
 uint32_t referencedNativeObjectIndicesCount;
 uint32_t* referencedNativeObjectIndices;
} NativeObject;
typedef struct Il2CppGCHandles
{
 uint32_t trackedObjectCount;
 uint64_t* pointersToObjects;
} Il2CppGCHandles;
typedef struct Il2CppRuntimeInformation
{
 uint32_t pointerSize;
 uint32_t objectHeaderSize;
 uint32_t arrayHeaderSize;
 uint32_t arrayBoundsOffsetInHeader;
 uint32_t arraySizeOffsetInHeader;
 uint32_t allocationGranularity;
} Il2CppRuntimeInformation;
typedef struct Il2CppManagedMemorySnapshot
{
 Il2CppManagedHeap heap;
 Il2CppStacks stacks;
 Il2CppMetadataSnapshot metadata;
 Il2CppGCHandles gcHandles;
 Il2CppRuntimeInformation runtimeInformation;
 void* additionalUserInformation;
} Il2CppManagedMemorySnapshot;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct FieldInfo FieldInfo;
typedef struct EventInfo EventInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppAsyncCall Il2CppAsyncCall;
typedef struct MonitorData MonitorData;
typedef struct FastMutex FastMutex;
typedef struct Thread Thread;
typedef struct Il2CppReflectionAssembly Il2CppReflectionAssembly;
typedef struct Il2CppObject
{
 Il2CppClass *klass;
 MonitorData *monitor;
} Il2CppObject;
typedef int32_t il2cpp_array_lower_bound_t;
typedef struct Il2CppArrayBounds
{
 il2cpp_array_size_t length;
 il2cpp_array_lower_bound_t lower_bound;
} Il2CppArrayBounds;
typedef struct Il2CppArray
{
 Il2CppObject obj;
 Il2CppArrayBounds *bounds;
 il2cpp_array_size_t max_length;
 double vector[32];
} Il2CppArray;
typedef struct Il2CppString
{
 Il2CppObject object;
 int32_t length;
 uint16_t chars[32];
} Il2CppString;
typedef struct Il2CppDataSegmentString
{
 Il2CppObject object;
} Il2CppDataSegmentString;
typedef struct Il2CppReflectionType
{
 Il2CppObject object;
 const Il2CppType *type;
} Il2CppReflectionType;
typedef struct Il2CppReflectionMonoType
{
 Il2CppReflectionType type;
 Il2CppObject *type_info;
} Il2CppReflectionMonoType;
typedef struct Il2CppReflectionEvent
{
 Il2CppObject object;
 Il2CppObject *cached_add_event;
} Il2CppReflectionEvent;
typedef struct Il2CppReflectionMonoEvent
{
 Il2CppReflectionEvent event;
 Il2CppReflectionType* reflectedType;
 const EventInfo* eventInfo;
} Il2CppReflectionMonoEvent;
typedef struct Il2CppReflectionMonoEventInfo
{
 Il2CppReflectionType* declaringType;
 Il2CppReflectionType* reflectedType;
 Il2CppString* name;
 Il2CppReflectionMethod* addMethod;
 Il2CppReflectionMethod* removeMethod;
 Il2CppReflectionMethod* raiseMethod;
 uint32_t eventAttributes;
 Il2CppArray* otherMethods;
} Il2CppReflectionMonoEventInfo;
typedef struct Il2CppEnumInfo
{
 Il2CppReflectionType *utype;
 Il2CppArray *values;
 Il2CppArray *names;
 void* name_hash;
} Il2CppEnumInfo;
typedef struct Il2CppReflectionField
{
 Il2CppObject object;
 Il2CppClass *klass;
 FieldInfo *field;
 Il2CppString *name;
 Il2CppReflectionType *type;
 uint32_t attrs;
} Il2CppReflectionField;
typedef struct Il2CppReflectionProperty
{
 Il2CppObject object;
 Il2CppClass *klass;
 const PropertyInfo *property;
} Il2CppReflectionProperty;
typedef struct Il2CppReflectionMethod
{
 Il2CppObject object;
 const MethodInfo *method;
 Il2CppString *name;
 Il2CppReflectionType *reftype;
} Il2CppReflectionMethod;
typedef struct Il2CppReflectionGenericMethod
{
 Il2CppReflectionMethod base;
} Il2CppReflectionGenericMethod;
typedef struct Il2CppMethodInfo
{
 Il2CppReflectionType *parent;
 Il2CppReflectionType *ret;
 uint32_t attrs;
 uint32_t implattrs;
 uint32_t callconv;
} Il2CppMethodInfo;
typedef struct Il2CppPropertyInfo
{
 Il2CppReflectionType *parent;
 Il2CppString *name;
 Il2CppReflectionMethod *get;
 Il2CppReflectionMethod *set;
 uint32_t attrs;
} Il2CppPropertyInfo;
typedef struct Il2CppReflectionParameter
{
 Il2CppObject object;
 Il2CppReflectionType *ClassImpl;
 Il2CppObject *DefaultValueImpl;
 Il2CppObject *MemberImpl;
 Il2CppString *NameImpl;
 int32_t PositionImpl;
 uint32_t AttrsImpl;
 Il2CppObject *MarshalAsImpl;
} Il2CppReflectionParameter;
typedef struct Il2CppReflectionModule
{
 Il2CppObject obj;
 const Il2CppImage* image;
 Il2CppReflectionAssembly* assembly;
 Il2CppString* fqname;
 Il2CppString* name;
 Il2CppString* scopename;
 bool is_resource;
 uint32_t token;
} Il2CppReflectionModule;
typedef struct Il2CppReflectionAssemblyName
{
 Il2CppObject obj;
 Il2CppString *name;
 Il2CppString *codebase;
 int32_t major, minor, build, revision;
 Il2CppObject *cultureInfo;
 uint32_t flags;
 uint32_t hashalg;
 Il2CppObject *keypair;
 Il2CppArray *publicKey;
 Il2CppArray *keyToken;
 uint32_t versioncompat;
 Il2CppObject *version;
 uint32_t processor_architecture;
} Il2CppReflectionAssemblyName;
typedef struct Il2CppReflectionAssembly
{
 Il2CppObject object;
 const Il2CppAssembly *assembly;
 Il2CppObject *resolve_event_holder;
 Il2CppObject *evidence;
 Il2CppObject *minimum;
 Il2CppObject *optional;
 Il2CppObject *refuse;
 Il2CppObject *granted;
 Il2CppObject *denied;
 bool from_byte_array;
 Il2CppString *name;
} Il2CppReflectionAssembly;
typedef struct Il2CppReflectionMarshal
{
 Il2CppObject object;
 int32_t count;
 int32_t type;
 int32_t eltype;
 Il2CppString* guid;
 Il2CppString* mcookie;
 Il2CppString* marshaltype;
 Il2CppObject* marshaltyperef;
 int32_t param_num;
 bool has_size;
} Il2CppReflectionMarshal;
typedef struct Il2CppReflectionPointer
{
 Il2CppObject object;
 void* data;
 Il2CppReflectionType* type;
} Il2CppReflectionPointer;
typedef struct Il2CppIntPtr
{
 void* m_value;
} Il2CppIntPtr;
typedef struct Il2CppThread
{
 Il2CppObject obj;
 int lock_thread_id;
 Thread* handle;
 Il2CppArray *cached_culture_info;
 void* unused1;
 bool threadpool_thread;
 uint16_t* name;
 uint32_t name_len;
 uint32_t state;
 Il2CppObject* abort_exc;
 int abort_state_handle;
 uint64_t tid;
 void* start_notify;
 void* stack_ptr;
 void* *static_data;
 void* jit_data;
 void* lock_data;
 Il2CppObject* current_appcontext;
 int stack_size;
 Il2CppObject* start_obj;
 void* appdomain_refs;
 int32_t interruption_requested;
 void* suspend_event;
 void* suspended_event;
 void* resume_event;
 FastMutex* synch_cs;
 uint8_t* serialized_culture_info;
 uint32_t serialized_culture_info_len;
 uint8_t* serialized_ui_culture_info;
 uint32_t serialized_ui_culture_info_len;
 bool thread_dump_requested;
 void* end_stack;
 bool thread_interrupt_requested;
 uint8_t apartment_state;
 int32_t critical_region_level;
 uint32_t small_id;
 void* manage_callback;
 Il2CppException *pending_exception;
 Il2CppObject *ec_to_set;
 void* interrupt_on_stop;
 void* unused3;
 void* unused4;
 void* unused5;
 void* unused6;
} Il2CppThread;
typedef struct Il2CppException
{
 Il2CppObject object;
 Il2CppArray *trace_ips;
 Il2CppObject *inner_ex;
 Il2CppString *message;
 Il2CppString *help_link;
 Il2CppString *class_name;
 Il2CppString *stack_trace;
 Il2CppString *remote_stack_trace;
 int32_t remote_stack_index;
 il2cpp_hresult_t hresult;
 Il2CppString *source;
 Il2CppObject *_data;
} Il2CppException;
typedef struct Il2CppSystemException
{
 Il2CppException base;
} Il2CppSystemException;
typedef struct Il2CppArgumentException
{
 Il2CppException base;
 Il2CppString *argName;
} Il2CppArgumentException;
typedef struct Il2CppTypedRef
{
 Il2CppType *type;
 void* value;
 Il2CppClass *klass;
} Il2CppTypedRef;
typedef struct Il2CppDelegate
{
 Il2CppObject object;
 methodPointerType method_ptr;
 void* (*invoke_impl)(const MethodInfo*, void*, void**);
 Il2CppObject *target;
 const MethodInfo *method;
 void* delegate_trampoline;
 uint8_t **method_code;
 Il2CppReflectionMethod *method_info;
 Il2CppReflectionMethod *original_method_info;
 Il2CppObject *data;
} Il2CppDelegate;
typedef struct Il2CppMarshalByRefObject
{
 Il2CppObject obj;
 Il2CppObject *identity;
} Il2CppMarshalByRefObject;
typedef struct Il2CppAppDomain
{
 Il2CppMarshalByRefObject mbr;
 Il2CppDomain *data;
} Il2CppAppDomain;
typedef struct Il2CppStackFrame
{
 Il2CppObject obj;
 int32_t il_offset;
 int32_t native_offset;
 Il2CppReflectionMethod *method;
 Il2CppString *filename;
 int32_t line;
 int32_t column;
 Il2CppString *internal_method_name;
} Il2CppStackFrame;
typedef struct Il2CppDateTimeFormatInfo
{
 Il2CppObject obj;
 bool readOnly;
 Il2CppString* AMDesignator;
 Il2CppString* PMDesignator;
 Il2CppString* DateSeparator;
 Il2CppString* TimeSeparator;
 Il2CppString* ShortDatePattern;
 Il2CppString* LongDatePattern;
 Il2CppString* ShortTimePattern;
 Il2CppString* LongTimePattern;
 Il2CppString* MonthDayPattern;
 Il2CppString* YearMonthPattern;
 Il2CppString* FullDateTimePattern;
 Il2CppString* RFC1123Pattern;
 Il2CppString* SortableDateTimePattern;
 Il2CppString* UniversalSortableDateTimePattern;
 uint32_t FirstDayOfWeek;
 Il2CppObject* Calendar;
 uint32_t CalendarWeekRule;
 Il2CppArray* AbbreviatedDayNames;
 Il2CppArray* DayNames;
 Il2CppArray* MonthNames;
 Il2CppArray* AbbreviatedMonthNames;
 Il2CppArray* ShortDatePatterns;
 Il2CppArray* LongDatePatterns;
 Il2CppArray* ShortTimePatterns;
 Il2CppArray* LongTimePatterns;
 Il2CppArray* MonthDayPatterns;
 Il2CppArray* YearMonthPatterns;
 Il2CppArray* shortDayNames;
} Il2CppDateTimeFormatInfo;
typedef struct Il2CppNumberFormatInfo
{
 Il2CppObject obj;
 bool readOnly;
 Il2CppString* decimalFormats;
 Il2CppString* currencyFormats;
 Il2CppString* percentFormats;
 Il2CppString* digitPattern;
 Il2CppString* zeroPattern;
 int32_t currencyDecimalDigits;
 Il2CppString* currencyDecimalSeparator;
 Il2CppString* currencyGroupSeparator;
 Il2CppArray* currencyGroupSizes;
 int32_t currencyNegativePattern;
 int32_t currencyPositivePattern;
 Il2CppString* currencySymbol;
 Il2CppString* naNSymbol;
 Il2CppString* negativeInfinitySymbol;
 Il2CppString* negativeSign;
 uint32_t numberDecimalDigits;
 Il2CppString* numberDecimalSeparator;
 Il2CppString* numberGroupSeparator;
 Il2CppArray* numberGroupSizes;
 int32_t numberNegativePattern;
 int32_t percentDecimalDigits;
 Il2CppString* percentDecimalSeparator;
 Il2CppString* percentGroupSeparator;
 Il2CppArray* percentGroupSizes;
 int32_t percentNegativePattern;
 int32_t percentPositivePattern;
 Il2CppString* percentSymbol;
 Il2CppString* perMilleSymbol;
 Il2CppString* positiveInfinitySymbol;
 Il2CppString* positiveSign;
} Il2CppNumberFormatInfo;
typedef struct Il2CppCultureInfo
{
 Il2CppObject obj;
 bool is_read_only;
 int32_t lcid;
 int32_t parent_lcid;
 int32_t specific_lcid;
 int32_t datetime_index;
 int32_t number_index;
 bool use_user_override;
 Il2CppNumberFormatInfo* number_format;
 Il2CppDateTimeFormatInfo* datetime_format;
 Il2CppObject* textinfo;
 Il2CppString* name;
 Il2CppString* displayname;
 Il2CppString* englishname;
 Il2CppString* nativename;
 Il2CppString* iso3lang;
 Il2CppString* iso2lang;
 Il2CppString* icu_name;
 Il2CppString* win3lang;
 Il2CppString* territory;
 Il2CppString* compareinfo;
 const int32_t* calendar_data;
 const void* text_info_data;
} Il2CppCultureInfo;
typedef struct Il2CppWaitHandle
{
 Il2CppMarshalByRefObject object;
 void* handle;
 bool disposed;
} Il2CppWaitHandle;
typedef struct Il2CppSafeHandle
{
 Il2CppObject base;
 void* handle;
 void* invalid_handle_value;
 int refcount;
 bool owns_handle;
} Il2CppSafeHandle;
typedef struct Il2CppStringBuilder
{
 Il2CppObject object;
 int32_t length;
 Il2CppString *str;
 Il2CppString *cached_str;
 int32_t max_capacity;
} Il2CppStringBuilder;
typedef struct Il2CppSocketAddress
{
 Il2CppObject base;
 Il2CppArray* data;
} Il2CppSocketAddress;
typedef struct Il2CppSortKey
{
 Il2CppObject base;
 Il2CppString *str;
 int32_t options;
 Il2CppArray *key;
 int32_t lcid;
} Il2CppSortKey;
typedef struct Il2CppAsyncResult
{
 Il2CppObject base;
 Il2CppObject *async_state;
 Il2CppWaitHandle *handle;
 Il2CppDelegate *async_delegate;
 void* data;
 Il2CppAsyncCall *object_data;
 bool sync_completed;
 bool completed;
 bool endinvoke_called;
 Il2CppObject *async_callback;
 Il2CppObject *execution_context;
 Il2CppObject *original_context;
} Il2CppAsyncResult;
typedef struct Il2CppAsyncCall
{
 Il2CppObject base;
 void *msg;
 MethodInfo *cb_method;
 Il2CppDelegate *cb_target;
 Il2CppObject *state;
 Il2CppObject *res;
 Il2CppArray *out_args;
 uint64_t wait_event;
} Il2CppAsyncCall;
typedef struct Il2CppExceptionWrapper
{
 Il2CppException* ex;
} Il2CppExceptionWrapper;
typedef struct Il2CppSocketAsyncResult
{
 Il2CppObject base;
 Il2CppObject *socket;
 Il2CppIntPtr handle;
 Il2CppObject *state;
 Il2CppDelegate *callback;
 Il2CppWaitHandle *wait_handle;
 Il2CppException *delayed_exc;
 Il2CppObject *ep;
 Il2CppArray *buffer;
 int32_t offset;
 int32_t size;
 int32_t socket_flags;
 Il2CppObject *accept_reuse_socket;
 Il2CppArray *addresses;
 int32_t port;
 Il2CppObject *buffers;
 bool reusesocket;
 Il2CppObject *acc_socket;
 int32_t total;
 bool completed_synch;
 bool completed;
 bool blocking;
 int32_t error;
 int32_t operation;
 Il2CppAsyncResult *ares;
} Il2CppSocketAsyncResult;
typedef enum Il2CppResourceLocation
{
 RESOURCE_LOCATION_EMBEDDED = 1,
 RESOURCE_LOCATION_ANOTHER_ASSEMBLY = 2,
 RESOURCE_LOCATION_IN_MANIFEST = 4
} Il2CppResourceLocation;
typedef struct Il2CppManifestResourceInfo
{
 Il2CppObject object;
 Il2CppReflectionAssembly* assembly;
 Il2CppString* filename;
 uint32_t location;
} Il2CppManifestResourceInfo;
typedef struct Il2CppAppContext
{
 Il2CppObject obj;
 int32_t domain_id;
 int32_t context_id;
 void* static_data;
} Il2CppAppContext;
typedef struct Il2CppGuid
{
 uint32_t data1;
 uint16_t data2;
 uint16_t data3;
 uint8_t data4[8];
} Il2CppGuid;
typedef struct Il2CppIUnknown
{
} Il2CppIUnknown;
