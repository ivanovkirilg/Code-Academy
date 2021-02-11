/*  Задача 2. Напишете програма, която чете съобщение, 
    след което го принтира в обратен ред:
        Enter a message: I am Miro.
        Reversal is : .oriM ma I
    Използвайте getchar() за да вземете символите от конзолата, 
    запазете ги в масив от чарове, прекратете четенето до достигане на \n. 
    Използвайте пойнтер, който да сочи към текущата позиция на масива. 
    Чрез него принтирайте масива в обратен ред. */

#include <stdio.h>

int main() {
    char input[128];
    char *p_pos = input;
    
    printf("Enter a message: ");
    while ((*p_pos++ = getchar()) != '\n');

    p_pos -= 2; /* skip '\n' */

    printf("Reversed message: ");
    while (p_pos >= input) putchar(*p_pos--);
    
    return 0;
}