/*  Задача 10. Напишете функцията strncat(s, t, n), която добавя 
    (конкатенира) n символа от стринга t в края на стринга s. */

#include <stdio.h>

void my_strcat(char *s, char *t, unsigned int n) {
    while (*s++);
    --s;
    while ( (*s++ = *t++) && --n ); 
    /* prefix decrement because we add chars in the condition of the loop */
}

int main() {
    char string1[64] = "The second string is: ";
    char string2[] = "A whole new string!";

    my_strcat(string1, string2, 5u);

    printf("%s", string1);
    
    return 0;
}
