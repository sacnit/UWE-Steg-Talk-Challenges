typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef unsigned long long    qword;
typedef unsigned int    undefined4;
typedef unsigned short    word;
typedef unsigned short    wchar16;
typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory;
    dword DataIsDirectory;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct Var Var, *PVar;

struct Var {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset;
    dword NameIsString;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 332
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct StringFileInfo StringFileInfo, *PStringFileInfo;

struct StringFileInfo {
    word wLength;
    word wValueLength;
    word wType;
};

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct StringTable StringTable, *PStringTable;

struct StringTable {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct VS_VERSION_INFO VS_VERSION_INFO, *PVS_VERSION_INFO;

struct VS_VERSION_INFO {
    word StructLength;
    word ValueLength;
    word StructType;
    wchar16 Info[16];
    byte Padding[2];
    dword Signature;
    word StructVersion[2];
    word FileVersion[4];
    word ProductVersion[4];
    dword FileFlagsMask[2];
    dword FileFlags;
    dword FileOS;
    dword FileType;
    dword FileSubtype;
    dword FileTimestamp;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_COR20_HEADER IMAGE_COR20_HEADER, *PIMAGE_COR20_HEADER;

typedef struct CLI_METADATA_DIRECTORY CLI_METADATA_DIRECTORY, *PCLI_METADATA_DIRECTORY;

typedef enum COR20_Flags {
    COMIMAGE_FLAGS_ILONLY=1,
    COMIMAGE_FLAGS_32BITREQUIRED=2,
    COMIMAGE_FLAGS_IL_LIBRARY=4,
    COMIMAGE_FLAGS_STRONGNAMESIGNED=8,
    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT=16,
    COMIMAGE_FLAGS_TRACKDEBUGDATA=65536
} COR20_Flags;

typedef struct IMAGE_DATA_DIRECTORY.conflict IMAGE_DATA_DIRECTORY.conflict, *PIMAGE_DATA_DIRECTORY.conflict;

struct CLI_METADATA_DIRECTORY {
    dword VirtualAddress;
    dword Size;
};

struct IMAGE_DATA_DIRECTORY.conflict {
    dword VirtualAddress;
    dword Size;
};

struct IMAGE_COR20_HEADER {
    dword cb; // Size of the structure
    word MajorRuntimeVersion; // Version of CLR Runtime
    word MinorRuntimeVersion;
    struct CLI_METADATA_DIRECTORY MetaData; // RVA and size of MetaData
    enum COR20_Flags Flags;
    dword EntryPointToken; // This is a metadata token if not a valid RVA
    struct IMAGE_DATA_DIRECTORY.conflict Resources;
    struct IMAGE_DATA_DIRECTORY.conflict StrongNameSignature;
    struct IMAGE_DATA_DIRECTORY.conflict CodeManagerTable; // Should be 0
    struct IMAGE_DATA_DIRECTORY.conflict VTableFixups;
    struct IMAGE_DATA_DIRECTORY.conflict ExportAddressTableJumps; // Should be 0
    struct IMAGE_DATA_DIRECTORY.conflict ManagedNativeHeader; // 0 unless this is a native image
};

typedef struct VarFileInfo VarFileInfo, *PVarFileInfo;

struct VarFileInfo {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct StringInfo StringInfo, *PStringInfo;

struct StringInfo {
    word wLength;
    word wValueLength;
    word wType;
};

typedef struct CLI_METADATA_HEADER CLI_METADATA_HEADER, *PCLI_METADATA_HEADER;

typedef struct CLI_Stream_Header_#~ CLI_Stream_Header_#~, *PCLI_Stream_Header_#~;

typedef struct CLI_Stream_Header_#Strings CLI_Stream_Header_#Strings, *PCLI_Stream_Header_#Strings;

typedef struct CLI_Stream_Header_#US CLI_Stream_Header_#US, *PCLI_Stream_Header_#US;

typedef struct CLI_Stream_Header_#GUID CLI_Stream_Header_#GUID, *PCLI_Stream_Header_#GUID;

typedef struct CLI_Stream_Header_#Blob CLI_Stream_Header_#Blob, *PCLI_Stream_Header_#Blob;

struct CLI_Stream_Header_#Blob {
    dword offset;
    dword size;
    char name[8];
};

struct CLI_Stream_Header_#GUID {
    dword offset;
    dword size;
    char name[8];
};

struct CLI_Stream_Header_#~ {
    dword offset;
    dword size;
    char name[4];
};

struct CLI_Stream_Header_#US {
    dword offset;
    dword size;
    char name[4];
};

struct CLI_Stream_Header_#Strings {
    dword offset;
    dword size;
    char name[12];
};

struct CLI_METADATA_HEADER {
    dword Signature; // must be 0x424a5342
    word MajorVersion;
    word MinorVersion;
    dword Reserved; // should be 0
    dword VersionLength;
    char Version[12];
    word Flags; // should be 0
    word StreamsCount; // number of stream headers to follow
    struct CLI_Stream_Header_#~ #~;
    struct CLI_Stream_Header_#Strings #Strings;
    struct CLI_Stream_Header_#US #US;
    struct CLI_Stream_Header_#GUID #GUID;
    struct CLI_Stream_Header_#Blob #Blob;
};

typedef struct GenericInstType_3572 GenericInstType_3572, *PGenericInstType_3572;

typedef enum TypeCode {
    ELEMENT_TYPE_END=0,
    ELEMENT_TYPE_VOID=1,
    ELEMENT_TYPE_BOOLEAN=2,
    ELEMENT_TYPE_CHAR=3,
    ELEMENT_TYPE_I1=4,
    ELEMENT_TYPE_U1=5,
    ELEMENT_TYPE_I2=6,
    ELEMENT_TYPE_U2=7,
    ELEMENT_TYPE_I4=8,
    ELEMENT_TYPE_U4=9,
    ELEMENT_TYPE_I8=10,
    ELEMENT_TYPE_U8=11,
    ELEMENT_TYPE_R4=12,
    ELEMENT_TYPE_R8=13,
    ELEMENT_TYPE_STRING=14,
    ELEMENT_TYPE_PTR=15,
    ELEMENT_TYPE_BYREF=16,
    ELEMENT_TYPE_VALUETYPE=17,
    ELEMENT_TYPE_CLASS=18,
    ELEMENT_TYPE_VAR=19,
    ELEMENT_TYPE_ARRAY=20,
    ELEMENT_TYPE_GENERICINST=21,
    ELEMENT_TYPE_TYPEDBYREF=22,
    ELEMENT_TYPE_I=24,
    ELEMENT_TYPE_U=25,
    ELEMENT_TYPE_FNPTR=27,
    ELEMENT_TYPE_OBJECT=28,
    ELEMENT_TYPE_SZARRAY=29,
    ELEMENT_TYPE_MVAR=30,
    ELEMENT_TYPE_CMOD_REQD=31,
    ELEMENT_TYPE_CMOD_OPT=32,
    ELEMENT_TYPE_INTERNAL=33,
    ELEMENT_TYPE_MAX=34,
    ELEMENT_TYPE_MODIFIER=64,
    ELEMENT_TYPE_SENTINEL=65,
    ELEMENT_TYPE_PINNED=69
} TypeCode;

