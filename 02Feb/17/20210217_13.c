/*  Задача 13. Напишете програма, която да прочете низ от потребителя 
    и да го обърне в обратен ред. Например: 'xyz' да стане 'zyx' */

#include <stdio.h>
#include <string.h>

int main() {
    char string[64];

    printf("Enter string:\n");
    gets(string);
    strrev(string);
    printf("%s", string);
    
    return 0;
}
