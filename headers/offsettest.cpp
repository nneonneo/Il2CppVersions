/* compiler flags will include the right structure for us */
#include <stddef.h>

static_assert(offsetof(Il2CppClass, vtable) == offsetof(Il2CppClass_Merged, vtable), "Mismatched vtable offset");
static_assert(offsetof(Il2CppClass, cctor_thread) == offsetof(Il2CppClass_Merged, _1.cctor_thread), "Mismatched cctor_thread offset");
static_assert(offsetof(Il2CppClass, static_fields) == offsetof(Il2CppClass_Merged, static_fields), "Mismatched static_fields offset");
static_assert(offsetof(Il2CppClass, flags) == offsetof(Il2CppClass_Merged, _1.flags), "Mismatched flags offset");
static_assert(offsetof(Il2CppClass, fields) == offsetof(Il2CppClass_Merged, _0.fields), "Mismatched fields offset");
static_assert(sizeof(Il2CppClass) == sizeof(Il2CppClass_Merged), "Mismatched size");