typedef struct ELEMENT_TYPE_MVAR_3576 ELEMENT_TYPE_MVAR_3576, *PELEMENT_TYPE_MVAR_3576;

struct ELEMENT_TYPE_MVAR_3576 {
    enum TypeCode ELEMENT_TYPE_MVAR;
    byte number;
};

struct GenericInstType_3572 {
    enum TypeCode GenericInst; // GenericInst
    enum TypeCode ClassOrValueType; // Class or ValueType
    byte Type; // TypeDefOrRefOrSpecEncoded
    byte GenArgCount; // Number of generics to follow
    struct ELEMENT_TYPE_MVAR_3576 Type; // Generic Type
};

typedef struct SzArray_3595 SzArray_3595, *PSzArray_3595;

struct SzArray_3595 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct GenericInstType_3555 GenericInstType_3555, *PGenericInstType_3555;

typedef struct ELEMENT_TYPE_MVAR_3559 ELEMENT_TYPE_MVAR_3559, *PELEMENT_TYPE_MVAR_3559;

struct ELEMENT_TYPE_MVAR_3559 {
    enum TypeCode ELEMENT_TYPE_MVAR;
    byte number;
};

struct GenericInstType_3555 {
    enum TypeCode GenericInst; // GenericInst
    enum TypeCode ClassOrValueType; // Class or ValueType
    byte Type; // TypeDefOrRefOrSpecEncoded
    byte GenArgCount; // Number of generics to follow
    struct ELEMENT_TYPE_MVAR_3559 Type; // Generic Type
};

typedef struct ValueType.conflict ValueType.conflict, *PValueType.conflict;

struct ValueType.conflict {
    enum TypeCode ValueType; // ValueType
    byte TypeDefOrRefEncoded; // TypeRef: Row 0x4
};

typedef struct SzArray_3613 SzArray_3613, *PSzArray_3613;

struct SzArray_3613 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct ELEMENT_TYPE_MVAR_3553 ELEMENT_TYPE_MVAR_3553, *PELEMENT_TYPE_MVAR_3553;

struct ELEMENT_TYPE_MVAR_3553 {
    enum TypeCode ELEMENT_TYPE_MVAR;
    byte number;
};

typedef struct SzArray_3619 SzArray_3619, *PSzArray_3619;

struct SzArray_3619 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct ValueType ValueType, *PValueType;

struct ValueType {
    enum TypeCode ValueType; // ValueType
    byte TypeDefOrRefEncoded; // TypeDef: Row 0x7
};

typedef struct ELEMENT_TYPE_MVAR_3570 ELEMENT_TYPE_MVAR_3570, *PELEMENT_TYPE_MVAR_3570;

struct ELEMENT_TYPE_MVAR_3570 {
    enum TypeCode ELEMENT_TYPE_MVAR;
    byte number;
};

typedef struct ValueType.conflict1 ValueType.conflict1, *PValueType.conflict1;

struct ValueType.conflict1 {
    enum TypeCode ValueType; // ValueType
    byte TypeDefOrRefEncoded; // TypeRef: Row 0xe
};

typedef struct ValueType.conflict2 ValueType.conflict2, *PValueType.conflict2;

struct ValueType.conflict2 {
    enum TypeCode ValueType; // ValueType
    byte TypeDefOrRefEncoded; // TypeRef: Row 0x17
};

typedef struct SzArray_3543 SzArray_3543, *PSzArray_3543;

struct SzArray_3543 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct GenericInstType_3549 GenericInstType_3549, *PGenericInstType_3549;

struct GenericInstType_3549 {
    enum TypeCode GenericInst; // GenericInst
    enum TypeCode ClassOrValueType; // Class or ValueType
    byte Type; // TypeDefOrRefOrSpecEncoded
    byte GenArgCount; // Number of generics to follow
    struct ELEMENT_TYPE_MVAR_3553 Type; // Generic Type
};

typedef struct SzArray_3582 SzArray_3582, *PSzArray_3582;

struct SzArray_3582 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct SzArray_3527 SzArray_3527, *PSzArray_3527;

struct SzArray_3527 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct SzArray_3523 SzArray_3523, *PSzArray_3523;

struct SzArray_3523 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct SzArray_3569 SzArray_3569, *PSzArray_3569;

struct SzArray_3569 {
    enum TypeCode TypeCode; // SzArray
    struct ELEMENT_TYPE_MVAR_3570 Type; // type or void
};

typedef struct SzArray_3525 SzArray_3525, *PSzArray_3525;

struct SzArray_3525 {
    enum TypeCode TypeCode; // SzArray
    enum TypeCode Type; // type or void
};

typedef struct Class Class, *PClass;

struct Class {
    enum TypeCode Class; // Class
    byte Type; // TypeDefOrRefOrSpecEncoded
};

typedef struct CustomAttrib_137 CustomAttrib_137, *PCustomAttrib_137;

struct CustomAttrib_137 {
    word PROLOG; // Magic (0x0001)
    word NumNamed; // Number of NamedArgs to follow
    byte FieldOrProp; // PROPERTY
    byte FieldOrPropType; // ELEMENT_TYPE_BOOLEAN
    byte PackedLen;
    char FieldOrPropName[23];
};

typedef struct Blob_Generic_85 Blob_Generic_85, *PBlob_Generic_85;

struct Blob_Generic_85 {
    byte Size; // coded integer - blob size
    byte Generic[5]; // Undefined blob contents
};

typedef struct Blob_MethodRefSig_72 Blob_MethodRefSig_72, *PBlob_MethodRefSig_72;

typedef struct MethodRefSig_72 MethodRefSig_72, *PMethodRefSig_72;

typedef struct Type_3568 Type_3568, *PType_3568;

typedef struct Type_3571 Type_3571, *PType_3571;

struct Type_3571 {
    struct GenericInstType_3572 ELEMENT_TYPE_GENERICINST;
};

struct Type_3568 {
    struct SzArray_3569 ELEMENT_TYPE_SZARRAY;
};

struct MethodRefSig_72 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte GenParamCount; // Number of generic paramameters for the method
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3568 RetType;
    struct Type_3571 Param0;
};

