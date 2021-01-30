/* Упражнение 15. Условен оператор (?:) */

/* Тази задача е идентична на 7-ма */
#include <stdio.h>

int main() {
    int a = 1;
    int b = a == 1 ? 2 : 0;
    printf("a = %d b = %d\n", a, b);
    
    printf("Enter value a: "), scanf("%d", &a);
    printf("Enter value b: "), scanf("%d", &b);

    int max = a>b ? a : b;
    printf("The larger number is %d", max);

    return 0;
}