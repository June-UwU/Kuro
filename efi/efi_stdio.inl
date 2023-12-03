#include <stdarg.h>

VOID printNumber(UINTN num, UINTN base);
VOID reverse(CHAR16* str, UINTN len);

INTN printf(const CHAR16* format, ...) {
    va_list args;
    va_start(args,format);

    UINT16 buffer[2];
    buffer[0] = u'\0';
    buffer[1] = u'\0';

    int offset = 0;
    while(format[offset] != u'\0') {

        if(u'%' == format[offset]) {
            offset++;
            UINT16 vaPredicate = format[offset];
            switch(vaPredicate) {
                case u'c': {
                    buffer[0] = va_arg(args,INT32);;
                    ConOut->OutputString(ConOut,buffer);
                } break;
                case u's': {
                    CHAR16* string = va_arg(args,CHAR16*);
                    ConOut->OutputString(ConOut,string);
                } break;
                case u'd':
                case u'i': {
                    INTN number = va_arg(args,INTN);
                    printNumber(number,10);
                } break;
                case u'o': {
                    UINTN number = va_arg(args,UINTN);
                    printNumber(number,8);
                } break;
                case u'x':
                case u'X': {
                    ConOut->OutputString(ConOut,u"0x");
                    UINTN number = va_arg(args,UINTN);
                    printNumber(number,16);
                } break;
                default: {
                    ConOut->OutputString(ConOut,u"Unknown format specifier");
                    goto error_exit;
                }
            }
        }
        else {
            buffer[0] = format[offset];
            ConOut->OutputString(ConOut,buffer);
        }

        offset++;
    }

error_exit:
    va_end(args);
    return offset;
}


VOID printNumber(UINTN num, UINTN base) {
    CHAR16 buffer[32];
    UINTN offset = 0;

    while(num > 0) {
        CHAR16 temp = u'0' + num % base;
        if(u'9' < temp) {
            temp = u'A' + temp - u'9' - 1;
        }
        buffer[offset] = temp;
        num = num / base;
        offset++;
    }
    buffer[offset] = u'\0';
    reverse(buffer,offset);

    ConOut->OutputString(ConOut,buffer);
}

VOID reverse(CHAR16* str, UINTN len) {
    UINTN i = 0;
    UINTN j = len - 1;
    while(i < j) {
        CHAR16 temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
