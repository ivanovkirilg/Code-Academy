/* Задача 16. strcpy() */

#include <stdio.h>
#include <string.h>

int main() {
    char string1[32] = "A string to be copied.";
    char string2[32];
    char string3[32] = "Another one.";
    char string4[32];

    strcpy(string2, string1);
    printf("%s\n", string2);
    strcpy(string4, string3);
    printf("%s\n", string4);
    strcpy(string4, string1);
    printf("%s\n", string4);
    
    return 0;
}