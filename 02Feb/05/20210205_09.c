/* Задача 9.  Напишете функцията strncpy(s, t, n), която копира най-много n символа от t в s . */

#include <stdio.h>

void my_strcpy(char *s, char *t, unsigned int n) {
    while (*t && n--) {
        *s = *t;
        s++, t++;
    }
}

int main() {
    char originalString[] = "A whole new world!";
    char copyString[32] = "";

    my_strcpy(copyString, originalString, 5u);

    printf("Original:\t%s\n", originalString);
    printf("Copy 5 chars:\t%s\n", copyString);
    
    return 0;
}
