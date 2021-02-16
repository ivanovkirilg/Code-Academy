/*  Задача 18. Нека сега отпечатаме стринговете с декрементиране, започвайки отзад-напред.
    strlen(). Помислете как да направите проверка във функцията за копиране, 
    дали размерът на стринга, в който копираме, не е по-малък от размера на стринга, 
    от който копираме, и какво да се случва тогава.*/


#include <stdio.h>
#include <string.h>

void copyString(char *from, char *to, size_t toSize);

int main() {
    char string1[] = "A string to be copied.";
    char string2[16];
    char string3[] = "Another one.";
    char string4[16];

    /* When target array is too small, only the end of the source is copied. */
    copyString(string1, string2, sizeof(string2));
    printf("%s\n", string2);
    copyString(string3, string4, sizeof(string4));
    printf("%s\n", string4);
    
    return 0;
}

void copyString(char *from, char *to, size_t toSize) {
    int i = strlen(from);
    from += i;
    if (i >= toSize) {
        i = toSize - 1;
    }
    to += i;
    while (i-- + 1) {
        *to-- = *from--;
    }
}
