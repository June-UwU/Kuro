#pragma once
#include <stdint.h>

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

