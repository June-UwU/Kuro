#pragma once
#include <stdint.h>

// UEFI Specs: https://uefi.org/sites/default/files/resources/UEFI_Spec_2_9_2021_03_18.pdf 


#define IN
#define OUT
#define OPTIONAL
#define CONST const
// uefi calling conventions
#define EFIAPI __attribute__((ms_abi))


// uefi types 
typedef uint8_t         BOOLEAN;
typedef int64_t         INTN;
typedef uint64_t        UINTN;
typedef int8_t          INT8;
typedef uint8_t         UINT8;
typedef int16_t         INT16;
typedef uint16_t        UINT16;
typedef int32_t         INT32;
typedef uint32_t        UINT32;
typedef int64_t         INT64;
typedef uint64_t        UINT64;
typedef unsigned char   CHAR8;
typedef uint16_t        CHAR16;
typedef void            VOID;
// uefi section : 7.3.2
typedef struct {
  UINT32 Data1;
  UINT16 Data2;
  UINT16 Data3;
  UINT8  Data4[8];
} EFI_GUID;
typedef UINTN       EFI_STATUS;
typedef VOID*       EFI_HANDLE;
typedef VOID*       EFI_EVENT;
typedef UINT64      EFI_LBA;
typedef UINTN       EFI_TPL;        


// BOOLEAN
#define FALSE 0
#define TRUE  1
// EFI status codes
enum {
  EFI_SUCCESS = 0x0,
  EFI_LOAD_ERROR,
  EFI_INVALID_PARAMETER,
  EFI_UNSUPPORTED,
  EFI_BAD_BUFFER_SIZE,
  EFI_BUFFER_TOO_SMALL,
  EFI_NOT_READY,
  EFI_DEVICE_ERROR,
  EFI_WRITE_PROTECTED,
  EFI_OUT_OF_RESOURCES,
  EFI_VOLUME_CORRUPTED,
  EFI_VOLUME_FULL,
  EFI_NO_MEDIA,
  EFI_MEDIA_CHANGED,
  EFI_NOT_FOUND,
  EFI_ACCESS_DENIED,
  EFI_NO_RESPONSE,
  EFI_NO_MAPPING,
  EFI_TIMEOUT,
  EFI_NOT_STARTED,
  EFI_ALREADY_STARTED,
  EFI_ABORTED,
  EFI_ICMP_ERROR,
  EFI_TFTP_ERROR,
  EFI_PROTOCOL_ERROR,
  EFI_INCOMPATIBLE_VERSION,
  EFI_SECURITY_VIOLATION,
  EFI_CRC_ERROR,
  EFI_END_OF_MEDIA,
  EFI_END_OF_FILE = 31,
  EFI_INVALID_LANGUAGE,
  EFI_COMPROMISED_DATA,
  EFI_IP_ADDRESS_CONFLICT,
  EFI_HTTP_ERROR,
};


enum {
  EFI_WARN_UNKNOWN_GLYPH = 0x1,
  EFI_WARN_DELETE_FAILURE,
  EFI_WARN_WRITE_FAILURE,
  EFI_WARN_BUFFER_TOO_SMALL,
  EFI_WARN_STALE_DATA,
  EFI_WARN_FILE_SYSTEM,
  EFI_WARN_RESET_REQUIRED
};