struct Blob_MethodRefSig_72 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_72 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_Generic_269 Blob_Generic_269, *PBlob_Generic_269;

struct Blob_Generic_269 {
    byte Size; // coded integer - blob size
    byte Generic[12]; // Undefined blob contents
};

typedef struct Blob_Generic_304 Blob_Generic_304, *PBlob_Generic_304;

struct Blob_Generic_304 {
    byte Size; // coded integer - blob size
    byte Generic[38]; // Undefined blob contents
};

typedef struct Blob_MethodDefSig_6 Blob_MethodDefSig_6, *PBlob_MethodDefSig_6;

typedef struct MethodDefSig_6 MethodDefSig_6, *PMethodDefSig_6;

typedef struct Type_3501 Type_3501, *PType_3501;

struct Type_3501 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct MethodDefSig_6 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte Count; // Number of parameter types to follow RetType
    struct Type_3501 RetType;
};

struct Blob_MethodDefSig_6 {
    byte Size; // coded integer - blob size
    struct MethodDefSig_6 MethodDefSig; // Type info for method return and params
};

typedef struct CustomAttrib_256 CustomAttrib_256, *PCustomAttrib_256;

struct CustomAttrib_256 {
    word PROLOG; // Magic (0x0001)
    byte PackedLen;
    char FixedArg_0[7];
    word NumNamed; // Number of NamedArgs to follow
};

typedef struct CustomAttrib_269 CustomAttrib_269, *PCustomAttrib_269;

struct CustomAttrib_269 {
    word PROLOG; // Magic (0x0001)
    byte PackedLen;
    char FixedArg_0[7];
    word NumNamed; // Number of NamedArgs to follow
};

typedef struct Blob_CustomAttrib_282 Blob_CustomAttrib_282, *PBlob_CustomAttrib_282;

typedef struct CustomAttrib_282 CustomAttrib_282, *PCustomAttrib_282;

struct CustomAttrib_282 {
    word PROLOG; // Magic (0x0001)
    byte PackedLen;
    char FixedArg_0[5];
    word NumNamed; // Number of NamedArgs to follow
};

struct Blob_CustomAttrib_282 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_282 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct CustomAttrib_304 CustomAttrib_304, *PCustomAttrib_304;

struct CustomAttrib_304 {
    word PROLOG; // Magic (0x0001)
    dword FixedArg_0; // Elem (ELEMENT_TYPE_VALUETYPE)
    word NumNamed; // Number of NamedArgs to follow
    byte FieldOrProp; // PROPERTY
    byte FieldOrPropType; // ELEMENT_TYPE_BOOLEAN
    byte PackedLen;
    char FieldOrPropName[14];
    byte FieldOrProp; // PROPERTY
    byte FieldOrPropType; // ELEMENT_TYPE_BOOLEAN
    byte PackedLen;
    char FieldOrPropName[10];
};

typedef struct Blob_Generic_91 Blob_Generic_91, *PBlob_Generic_91;

struct Blob_Generic_91 {
    byte Size; // coded integer - blob size
    byte Generic[8]; // Undefined blob contents
};

typedef struct Blob_Generic_137 Blob_Generic_137, *PBlob_Generic_137;

struct Blob_Generic_137 {
    byte Size; // coded integer - blob size
    byte Generic[30]; // Undefined blob contents
};

typedef struct Blob_Generic_16 Blob_Generic_16, *PBlob_Generic_16;

struct Blob_Generic_16 {
    byte Size; // coded integer - blob size
    byte Generic[4]; // Undefined blob contents
};

typedef struct Blob_Generic_256 Blob_Generic_256, *PBlob_Generic_256;

struct Blob_Generic_256 {
    byte Size; // coded integer - blob size
    byte Generic[12]; // Undefined blob contents
};

typedef struct Blob_Generic_10 Blob_Generic_10, *PBlob_Generic_10;

struct Blob_Generic_10 {
    byte Size; // coded integer - blob size
    byte Generic[5]; // Undefined blob contents
};

typedef struct Blob_CustomAttrib_168 Blob_CustomAttrib_168, *PBlob_CustomAttrib_168;

typedef struct CustomAttrib_168 CustomAttrib_168, *PCustomAttrib_168;

struct CustomAttrib_168 {
    word PROLOG; // Magic (0x0001)
    dword FixedArg_0; // Elem (ELEMENT_TYPE_VALUETYPE)
    word NumNamed; // Number of NamedArgs to follow
};

struct Blob_CustomAttrib_168 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_168 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct Blob_Generic_122 Blob_Generic_122, *PBlob_Generic_122;

struct Blob_Generic_122 {
    byte Size; // coded integer - blob size
    byte Generic[5]; // Undefined blob contents
};

typedef struct Blob_FieldSig_107 Blob_FieldSig_107, *PBlob_FieldSig_107;

typedef struct FieldSig_107 FieldSig_107, *PFieldSig_107;

typedef struct Type_3601 Type_3601, *PType_3601;

struct Type_3601 {
    struct ValueType ELEMENT_TYPE_VALUETYPE;
};

struct FieldSig_107 {
    byte FIELD; // Magic (0x06)
    struct Type_3601 ELEMENT_TYPE_VALUETYPE;
};

struct Blob_FieldSig_107 {
    byte Size; // coded integer - blob size
    struct FieldSig_107 FieldSig; // Type information for Field
};

typedef struct Blob_MethodRefSig_52 Blob_MethodRefSig_52, *PBlob_MethodRefSig_52;

typedef struct MethodRefSig_52 MethodRefSig_52, *PMethodRefSig_52;

typedef struct Type_3548 Type_3548, *PType_3548;

typedef struct Type_3554 Type_3554, *PType_3554;

struct Type_3548 {
    struct GenericInstType_3549 ELEMENT_TYPE_GENERICINST;
};

struct Type_3554 {
    struct GenericInstType_3555 ELEMENT_TYPE_GENERICINST;
};

struct MethodRefSig_52 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte GenParamCount; // Number of generic paramameters for the method
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3548 RetType;
    struct Type_3554 Param0;
};

struct Blob_MethodRefSig_52 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_52 MethodRefSig; // Type info for imported method return and params
};

typedef struct CustomAttrib_239 CustomAttrib_239, *PCustomAttrib_239;

struct CustomAttrib_239 {
    word PROLOG; // Magic (0x0001)
    byte PackedLen;
    char FixedArg_0[11];
    word NumNamed; // Number of NamedArgs to follow
};

typedef struct Blob_Generic_68 Blob_Generic_68, *PBlob_Generic_68;

struct Blob_Generic_68 {
    byte Size; // coded integer - blob size
    byte Generic[3]; // Undefined blob contents
};

