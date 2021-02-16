/* Задача 15. Ще копираме стрингове. */

#include <stdio.h>

void copyString(char *from, char *to);

int main() {
    char string1[32] = "A string to be copied.";
    char string2[32];
    char string3[32] = "Another one.";
    char string4[32];

    copyString(string1, string2);
    printf("%s\n", string2);
    copyString(string3, string4);
    printf("%s\n", string4);
    copyString(string1, string4);
    printf("%s\n", string4);
    
    return 0;
}

void copyString(char *from, char *to) {
    while (*to++ = *from++);
    *to = *from;
}

/* Продължение: Опитайте какво ще стане, ако изпишем инкрементирането така: *++to= *++from; */

/* Ще пропуснем първия символ. */
