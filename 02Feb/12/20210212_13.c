/* Задача 13. Функция за степенуване */

#include <stdio.h>

double power(double x, int y);

int main() {
    printf("3^2 = %lf\n", power(3, 2));
    printf("3^(-2) = %lf\n", power(3, -2));
    printf("2^6 = %lf\n", power(2, 6));
    printf("2.2^3 = %lf\n", power(2.2, 3));
    printf("-4^4 = %lf\n", power(-4, 4));
    printf("-4^3 = %lf\n", power(-4, 3));
    
    return 0;
}

double power(double x, int y) {
    if (y == 0)
        return 1.0;
    if (y < 0) {
        x = 1 / x;
        y = -y;
    }
    double result = x;
    while (--y)
        result *= x;
    return result;
}