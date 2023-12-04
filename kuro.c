#include "efi.h"
#include "efi_stdio.inl"


EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) {
    (void) ImageHandle;
    
    INITIALIZE_EFI_GLOBALS(SystemTable)

    clearScreen();
    setAttribute(EFI_TEXT_ATTR(EFI_BLUE,EFI_RED));
    
    UINTN modes = 0;
    UINTN height = 0;
    UINTN width = 0;
    EFI_STATUS status = ConOut->QueryMode(ConOut, modes, &width, &height);

    for(; EFI_SUCCESS == status;) {
        modes++;
        printf(u"Mode %d: %dx%d\n", modes, width, height);
        status = ConOut->QueryMode(ConOut, modes, &width, &height);
    }
    
    while(TRUE);
    return EFI_SUCCESS;
}
