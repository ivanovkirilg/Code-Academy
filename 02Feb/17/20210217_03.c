/*  Задача.3. Направете масив от указатели към функции. Направете меню,
    с което да питате потребителя коя от горните функции иска да използва:
    събиране, изваждане, умножение и деление. След това попитайте за числата, 
    които да участват в тази операция, и извикайте функцията, която да извърши желаната операция. */

#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
#define ADD_INDEX 0
#define SUB_INDEX 1
#define MULT_INDEX 2
#define DIV_INDEX 3

int main() {
    int (*pfuncCalculator[4]) (int, int) = { &add, &subtract, &multiply, &divide };
    char operation = 0, funcIndex = -1;
    int a = 0, b = 0, result = 0;
    
    menuOperationChoice:
    fflush(stdin);
    printf("Choose operation: (+ - * /): ");
    scanf("%c", &operation);
    /* Is this readable? */
    funcIndex = (operation == '+') ? ADD_INDEX : (operation == '-') ? SUB_INDEX : 
                (operation == '*') ? MULT_INDEX : (operation == '/') ? DIV_INDEX : -1;
    if (funcIndex == -1) {
        goto menuOperationChoice;
    }
    
    menuNumbers:
    fflush(stdin);
    printf("Enter two whole numbers: ");
    scanf("%d %d", &a, &b);
    if (funcIndex == DIV_INDEX && b == 0) {
        printf("Cannot divide by 0!\n");
        goto menuNumbers;
    }

    result = pfuncCalculator[funcIndex](a, b);
    printf("%d %c %d = %d", a, operation, b, result);

    return 0;
}