//*******************************************************
// UNICODE DRAWING CHARACTERS
//*******************************************************
#define BOXDRAW_HORIZONTAL 0x2500
#define BOXDRAW_VERTICAL 0x2502
#define BOXDRAW_DOWN_RIGHT 0x250c
#define BOXDRAW_DOWN_LEFT 0x2510
#define BOXDRAW_UP_RIGHT 0x2514
#define BOXDRAW_UP_LEFT 0x2518
#define BOXDRAW_VERTICAL_RIGHT 0x251c
#define BOXDRAW_VERTICAL_LEFT 0x2524
#define BOXDRAW_DOWN_HORIZONTAL 0x252c
#define BOXDRAW_UP_HORIZONTAL 0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL 0x253c
#define BOXDRAW_DOUBLE_HORIZONTAL 0x2550
#define BOXDRAW_DOUBLE_VERTICAL 0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE 0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT 0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT 0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE 0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT 0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT 0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE 0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT 0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT 0x255a
#define BOXDRAW_UP_LEFT_DOUBLE 0x255b
#define BOXDRAW_UP_DOUBLE_LEFT 0x255c
#define BOXDRAW_DOUBLE_UP_LEFT 0x255d
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE 0x255e
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT 0x255f
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT 0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE 0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT 0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT 0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE 0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL 0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL 0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE 0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL 0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL 0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE 0x256a
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL 0x256b
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL 0x256c
//*******************************************************
// EFI Required Block Elements Code Chart
//*******************************************************
#define BLOCKELEMENT_FULL_BLOCK 0x2588
#define BLOCKELEMENT_LIGHT_SHADE 0x2591
//*******************************************************
// EFI Required Geometric Shapes Code Chart
//*******************************************************
#define GEOMETRICSHAPE_UP_TRIANGLE 0x25b2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE 0x25ba
#define GEOMETRICSHAPE_DOWN_TRIANGLE 0x25bc
#define GEOMETRICSHAPE_LEFT_TRIANGLE 0x25c4
//*******************************************************
// EFI Required Arrow shapes
//*******************************************************
#define ARROW_UP 0x2191
#define ARROW_DOWN 0x2193

//*******************************************************
// Attributes
//*******************************************************
#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x05
#define EFI_BROWN 0x06
#define EFI_LIGHTGRAY 0x07
#define EFI_BRIGHT 0x08
#define EFI_DARKGRAY (EFI_BLACK | EFI_BRIGHT) | 0x08
#define EFI_LIGHTBLUE 0x09
#define EFI_LIGHTGREEN 0x0A
#define EFI_LIGHTCYAN 0x0B
#define EFI_LIGHTRED 0x0C
#define EFI_LIGHTMAGENTA 0x0D
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F
#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70
//
// Macro to accept color values in their raw form to create
// a value that represents both a foreground and background
// color in a single byte.
// For Foreground, and EFI_* value is valid from EFI_BLACK(0x00)
// to EFI_WHITE (0x0F).
// For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN,
// EFI_CYAN, EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY
// are acceptable.
//
// Do not use EFI_BACKGROUND_xxx values with this macro.
#define EFI_TEXT_ATTR(Foreground,Background) ((Foreground) | ((Background) << 4))

#define EFI_ERROR(status) (status != EFI_SUCCESS)

typedef struct {
  UINT64 Signature;
  UINT32 Revision;
  UINT32 HeaderSize;
  UINT32 CRC32;
  UINT32 Reserved;
} EFI_TABLE_HEADER;

// EFI stubs for forward decls
typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL; 
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// Supporting structures
typedef struct {
  UINT16 ScanCode;
  CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

//*******************************************************
// SIMPLE_TEXT_OUTPUT_MODE
//*******************************************************
typedef struct {
  INT32   MaxMode;
// current settings
  INT32   Mode;
  INT32   Attribute;
  INT32   CursorColumn;
  INT32   CursorRow;
  BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

// Protocols
typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_RESET) (
  IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL*  This,
  IN BOOLEAN                          ExtendedVerification
);

typedef
EFI_STATUS
(EFIAPI *EFI_INPUT_READ_KEY) (
  IN  EFI_SIMPLE_TEXT_INPUT_PROTOCOL*  This,
  OUT EFI_INPUT_KEY*                   Key
);

typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT) (
  IN  UINTN       NumberOfEvents,
  IN  EFI_EVENT*  Event,
  OUT UINTN*      Index
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_RESET) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*   This,
  IN BOOLEAN                            ExtendedVerification
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_STRING) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
  IN CHAR16*                          String
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_TEST_STRING) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
  IN CHAR16*                          String
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_QUERY_MODE) (
  IN  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*  This,
  IN  UINTN                             ModeNumber,
  OUT UINTN*                            Columns,
  OUT UINTN*                            Rows
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_MODE) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
  IN UINTN                            ModeNumber
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_ATTRIBUTE) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
  IN UINTN                            Attribute
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_CLEAR_SCREEN) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
  IN UINTN                            Column,
  IN UINTN                            Row
);

