#include "efi.h"

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) {
    (void) ImageHandle;
    
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut,EFI_TEXT_ATTR(EFI_BLUE,EFI_RED));
    SystemTable->ConOut->OutputString(SystemTable->ConOut,u"Hello, World!\n");
    
    while(TRUE);
    return EFI_SUCCESS;
}
