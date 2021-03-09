/*  Задача 1. Напишете програма, която чете стринг от стандартния вход 
    и го извежда на стандартния изход с функцията gets(szBuf); */

#include <stdio.h>
#include <string.h>
#define BUF_SIZE 128

int main() {
    char inBuffer[BUF_SIZE] = "";

    do {
        printf("Enter text:  ");
        gets(inBuffer);
        
        printf("You entered: ");
        puts(inBuffer);
    } while (strlen(inBuffer));

    return 0;
}