typedef
EFI_STATUS
(EFIAPI *EFI_TEXT_ENABLE_CURSOR) (
  IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This,
  IN BOOLEAN                          Visible
);

// Protocol Structures
#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID {0x387477c1,0x69c7,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}
typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
  EFI_INPUT_RESET     Reset;
  EFI_INPUT_READ_KEY  ReadKeyStroke;
  EFI_EVENT           WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID {0x387477c2,0x69c7,0x11d2,{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
  EFI_TEXT_RESET                Reset;
  EFI_TEXT_STRING               OutputString;
  EFI_TEXT_TEST_STRING          TestString;
  EFI_TEXT_QUERY_MODE           QueryMode;
  EFI_TEXT_SET_MODE             SetMode;
  EFI_TEXT_SET_ATTRIBUTE        SetAttribute;
  EFI_TEXT_CLEAR_SCREEN         ClearScreen;
  EFI_TEXT_SET_CURSOR_POSITION  SetCursorPosition;
  EFI_TEXT_ENABLE_CURSOR        EnableCursor;
  SIMPLE_TEXT_OUTPUT_MODE*      Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_90_SYSTEM_TABLE_REVISION

typedef struct {
  UINT16  Year; // 1900 – 9999
  UINT8   Month; // 1 – 12
  UINT8   Day; // 1 – 31
  UINT8   Hour; // 0 – 23
  UINT8   Minute; // 0 – 59
  UINT8   Second; // 0 – 59
  UINT8   Pad1;
  UINT32  Nanosecond; // 0 – 999,999,999
  INT16   TimeZone; // -1440 to 1440 or 2047
  UINT8   Daylight;
  UINT8   Pad2;
} EFI_TIME;

typedef struct {
  UINT32  Resolution;
  UINT32  Accuracy;
  BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

//*******************************************************
//EFI_PHYSICAL_ADDRESS
//*******************************************************
typedef UINT64 EFI_PHYSICAL_ADDRESS;
//*******************************************************
//EFI_VIRTUAL_ADDRESS
//*******************************************************
typedef UINT64 EFI_VIRTUAL_ADDRESS;
//*******************************************************
// Memory Descriptor Version Number
//*******************************************************
#define EFI_MEMORY_DESCRIPTOR_VERSION 1

//*******************************************************
// Memory Attribute Definitions
//*******************************************************
// These types can be “OR-ed” together as needed.
#define EFI_MEMORY_UC             0x0000000000000001
#define EFI_MEMORY_WC             0x0000000000000002
#define EFI_MEMORY_WT             0x0000000000000004
#define EFI_MEMORY_WB             0x0000000000000008
#define EFI_MEMORY_UCE            0x0000000000000010
#define EFI_MEMORY_WP             0x0000000000001000
#define EFI_MEMORY_RP             0x0000000000002000
#define EFI_MEMORY_XP             0x0000000000004000
#define EFI_MEMORY_NV             0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE  0x0000000000010000
#define EFI_MEMORY_RO             0x0000000000020000
#define EFI_MEMORY_SP             0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO     0x0000000000080000
#define EFI_MEMORY_RUNTIME        0x8000000000000000

typedef struct {
  UINT32                Type;
  EFI_PHYSICAL_ADDRESS  PhysicalStart;
  EFI_VIRTUAL_ADDRESS   VirtualStart;
  UINT64                NumberOfPages;
  UINT64                Attribute;
} EFI_MEMORY_DESCRIPTOR;

//*******************************************************
// Bit Definitions for EFI_TIME.Daylight. See below.
//*******************************************************
#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02
//*******************************************************
// Value Definition for EFI_TIME.TimeZone. See below.
//*******************************************************
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

typedef 
EFI_STATUS 
(EFIAPI *EFI_GET_TIME) (
  OUT EFI_TIME* Time, 
  OUT EFI_TIME_CAPABILITIES* Capabilities OPTIONAL
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_SET_TIME) (
  IN EFI_TIME* Time
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_GET_WAKEUP_TIME) (
  OUT BOOLEAN* Enabled, 
  OUT BOOLEAN* Pending, 
  OUT EFI_TIME* Time
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_SET_WAKEUP_TIME) (
  IN BOOLEAN Enable, 
  IN EFI_TIME* Time OPTIONAL
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP) (
  IN UINTN MemoryMapSize,
  IN UINTN DescriptorSize,
  IN UINT32 DescriptorVersion,
  IN EFI_MEMORY_DESCRIPTOR* VirtualMap
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_CONVERT_POINTER) (
  IN UINTN DebugDisposition,
  IN VOID** Address
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_GET_VARIABLE) (
  IN CHAR16* VariableName, 
  IN EFI_GUID* VendorGuid, 
  OUT UINT32* Attributes OPTIONAL, 
  IN OUT UINTN* DataSize, 
  OUT VOID* Data OPTIONAL
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_GET_NEXT_VARIABLE_NAME) (
  IN OUT UINTN* VariableNameSize, 
  IN OUT CHAR16* VariableName, 
  IN OUT EFI_GUID* VendorGuid
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_SET_VARIABLE) (
  IN CHAR16* VariableName, 
  IN EFI_GUID* VendorGuid, 
  IN UINT32 Attributes, 
  IN UINTN DataSize, 
  IN VOID* Data
);

typedef 
EFI_STATUS 
(EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT) (
  OUT UINT32* HighCount
);

typedef 
VOID 
(EFIAPI *EFI_RESET_SYSTEM) (
  IN EFI_RESET_TYPE ResetType,
  IN EFI_STATUS     ResetStatus,
  IN UINTN          DataSize,
  IN VOID*          ResetData OPTIONAL
);

typedef
EFI_STATUS 
(EFIAPI *EFI_UPDATE_CAPSULE) (
  IN EFI_CAPSULE_HEADER** CapsuleHeaderArray,
  IN UINTN                CapsuleCount,
  IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL
);


typedef
EFI_STATUS
(EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES) (
  IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
  IN UINTN CapsuleCount,
  OUT UINT64 *MaximumCapsuleSize,
  OUT EFI_RESET_TYPE *ResetType
);

typedef
EFI_STATUS
(EFIAPI *EFI_QUERY_VARIABLE_INFO) (
  IN UINT32 Attributes,
  OUT UINT64 *MaximumVariableStorageSize,
  OUT UINT64 *RemainingVariableStorageSize,
  OUT UINT64 *MaximumVariableSize
);

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

typedef struct {
  EFI_TABLE_HEADER Hdr;
  EFI_GET_TIME                    GetTime;
  EFI_SET_TIME                    SetTime;
  EFI_GET_WAKEUP_TIME             GetWakeupTime;
  EFI_SET_WAKEUP_TIME             SetWakeupTime;
  EFI_SET_VIRTUAL_ADDRESS_MAP     SetVirtualAddressMap;
  EFI_CONVERT_POINTER             ConvertPointer;
  EFI_GET_VARIABLE                GetVariable;
  EFI_GET_NEXT_VARIABLE_NAME      GetNextVariableName;
  EFI_SET_VARIABLE                SetVariable;
  EFI_GET_NEXT_HIGH_MONO_COUNT    GetNextHighMonotonicCount;
  EFI_RESET_SYSTEM                ResetSystem;
  EFI_UPDATE_CAPSULE              UpdateCapsule;
  EFI_QUERY_CAPSULE_CAPABILITIES  QueryCapsuleCapabilities;
  EFI_QUERY_VARIABLE_INFO         QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION
typedef struct {
  EFI_TABLE_HEADER                           Hdr;
  EFI_RAISE_TPL                              RaiseTPL; 
  EFI_RESTORE_TPL                            RestoreTPL;
  EFI_ALLOCATE_PAGES                         AllocatePages; 
  EFI_FREE_PAGES                             FreePages; 
  EFI_GET_MEMORY_MAP                         GetMemoryMap; 
  EFI_ALLOCATE_POOL                          AllocatePool; 
  EFI_FREE_POOL                              FreePool; 
  EFI_CREATE_EVENT                           CreateEvent; 
  EFI_SET_TIMER                              SetTimer; 
  EFI_WAIT_FOR_EVENT                         WaitForEvent; 
  EFI_SIGNAL_EVENT                           SignalEvent; 
  EFI_CLOSE_EVENT                            CloseEvent; 
  EFI_CHECK_EVENT                            CheckEvent; 
  EFI_INSTALL_PROTOCOL_INTERFACE             InstallProtocolInterface; 
  EFI_REINSTALL_PROTOCOL_INTERFACE           ReinstallProtocolInterface; 
  EFI_UNINSTALL_PROTOCOL_INTERFACE           UninstallProtocolInterface; 
  EFI_HANDLE_PROTOCOL                        HandleProtocol; 
  VOID*                                      Reserved; 
  EFI_REGISTER_PROTOCOL_NOTIFY               RegisterProtocolNotify; 
  EFI_LOCATE_HANDLE                          LocateHandle; 
  EFI_LOCATE_DEVICE_PATH                     LocateDevicePath; 
  EFI_INSTALL_CONFIGURATION_TABLE            InstallConfigurationTable; 
  EFI_IMAGE_LOAD                             LoadImage; 
  EFI_IMAGE_START                            StartImage;
  EFI_EXIT                                   Exit;
  EFI_IMAGE_UNLOAD                           UnloadImage; 
  EFI_EXIT_BOOT_SERVICES                     ExitBootServices;
  EFI_GET_NEXT_MONOTONIC_COUNT               GetNextMonotonicCount;
  EFI_STALL                                  Stall;
  EFI_SET_WATCHDOG_TIMER                     SetWatchdogTimer;
  EFI_CONNECT_CONTROLLER                     ConnectController;
  EFI_DISCONNECT_CONTROLLER                  DisconnectController;
  EFI_OPEN_PROTOCOL                          OpenProtocol; 
  EFI_CLOSE_PROTOCOL                         CloseProtocol; 
  EFI_OPEN_PROTOCOL_INFORMATION              OpenProtocolInformation;
  EFI_PROTOCOLS_PER_HANDLE                   ProtocolsPerHandle; 
  EFI_LOCATE_HANDLE_BUFFER                   LocateHandleBuffer; 
  EFI_LOCATE_PROTOCOL                        LocateProtocol; 
  EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES   InstallMultipleProtocolInterfaces; 
  EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;
  EFI_CALCULATE_CRC32                        CalculateCrc32;
  EFI_COPY_MEM                               CopyMem; 
  EFI_SET_MEM                                SetMem; 
  EFI_CREATE_EVENT_EX                        CreateEventEx; 
} EFI_BOOT_SERVICES;

typedef struct {
  EFI_TABLE_HEADER                  Hdr;
  CHAR16*                           FirmwareVendor;
  UINT32                            FirmwareRevision;
  EFI_HANDLE                        ConsoleInHandle;
  EFI_SIMPLE_TEXT_INPUT_PROTOCOL *  ConIn;
  EFI_HANDLE                        ConsoleOutHandle;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*  ConOut;
  EFI_HANDLE                        StandardErrorHandle;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*  StdErr;
  EFI_RUNTIME_SERVICES*             RuntimeServices;
  EFI_BOOT_SERVICES*                BootServices;
  UINTN                             NumberOfTableEntries;
  void* ConfigurationTable; // TO REMOVE
  // EFI_CONFIGURATION_TABLE*          ConfigurationTable;
} EFI_SYSTEM_TABLE;


extern EFI_SYSTEM_TABLE*      ST;
extern EFI_RUNTIME_SERVICES*  RS;
extern EFI_BOOT_SERVICES*     BS;

#define INITIALIZE_EFI_GLOBALS(SystemTable) \
        ST = SystemTable; \
        RS = SytemTable->RuntimeServices; \
        BS = SytemTable->BootServices;