typedef struct Blob_Generic_128 Blob_Generic_128, *PBlob_Generic_128;

struct Blob_Generic_128 {
    byte Size; // coded integer - blob size
    byte Generic[8]; // Undefined blob contents
};

typedef struct Blob_FieldSig_104 Blob_FieldSig_104, *PBlob_FieldSig_104;

typedef struct FieldSig_104 FieldSig_104, *PFieldSig_104;

typedef struct Type_3598 Type_3598, *PType_3598;

struct Type_3598 {
    enum TypeCode ELEMENT_TYPE_U1;
};

struct FieldSig_104 {
    byte FIELD; // Magic (0x06)
    struct Type_3598 ELEMENT_TYPE_U1;
};

struct Blob_FieldSig_104 {
    byte Size; // coded integer - blob size
    struct FieldSig_104 FieldSig; // Type information for Field
};

typedef struct Blob_CustomAttrib_256 Blob_CustomAttrib_256, *PBlob_CustomAttrib_256;

struct Blob_CustomAttrib_256 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_256 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct Blob_CustomAttrib_137 Blob_CustomAttrib_137, *PBlob_CustomAttrib_137;

struct Blob_CustomAttrib_137 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_137 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct Blob_FieldSig_100 Blob_FieldSig_100, *PBlob_FieldSig_100;

typedef struct FieldSig_100 FieldSig_100, *PFieldSig_100;

typedef struct Type_3594 Type_3594, *PType_3594;

struct Type_3594 {
    struct SzArray_3595 ELEMENT_TYPE_SZARRAY;
};

struct FieldSig_100 {
    byte FIELD; // Magic (0x06)
    struct Type_3594 ELEMENT_TYPE_SZARRAY;
};

struct Blob_FieldSig_100 {
    byte Size; // coded integer - blob size
    struct FieldSig_100 FieldSig; // Type information for Field
};

typedef struct Blob_Generic_72 Blob_Generic_72, *PBlob_Generic_72;

struct Blob_Generic_72 {
    byte Size; // coded integer - blob size
    byte Generic[12]; // Undefined blob contents
};

typedef struct Blob_MethodRefSig_45 Blob_MethodRefSig_45, *PBlob_MethodRefSig_45;

typedef struct MethodRefSig_45 MethodRefSig_45, *PMethodRefSig_45;

typedef struct Type_3540 Type_3540, *PType_3540;

typedef struct Type_3541 Type_3541, *PType_3541;

typedef struct Type_3542 Type_3542, *PType_3542;

struct Type_3540 {
    enum TypeCode ELEMENT_TYPE_STRING;
};

struct Type_3541 {
    enum TypeCode ELEMENT_TYPE_STRING;
};

struct Type_3542 {
    struct SzArray_3543 ELEMENT_TYPE_SZARRAY;
};

struct MethodRefSig_45 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3540 RetType;
    struct Type_3541 Param0;
    struct Type_3542 Param1;
};

struct Blob_MethodRefSig_45 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_45 MethodRefSig; // Type info for imported method return and params
};

typedef struct CustomAttrib_128 CustomAttrib_128, *PCustomAttrib_128;

struct CustomAttrib_128 {
    word PROLOG; // Magic (0x0001)
    dword FixedArg_0; // Elem (ELEMENT_TYPE_I4)
    word NumNamed; // Number of NamedArgs to follow
};

typedef struct Blob_Generic_111 Blob_Generic_111, *PBlob_Generic_111;

struct Blob_Generic_111 {
    byte Size; // coded integer - blob size
    byte Generic[4]; // Undefined blob contents
};

typedef struct Blob_Generic_239 Blob_Generic_239, *PBlob_Generic_239;

struct Blob_Generic_239 {
    byte Size; // coded integer - blob size
    byte Generic[16]; // Undefined blob contents
};

typedef struct Blob_Generic_116 Blob_Generic_116, *PBlob_Generic_116;

struct Blob_Generic_116 {
    byte Size; // coded integer - blob size
    byte Generic[5]; // Undefined blob contents
};

typedef struct Blob_Generic_6 Blob_Generic_6, *PBlob_Generic_6;

struct Blob_Generic_6 {
    byte Size; // coded integer - blob size
    byte Generic[3]; // Undefined blob contents
};

typedef struct Blob_CustomAttrib_269 Blob_CustomAttrib_269, *PBlob_CustomAttrib_269;

struct Blob_CustomAttrib_269 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_269 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct Blob_MethodRefSig_37 Blob_MethodRefSig_37, *PBlob_MethodRefSig_37;

typedef struct MethodRefSig_37 MethodRefSig_37, *PMethodRefSig_37;

typedef struct Type_3532 Type_3532, *PType_3532;

typedef struct Type_3533 Type_3533, *PType_3533;

typedef struct Type_3535 Type_3535, *PType_3535;

struct Type_3535 {
    struct ValueType.conflict2 ELEMENT_TYPE_VALUETYPE;
};

struct Type_3532 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct Type_3533 {
    struct Class ELEMENT_TYPE_CLASS;
};

struct MethodRefSig_37 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3532 RetType;
    struct Type_3533 Param0;
    struct Type_3535 Param1;
};

struct Blob_MethodRefSig_37 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_37 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_CustomAttrib_304 Blob_CustomAttrib_304, *PBlob_CustomAttrib_304;

struct Blob_CustomAttrib_304 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_304 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct Blob_Generic_1 Blob_Generic_1, *PBlob_Generic_1;

struct Blob_Generic_1 {
    byte Size; // coded integer - blob size
    byte Generic[4]; // Undefined blob contents
};

typedef struct Blob_Generic_100 Blob_Generic_100, *PBlob_Generic_100;

struct Blob_Generic_100 {
    byte Size; // coded integer - blob size
    byte Generic[3]; // Undefined blob contents
};

typedef struct Blob_Generic_104 Blob_Generic_104, *PBlob_Generic_104;

struct Blob_Generic_104 {
    byte Size; // coded integer - blob size
    byte Generic[2]; // Undefined blob contents
};

typedef struct Blob_Generic_343 Blob_Generic_343, *PBlob_Generic_343;

struct Blob_Generic_343 {
    byte Size; // coded integer - blob size
    byte Generic[38]; // Undefined blob contents
};

typedef struct Blob_Generic_107 Blob_Generic_107, *PBlob_Generic_107;

struct Blob_Generic_107 {
    byte Size; // coded integer - blob size
    byte Generic[3]; // Undefined blob contents
};

typedef struct Blob_Generic_45 Blob_Generic_45, *PBlob_Generic_45;

struct Blob_Generic_45 {
    byte Size; // coded integer - blob size
    byte Generic[6]; // Undefined blob contents
};

