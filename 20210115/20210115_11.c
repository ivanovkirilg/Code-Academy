/*  Задача 11. Ако имаме символен низ от символа char str[] = “Hello”;
    копирайте всеки един от неговите символи в низ,
    който да изглежда огледален на него. */

#include <stdio.h>
#include <string.h>

int main()
{
    char myString[] = "hello hello";
    char backwardString[strlen(myString)];
    /* 
    backwardString[0] = myString[3];
    backwardString[1] = myString[2];
    backwardString[2] = myString[1];
    backwardString[3] = myString[0]; */
    
    for (int i=0; myString[i]!='\0'; i++) {
        backwardString[i] = myString[strlen(myString)-i-1];
    }
    backwardString[strlen(myString)] = '\0';
    printf("String: %s\nBackwards: %s", myString, backwardString);

    return 0;
}