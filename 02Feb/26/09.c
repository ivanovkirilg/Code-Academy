/*  Задача 9. Изведете резултата от деленето на две цели числа 
    от тип int като double с преобразуване и без такова */

#include <stdio.h>

int main() {
    double x;

    x = 5/3;
    printf("%lf\n", x);
    x = (double) (5/3);
    printf("%lf\n", x);
    x = (double) 5 / 3;
    printf("%lf\n", x);

    int i = -5;
    unsigned u = i;
    i = (signed) u;
    printf("%d\n", i); /* Negative again */

    return 0;
}