typedef struct Blob_MethodSpecSig_68 Blob_MethodSpecSig_68, *PBlob_MethodSpecSig_68;

typedef struct MethodSpecSig_68 MethodSpecSig_68, *PMethodSpecSig_68;

struct MethodSpecSig_68 {
    byte GENRICINST; // Magic (0x0a)
    byte GenArgCount; // Number of types to follow
    enum TypeCode Type0;
};

struct Blob_MethodSpecSig_68 {
    byte Size; // coded integer - blob size
    struct MethodSpecSig_68 MethodSpecSig; // Specifies a generic method with GenArgCount types
};

typedef struct CustomAttrib_293 CustomAttrib_293, *PCustomAttrib_293;

struct CustomAttrib_293 {
    word PROLOG; // Magic (0x0001)
    byte FixedArg_0; // Elem (ELEMENT_TYPE_U1)
    word NumNamed; // Number of NamedArgs to follow
};

typedef struct Blob_CustomAttrib_239 Blob_CustomAttrib_239, *PBlob_CustomAttrib_239;

struct Blob_CustomAttrib_239 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_239 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct CustomAttrib_299 CustomAttrib_299, *PCustomAttrib_299;

struct CustomAttrib_299 {
    word PROLOG; // Magic (0x0001)
    word NumNamed; // Number of NamedArgs to follow
};

typedef struct Blob_Generic_293 Blob_Generic_293, *PBlob_Generic_293;

struct Blob_Generic_293 {
    byte Size; // coded integer - blob size
    byte Generic[5]; // Undefined blob contents
};

typedef struct Blob_Generic_52 Blob_Generic_52, *PBlob_Generic_52;

struct Blob_Generic_52 {
    byte Size; // coded integer - blob size
    byte Generic[15]; // Undefined blob contents
};

typedef struct Blob_MethodRefSig_21 Blob_MethodRefSig_21, *PBlob_MethodRefSig_21;

typedef struct MethodRefSig_21 MethodRefSig_21, *PMethodRefSig_21;

typedef struct Type_3516 Type_3516, *PType_3516;

typedef struct Type_3517 Type_3517, *PType_3517;

struct Type_3516 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct Type_3517 {
    struct ValueType.conflict1 ELEMENT_TYPE_VALUETYPE;
};

struct MethodRefSig_21 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3516 RetType;
    struct Type_3517 Param0;
};

struct Blob_MethodRefSig_21 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_21 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_Generic_177 Blob_Generic_177, *PBlob_Generic_177;

struct Blob_Generic_177 {
    byte Size; // coded integer - blob size
    byte Generic[61]; // Undefined blob contents
};

typedef struct Blob_Generic_299 Blob_Generic_299, *PBlob_Generic_299;

struct Blob_Generic_299 {
    byte Size; // coded integer - blob size
    byte Generic[4]; // Undefined blob contents
};

typedef struct Blob_MethodRefSig_16 Blob_MethodRefSig_16, *PBlob_MethodRefSig_16;

typedef struct MethodRefSig_16 MethodRefSig_16, *PMethodRefSig_16;

typedef struct Type_3511 Type_3511, *PType_3511;

typedef struct Type_3512 Type_3512, *PType_3512;

struct Type_3512 {
    enum TypeCode ELEMENT_TYPE_STRING;
};

struct Type_3511 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct MethodRefSig_16 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3511 RetType;
    struct Type_3512 Param0;
};

struct Blob_MethodRefSig_16 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_16 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_CustomAttrib_128 Blob_CustomAttrib_128, *PBlob_CustomAttrib_128;

struct Blob_CustomAttrib_128 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_128 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct CustomAttrib_343 CustomAttrib_343, *PCustomAttrib_343;

struct CustomAttrib_343 {
    word PROLOG; // Magic (0x0001)
    dword FixedArg_0; // Elem (ELEMENT_TYPE_VALUETYPE)
    word NumNamed; // Number of NamedArgs to follow
    byte FieldOrProp; // PROPERTY
    byte FieldOrPropType; // ELEMENT_TYPE_BOOLEAN
    byte PackedLen;
    char FieldOrPropName[14];
    byte FieldOrProp; // PROPERTY
    byte FieldOrPropType; // ELEMENT_TYPE_BOOLEAN
    byte PackedLen;
    char FieldOrPropName[10];
};

typedef struct Blob_Generic_282 Blob_Generic_282, *PBlob_Generic_282;

struct Blob_Generic_282 {
    byte Size; // coded integer - blob size
    byte Generic[10]; // Undefined blob contents
};

typedef struct Blob_MethodRefSig_10 Blob_MethodRefSig_10, *PBlob_MethodRefSig_10;

typedef struct MethodRefSig_10 MethodRefSig_10, *PMethodRefSig_10;

typedef struct Type_3505 Type_3505, *PType_3505;

typedef struct Type_3506 Type_3506, *PType_3506;

struct Type_3505 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct Type_3506 {
    struct ValueType.conflict ELEMENT_TYPE_VALUETYPE;
};

struct MethodRefSig_10 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3505 RetType;
    struct Type_3506 Param0;
};

struct Blob_MethodRefSig_10 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_10 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_CustomAttrib_293 Blob_CustomAttrib_293, *PBlob_CustomAttrib_293;

struct Blob_CustomAttrib_293 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_293 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct Blob_MethodDefSig_122 Blob_MethodDefSig_122, *PBlob_MethodDefSig_122;

typedef struct MethodDefSig_122 MethodDefSig_122, *PMethodDefSig_122;

typedef struct Type_3617 Type_3617, *PType_3617;

typedef struct Type_3618 Type_3618, *PType_3618;

struct Type_3617 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct Type_3618 {
    struct SzArray_3619 ELEMENT_TYPE_SZARRAY;
};

struct MethodDefSig_122 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte Count; // Number of parameter types to follow RetType
    struct Type_3617 RetType;
    struct Type_3618 Param0;
};

struct Blob_MethodDefSig_122 {
    byte Size; // coded integer - blob size
    struct MethodDefSig_122 MethodDefSig; // Type info for method return and params
};

typedef struct Blob_Generic_27 Blob_Generic_27, *PBlob_Generic_27;

struct Blob_Generic_27 {
    byte Size; // coded integer - blob size
    byte Generic[9]; // Undefined blob contents
};

typedef struct Blob_Generic_168 Blob_Generic_168, *PBlob_Generic_168;

struct Blob_Generic_168 {
    byte Size; // coded integer - blob size
    byte Generic[8]; // Undefined blob contents
};

typedef struct Blob_Generic_21 Blob_Generic_21, *PBlob_Generic_21;

