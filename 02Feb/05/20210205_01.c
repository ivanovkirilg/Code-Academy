/*  Задача 1. Напишете функцията void printStr(char *s) аргумент поинтер 
    към началото на стринга. Използвайте for цикъл и обходете стринга 
    докато не стигнете знака за край на стринг '\0'. На ваяка итерация 
    принтирайте всеки един елемент на стринга с printf(“%с”, с). */

#include <stdio.h>

void printString(char *p_string);
void prntstr(char *p_string);
void prstr(char *p_string);

int main() {

    printString("Using printf() and incrementing pointer.\n");
    prntstr("Using increment variable and while.\n");
    prstr("Shortest variant I can come up with.\n");

    return 0;
}

void printString(char *p_string) {
    for ( ; *p_string != '\0'; p_string++ ) {
        printf("%c", *p_string);
    }
}

void prntstr(char *p_string) {
    int i = 0;
    while (putchar(p_string[i++]) != '\0');
}

void prstr(char *p_string) {
/*  for ( ; putchar(*p_string); p_string++ ); */
    while (putchar(*p_string++)); 
}