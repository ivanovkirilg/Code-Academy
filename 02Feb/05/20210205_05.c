/*  Задача 5. Напишете функцията void our_strcat(char *s, char *t), 
    която добавя (конкатенира) стринга t в края на стринга s. */

#include <stdio.h>

void my_strcat(char *s, char *t) {
    while (*s++);
    --s;
    while (*s++ = *t++);
}

int main() {
    char string1[64] = "The second string is: ";
    char string2[] = "A whole new string!";

    my_strcat(string1, string2);

    printf("%s", string1);
    
    return 0;
}
