/*  Задача 9*. Напишете програма, която пресмята колко символа 
    има в един низ преди края на низа, обозначен със символа ‘\0’. */

#include <stdio.h>

int main() {
    char greeting[] = "duma";

    int i=0;
    for ( ; greeting[i]!='\0'; i++);
    printf("%d\n", i);
    
    return 0;
}