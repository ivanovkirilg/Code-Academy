/*  Задача 1. Напишете функция, която принтира низ, пойнтера към началото му 
    е подаден като аргумент на функцията void printstr(char *s); */

#include <stdio.h>

void printString(char *p_str);
void prntstr(char *p_str);

int main() {
    char string[] = "hey there";
    char *p_string = string; /* because string is an array, this is the same a &string[0] */

    printString(p_string); /* calling with pointer variable */
    putchar('\n');
    prntstr(string); /* passing array variable is equivalent to passing a pointer to the first element */
    
    return 0;
}

void printString(char *p_str) {
    int i = 0; /* position to print */
    while (p_str[i] != '\0') { /* check if end of string */
        putchar(p_str[i]); /* print character at current position */
        i++; /* next position */
    }
}

/* Alternate Version in One Line */
void prntstr(char *p_str) {
    for (int i = 0; putchar(p_str[i++]) != '\0'; );
}