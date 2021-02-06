/*  Задача 2. Напишете функцията size_t my_strlen(char *s), 
    която връща дължината на стринга подаден в нея. */

#include <stdio.h>

size_t my_strlen(char *str) {
    size_t szOfString = 0;
    while (str[szOfString]) {
        szOfString++;
    }
    return szOfString;
}

int main() {
    char myString[] = "What a lovely day!";

    printf("%d", my_strlen(myString));
    
    return 0;
}
