/*  Задача 8. Напишете функция void reverse(char s[]), която обръща низа char s[ ]. 
    Използвайте for цикъл с два аргумента, разделени със запетая. */

#include <stdio.h>

void reverseString(char *p_string);

int main() {
    char str[] = "Miro";
    reverseString(str);
    printf("%s\n", str);
}

/* Both functions are from my own library */
int stringLength(char *p_string) {
    int i = 0;
    for ( ; p_string[i]!='\0'; i++);
    return i;
}

void reverseString(char *p_string) {
    for (int i=0, j=stringLength(p_string)-1; i < j; i++, j-- ) {
        char temp = p_string[i];
        p_string[i] = p_string[j];
        p_string[j] = temp;
    }
}