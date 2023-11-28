#include "efi.h"

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) {
    (void) ImageHandle;
    
    INITIALIZE_EFI_GLOBALS(SystemTable)

    ConOut->ClearScreen(ConOut);
    ConOut->SetAttribute(ConOut,EFI_TEXT_ATTR(EFI_BLUE,EFI_RED));
    ConOut->OutputString(ConOut,u"RunTime and BootTime Services Test!\n");
    
    while(TRUE);
    return EFI_SUCCESS;
}