struct Blob_Generic_21 {
    byte Size; // coded integer - blob size
    byte Generic[5]; // Undefined blob contents
};

typedef struct Blob_MethodRefSig_6 Blob_MethodRefSig_6, *PBlob_MethodRefSig_6;

typedef struct MethodRefSig_6 MethodRefSig_6, *PMethodRefSig_6;

struct MethodRefSig_6 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3501 RetType;
};

struct Blob_MethodRefSig_6 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_6 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_CustomAttrib_299 Blob_CustomAttrib_299, *PBlob_CustomAttrib_299;

struct Blob_CustomAttrib_299 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_299 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct Blob_MethodRefSig_1 Blob_MethodRefSig_1, *PBlob_MethodRefSig_1;

typedef struct MethodRefSig_1 MethodRefSig_1, *PMethodRefSig_1;

typedef struct Type_3496 Type_3496, *PType_3496;

typedef struct Type_3497 Type_3497, *PType_3497;

struct Type_3497 {
    enum TypeCode ELEMENT_TYPE_I4;
};

struct Type_3496 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct MethodRefSig_1 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3496 RetType;
    struct Type_3497 Param0;
};

struct Blob_MethodRefSig_1 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_1 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_LocalVarSig_27 Blob_LocalVarSig_27, *PBlob_LocalVarSig_27;

typedef struct LocalVarSig_27 LocalVarSig_27, *PLocalVarSig_27;

typedef struct Type_3522 Type_3522, *PType_3522;

typedef struct Type_3524 Type_3524, *PType_3524;

typedef struct Type_3526 Type_3526, *PType_3526;

typedef struct Type_3528 Type_3528, *PType_3528;

struct Type_3526 {
    struct SzArray_3527 ELEMENT_TYPE_SZARRAY;
};

struct Type_3524 {
    struct SzArray_3525 ELEMENT_TYPE_SZARRAY;
};

struct Type_3528 {
    enum TypeCode ELEMENT_TYPE_I4;
};

struct Type_3522 {
    struct SzArray_3523 ELEMENT_TYPE_SZARRAY;
};

struct LocalVarSig_27 {
    byte LOCAL_SIG; // Magic (0x07)
    byte Count; // Number of types to follow
    struct Type_3522 Type;
    struct Type_3524 Type;
    struct Type_3526 Type;
    struct Type_3528 Type;
};

struct Blob_LocalVarSig_27 {
    byte Size; // coded integer - blob size
    struct LocalVarSig_27 LocalVarSig; // Contains signature for function locals
};

typedef struct Blob_MethodDefSig_111 Blob_MethodDefSig_111, *PBlob_MethodDefSig_111;

typedef struct MethodDefSig_111 MethodDefSig_111, *PMethodDefSig_111;

typedef struct Type_3606 Type_3606, *PType_3606;

typedef struct Type_3607 Type_3607, *PType_3607;

struct Type_3606 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct Type_3607 {
    enum TypeCode ELEMENT_TYPE_U1;
};

struct MethodDefSig_111 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte Count; // Number of parameter types to follow RetType
    struct Type_3606 RetType;
    struct Type_3607 Param0;
};

struct Blob_MethodDefSig_111 {
    byte Size; // coded integer - blob size
    struct MethodDefSig_111 MethodDefSig; // Type info for method return and params
};

typedef struct Blob_MethodDefSig_116 Blob_MethodDefSig_116, *PBlob_MethodDefSig_116;

typedef struct MethodDefSig_116 MethodDefSig_116, *PMethodDefSig_116;

typedef struct Type_3611 Type_3611, *PType_3611;

typedef struct Type_3612 Type_3612, *PType_3612;

struct Type_3611 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct Type_3612 {
    struct SzArray_3613 ELEMENT_TYPE_SZARRAY;
};

struct MethodDefSig_116 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte Count; // Number of parameter types to follow RetType
    struct Type_3611 RetType;
    struct Type_3612 Param0;
};

struct Blob_MethodDefSig_116 {
    byte Size; // coded integer - blob size
    struct MethodDefSig_116 MethodDefSig; // Type info for method return and params
};

typedef struct Blob_MethodRefSig_85 Blob_MethodRefSig_85, *PBlob_MethodRefSig_85;

typedef struct MethodRefSig_85 MethodRefSig_85, *PMethodRefSig_85;

typedef struct Type_3580 Type_3580, *PType_3580;

typedef struct Type_3581 Type_3581, *PType_3581;

struct Type_3580 {
    enum TypeCode ELEMENT_TYPE_VOID;
};

struct Type_3581 {
    struct SzArray_3582 ELEMENT_TYPE_SZARRAY;
};

struct MethodRefSig_85 {
    byte Flags; // ORed VARARG/GENERIC/HASTHIS/EXPLICITTHIS
    byte ParamCount; // Number of parameter types to follow RetType
    struct Type_3580 RetType;
    struct Type_3581 Param0;
};

struct Blob_MethodRefSig_85 {
    byte Size; // coded integer - blob size
    struct MethodRefSig_85 MethodRefSig; // Type info for imported method return and params
};

typedef struct Blob_Generic_37 Blob_Generic_37, *PBlob_Generic_37;

struct Blob_Generic_37 {
    byte Size; // coded integer - blob size
    byte Generic[7]; // Undefined blob contents
};

typedef struct Blob_CustomAttrib_343 Blob_CustomAttrib_343, *PBlob_CustomAttrib_343;

