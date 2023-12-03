#include "efi.h"
#include "efi_stdio.inl"


EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) {
    (void) ImageHandle;
    
    INITIALIZE_EFI_GLOBALS(SystemTable)

    ConOut->ClearScreen(ConOut);
    ConOut->SetAttribute(ConOut,EFI_TEXT_ATTR(EFI_BLUE,EFI_RED));
    printf(u"Hello, World inline test!\n");
    printf(u"decimal value : %d\n",1024);
    printf(u"hexadecimal value : %x\n",0x1024);
    printf(u"character value : %c\n",u'F');
    printf(u"string value : %s\n",u"hello world");
    while(TRUE);
    return EFI_SUCCESS;
}
