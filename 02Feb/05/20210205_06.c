/*  Задача 6. Напишете отново функцията void our_strcat(char *s, char *t), 
    която разгледахме преди малко като използвате указатели, 
    а не инкрементиращите пrоменливи i, j. 
    
    Аз първоначално я написах с указатели, тъй като това учим.
    Затова ето копие на решението. */

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