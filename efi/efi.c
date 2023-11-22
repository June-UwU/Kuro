#include "efi.h"

static EFI_SYSTEM_TABLE* ST     = nullptr;
static EFI_RUNTIME_SERVICES* RS = nullptr;
static EFI_BOOT_SERVICES* BS    = nullptr;
