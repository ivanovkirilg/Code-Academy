/* Задача 13. Напишете програма, която намира дължината на стринг с пойнтер! */

#include <stdio.h>

int stringlen(char *strStart);

int main() {
    char string[] = "Hello";
    printf("%d", stringlen(string));
    
    return 0;
}

int stringlen(char *strStart) {
    char *strEnd = strStart;
    while (*strEnd++);
    return strEnd - strStart - 1u;
}