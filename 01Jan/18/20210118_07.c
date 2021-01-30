/*  Задача 7: Условен оператор (?:) 
    а) въведете стойност за nA с scanf
    b) използвайте условния оператор за намиране на максималното от две числа
*/

#include <stdio.h>

int main() {
    int a = 1;
    int b = a == 1 ? 2 : 0;
    printf("a = %d b = %d\n", a, b);
    
    printf("Enter value a: "), scanf("%d", &a);
    printf("Enter value b: "), scanf("%d", &b);

    int iMax = a>b ? a : b;
    char chMax = a>b ? 'a' : 'b';
    printf("The larger number is %c = %d", chMax, iMax);

    return 0;
}