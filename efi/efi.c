#include "efi.h"

static EFI_SYSTEM_TABLE*                 ST     = nullptr;
static EFI_RUNTIME_SERVICES*             RS     = nullptr;
static EFI_BOOT_SERVICES*                BS     = nullptr;
static EFI_SIMPLE_TEXT_INPUT_PROTOCOL*   ConIn  = nullptr;
static EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*  ConOut = nullptr;
static EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL*  ConErr = nullptr;