struct Blob_CustomAttrib_343 {
    byte Size; // coded integer - blob size
    struct CustomAttrib_343 CustomAttrib; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct ParamRow ParamRow, *PParamRow;

typedef enum ParamAttributes {
    In=1,
    Out=2,
    Optional=16,
    HasDefault=4096,
    HasFieldMarshal=8192,
    Unused=53216
} ParamAttributes;

struct ParamRow {
    enum ParamAttributes Flags; // bitmask of type ParamAttributes
    word Sequence; // constant
    word Name; // index into String heap
};

typedef struct Field Row Field Row, *PField Row;

typedef enum FieldAttributes {
    Access_CompilerControlled=0,
    Access_Private=1,
    Access_FamANDAssem=2,
    Access_Assembly=3,
    Access_Family=4,
    Access_FamORAssem=5,
    Access_Public=6,
    Static=16,
    InitOnly=32,
    Literal=64,
    NotSerialized=128,
    HasFieldRVA=256,
    SpecialName=512,
    RTSpecialName=1024,
    HasFieldMarshal=4096,
    PInvokeImpl=8192,
    HasDefault=32768
} FieldAttributes;

struct Field Row {
    enum FieldAttributes Flags; // see CorFieldAttr
    word Name; // index into String heap
    word Signature; // index into Blob heap
};

typedef struct AssemblyRef Row AssemblyRef Row, *PAssemblyRef Row;

typedef enum AssemblyFlags {
    PublicKey=1,
    Retargetable=256,
    DisableJITcompileOptimizer=16384,
    EnableJITcompileTracking=32768
} AssemblyFlags;

struct AssemblyRef Row {
    word MajorVersion;
    word MinorVersion;
    word BuildNumber;
    word RevisionNumber;
    enum AssemblyFlags Flags; // Bitmask of type AssemblyFlags
    word PublicKeyOrToken; // Public Key or token identifying the author of the assembly.
    word Name; // index into String heap
    word Culture; // index into String heap
    word HashValue; // index into Blob heap
};

typedef struct MethodSpec Row MethodSpec Row, *PMethodSpec Row;

struct MethodSpec Row {
    word Method; // MethodDefOrRef coded index
    word Instantiation; // index into Blob heap, signature of this instantiation
};

typedef struct MethodDef Row MethodDef Row, *PMethodDef Row;

typedef enum MethodImplAttributes {
    CodeType_IL=0,
    CodeType_Native=1,
    CodeType_OPTIL=2,
    CodeType_Runtime=3,
    Unmanaged=4,
    NoInlining=8,
    ForwardRef=16,
    Synchronized=32,
    NoOptimization=64,
    PreserveSig=128,
    InternalCall=4096,
    MaxMethodImplVal=65535
} MethodImplAttributes;

typedef enum MethodAttributes {
    MAccess_CompilerControlled=0,
    MAccess_Private=1,
    MAccess_FamANDAssem=2,
    MAccess_Assem=3,
    MAccess_Family=4,
    MAccess_FamORAssem=5,
    MAccess_Public=6,
    UnmanagedExport=8,
    Static=16,
    Final=32,
    Virtual=64,
    HideBySig=128,
    VtableLayout_NewSlot=256,
    Strict=512,
    Abstract=1024,
    SpecialName=2048,
    RTSpecialName=4096,
    PInvokeImpl=8192,
    HasSecurity=16384,
    RequireSecObject=32768
} MethodAttributes;

struct MethodDef Row {
    dword RVA;
    enum MethodImplAttributes ImplFlags; // Bitmask of type MethodImplAttributes
    enum MethodAttributes Flags; // Bitmask of type MethodAttribute
    word Name; // index into String heap
    word Signature; // index into Blob heap
    word ParamList; // index into Param table
};

typedef struct NestedClass Row NestedClass Row, *PNestedClass Row;

struct NestedClass Row {
    word NestedClass; // TypeDef index
    word EnclosingClass; // TypeDef index
};

typedef struct MemberRef Row MemberRef Row, *PMemberRef Row;

struct MemberRef Row {
    word Class; // index-MemberRefParent coded
    word Name; // index into String heap
    word Signature; // index into Blob heap
};

typedef struct FieldRVA Row FieldRVA Row, *PFieldRVA Row;

struct FieldRVA Row {
    dword RVA;
    word Field; // index into Field table
};

typedef struct TypeRef Row TypeRef Row, *PTypeRef Row;

struct TypeRef Row {
    word ResolutionScope;
    word TypeName;
    word TypeNamespace;
};

typedef struct CustomAttribute Row CustomAttribute Row, *PCustomAttribute Row;

struct CustomAttribute Row {
    word Parent;
    word Type;
    word Value;
};

typedef struct TypeDef Row TypeDef Row, *PTypeDef Row;

typedef enum TypeAttributes {
    Visibility_NotPublic=0,
    Visibility_Public=1,
    Visibility_NestedPublic=2,
    Visibility_NestedPrivate=3,
    Visibility_NestedFamily=4,
    Visibility_NestedAssembly=5,
    Visibility_NestedFamANDAssem=6,
    Visibility_NestedFamORAssem=7,
    SequentialLayout=8,
    ExplicitLayout=16,
    Interface=32,
    Abstract=128,
    Sealed=256,
    SpecialName=1024,
    RTSpecialName=2048,
    Import=4096,
    Serializable=8192,
    UnicodeClass=65536,
    AutoClass=131072,
    CustomFormatClass=196608,
    HasSecurity=262144,
    BeforeFieldInit=1048576,
    IsTypeForwarder=2097152,
    CustomStringFormatMask=12582912
} TypeAttributes;

struct TypeDef Row {
    enum TypeAttributes Flags; // see CorTypeAttr
    word TypeName; // index into String heap
    word TypeNamespace; // index into String heap
    word Extends; // index: coded TypeDefOrRef
    word FieldList; // index into Field table
    word MethodList; // index into MethodDef table
};

typedef struct StandAloneSig Row StandAloneSig Row, *PStandAloneSig Row;

struct StandAloneSig Row {
    word Signature;
};

typedef struct ClassLayout Row ClassLayout Row, *PClassLayout Row;

struct ClassLayout Row {
    word PackingSize;
    dword ClassSize;
    word Parent;
};

typedef struct Assembly Table Assembly Table, *PAssembly Table;

typedef enum AssemblyHash {
    None=0,
    Reserved (MD5)=32771,
    SHA1=32772
} AssemblyHash;

struct Assembly Table {
    enum AssemblyHash HashAlg; // Type of hash present
    word MajorVersion;
    word MinorVersion;
    word BuildNumber;
    word RevisionNumber;
    enum AssemblyFlags Flags; // Bitmask of type AssemblyFlags
    word PublicKey; // index into Blob heap
    word Name; // index into String heap
    word Culture; // index into String heap
};

typedef struct Module Row Module Row, *PModule Row;

struct Module Row {
    word Generation; // reserved, shall be 0
    word Name; // index into String heap
    word MvId; // used to distinguish between versions of same module
    word EncId; // reserved, shall be 0
    word EncBaseId; // reserved, shall be 0
};

typedef struct #US #US, *P#US;

struct #US {
    byte Reserved; // Always 0
    byte Next string size;
    wchar16 [1][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [17][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [2d][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [43][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [59][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [6f][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [85][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [9b][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [b1][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [c7][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [dd][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [f3][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [109][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [11f][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [135][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [14b][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [161][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [177][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [18d][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [1a3][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [1b9][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [1cf][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [1e5][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [1fb][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [211][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [227][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [23d][10];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    wchar16 [253][2];
    byte Extra byte; // 0x01 if string contains non-ASCII
    byte Next string size;
    byte Extra byte; // 0x01 if string contains non-ASCII
};

typedef struct #GUID #GUID, *P#GUID;

struct #GUID {
    GUID [0];
};

typedef struct #Strings #Strings, *P#Strings;

struct #Strings {
    char [0][1];
    char [1][30];
    char [1f][14];
    char [2d][6];
    char [33][9];
    char [3c][31];
    char [5b][65];
    char [9c][27];
    char [b7][11];
    char [c2][19];
    char [d5][15];
    char [e4][10];
    char [ee][8];
    char [f6][18];
    char [108][27];
    char [123][24];
    char [13b][20];
    char [14f][18];
    char [161][23];
    char [178][25];
    char [191][29];
    char [1ae][38];
    char [1d4][31];
    char [1f3][32];
    char [213][25];
    char [22c][25];
    char [245][25];
    char [25e][30];
    char [27c][5];
    char [281][5];
    char [286][26];
    char [2a0][7];
    char [2a7][16];
    char [2b7][8];
    char [2bf][7];
    char [2c6][5];
    char [2cb][5];
    char [2d0][23];
    char [2e7][18];
    char [2f9][12];
    char [305][6];
    char [30b][19];
    char [31e][32];
    char [33e][15];
    char [34d][14];
    char [35b][5];
    char [360][23];
    char [377][15];
    char [386][17];
    char [397][7];
    char [39e][12];
    char [3aa][16];
    char [3ba][8];
    char [3c2][1];
    char [3c3][1];
};

typedef struct #~ #~, *P#~;

struct #~ {
    dword Reserved; // Always 0
    byte MajorVersion;
    byte MinorVersion;
    byte HeapSizes; // Bit vector for heap sizes
    byte Reserved; // Always 1
    qword Valid; // Bit vector of present tables
    qword Sorted; // Bit vector of sorted tables
    dword Rows[15]; // # of rows for each corresponding present table
    struct Module Row Module; // CLI Metadata Table: Module
    struct TypeRef Row TypeRef[25]; // CLI Metadata Table: TypeRef
    struct TypeDef Row TypeDef[7]; // CLI Metadata Table: TypeDef
    struct Field Row Field[3]; // CLI Metadata Table: Field
    struct MethodDef Row MethodDef[6]; // CLI Metadata Table: MethodDef
    struct ParamRow Param[1]; // CLI Metadata Table: Param
    struct MemberRef Row MemberRef[19]; // CLI Metadata Table: MemberRef
    struct CustomAttribute Row CustomAttribute[20]; // CLI Metadata Table: CustomAttribute
    struct ClassLayout Row ClassLayout[1]; // CLI Metadata Table: ClassLayout
    struct StandAloneSig Row StandAloneSig[1]; // CLI Metadata Table: StandAloneSig
    struct FieldRVA Row FieldRVA[1]; // CLI Metadata Table: FieldRVA
    struct Assembly Table Assembly; // CLI Metadata Table: Assembly
    struct AssemblyRef Row AssemblyRef[2]; // CLI Metadata Table: AssemblyRef
    struct NestedClass Row NestedClass[1]; // CLI Metadata Table: NestedClass
    struct MethodSpec Row MethodSpec[2]; // CLI Metadata Table: MethodSpec
};

typedef struct #Blob #Blob, *P#Blob;

struct #Blob {
    byte Reserved; // Always 0
    struct Blob_MethodRefSig_1 MethodRefSig_1; // Type info for imported method return and params
    struct Blob_MethodRefSig_6 MethodRefSig_6; // Type info for imported method return and params
    struct Blob_MethodRefSig_10 MethodRefSig_10; // Type info for imported method return and params
    struct Blob_MethodRefSig_16 MethodRefSig_16; // Type info for imported method return and params
    struct Blob_MethodRefSig_21 MethodRefSig_21; // Type info for imported method return and params
    struct Blob_LocalVarSig_27 LocalVarSig_27; // Contains signature for function locals
    struct Blob_MethodRefSig_37 MethodRefSig_37; // Type info for imported method return and params
    struct Blob_MethodRefSig_45 MethodRefSig_45; // Type info for imported method return and params
    struct Blob_MethodRefSig_52 MethodRefSig_52; // Type info for imported method return and params
    struct Blob_MethodSpecSig_68 MethodSpecSig_68; // Specifies a generic method with GenArgCount types
    struct Blob_MethodRefSig_72 MethodRefSig_72; // Type info for imported method return and params
    struct Blob_MethodRefSig_85 MethodRefSig_85; // Type info for imported method return and params
    struct Blob_Generic_91 [5b];
    struct Blob_FieldSig_100 FieldSig_100; // Type information for Field
    struct Blob_FieldSig_104 FieldSig_104; // Type information for Field
    struct Blob_FieldSig_107 FieldSig_107; // Type information for Field
    struct Blob_MethodDefSig_111 MethodDefSig_111; // Type info for method return and params
    struct Blob_MethodDefSig_116 MethodDefSig_116; // Type info for method return and params
    struct Blob_MethodDefSig_122 MethodDefSig_122; // Type info for method return and params
    struct Blob_CustomAttrib_128 CustomAttrib_128; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_137 CustomAttrib_137; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_168 CustomAttrib_168; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_Generic_177 [b1];
    struct Blob_CustomAttrib_239 CustomAttrib_239; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_256 CustomAttrib_256; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_269 CustomAttrib_269; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_282 CustomAttrib_282; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_293 CustomAttrib_293; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_299 CustomAttrib_299; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_304 CustomAttrib_304; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
    struct Blob_CustomAttrib_343 CustomAttrib_343; // A CustomAttrib blob stores values of fixed or named parameters supplied when instantiating a custom attribute
};

typedef struct MethodDefHdr_Fat MethodDefHdr_Fat, *PMethodDefHdr_Fat;

struct MethodDefHdr_Fat {
    word Size+Flags; // L.S. Bits 0:3 Size of hdr in bytes, Bits 4:15 Flags
    word MaxStack; // Maximum number of items on the operand stack
    dword CodeSize; // Size of actual method body in bytes
    dword LocalVarSigTok; // Signature for the local variables of the method. 0 means no locals. References standalone signature in Metadata tables, which references #Blob heap.
};

typedef struct MethodDefHdr_Tiny MethodDefHdr_Tiny, *PMethodDefHdr_Tiny;

struct MethodDefHdr_Tiny {
    byte Size+Flags; // L.S. Bits 0:1 Flags, Bits 2:7 Size of method in Bytes
};

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef struct DotNetPdbInfo DotNetPdbInfo, *PDotNetPdbInfo;

struct DotNetPdbInfo {
    char signature[4];
    GUID guid;
    dword age;
    char pdbpath[86];
};




void entry(void)

{
                    // WARNING: Could not recover jumptable at 0x00402e62. Too many branches
                    // WARNING: Treating indirect jump as call
  _CorExeMain();
  return;
}


