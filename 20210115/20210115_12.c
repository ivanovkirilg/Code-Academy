/*  Задача 12. Ако имаме символен низ char str[] = “Hеllo”, 
    заменете буквите l с х на същия символен низ 
    и отпечатайте резултата на конзолата. */

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello";
    for (int i = 0; i<strlen(str); i++) {
        if (str[i]=='l') str[i] = 'x';
    }

    printf("%s\n", str);
    
    return 0;
}