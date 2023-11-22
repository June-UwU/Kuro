#include "efi.h"

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) {
    (void) ImageHandle;
    
    INITIALIZE_EFI_GLOBALS(SystemTable)

    ST->ConOut->ClearScreen(ST->ConOut);
    ST->ConOut->SetAttribute(ST->ConOut,EFI_TEXT_ATTR(EFI_BLUE,EFI_RED));
    ST->ConOut->OutputString(ST->ConOut,u"Hello, World!\n");
    
    while(TRUE);
    return EFI_SUCCESS;
}
