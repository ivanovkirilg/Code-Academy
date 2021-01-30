/*  Задача 13. Ако имаме символен низ char str[] = “HELLO”,
    заменете всичките символи с главна буква със съответните символи с малка буква. */

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "HELLO world!";
    for (int i = 0; i<strlen(str); i++) {
        if (str[i] > 64 && str[i] < 91) str[i] = (char) (str[i]+32);
    }

    printf("%s\n", str);
    
    return 0;
}