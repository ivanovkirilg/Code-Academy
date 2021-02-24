/* Задача 8. Напишете функциите като макроси: */
#include <stdio.h>

/* 1. Функция AVG, която смята средното аритметично на две подадени като параметър числа. */
#define AVG(x,y) ((double) x + y)/2

/* 2. Функция AVG, която смята средното аритметично на числата от определен диапазон. */
#define PRINT_AVG_VA(N, ...)  { int arr[N] = { __VA_ARGS__ }; double res = 0;\
                                for (int i = 0; i < N; i++) {\
                                    res += arr[i]; }\
                                res /= N; printf("%lf\n", res); }
/*  Ако се има предвид например средното аритметично на 5-8 (5, 6, 7, 8),
    то това е същото като средното аритметично на 5 и 8, тъй че първата функция е решение.
    Ако се има предвид друго, не разбирам какво. */

/* 3. Напишете функцията повдигане на степен, която повдига х на степен у */
#define POW(x,e) { double res = x; int i = e; while (--i) { res *= x; } x = res; }

/* 4. Напишете функцията TOUPPER, която прави малката буква а в голяма А */
#define TOUPPER(c) c + 'A' - 'a'
#define TOUPPER_STRICT(c) (c >= 'a' && c <= 'z') ? c + 'A' - 'a' : c

int main() {
    printf("%f\n", AVG(20,15));
    PRINT_AVG_VA(4, 10, 11, 14, 15); /* First argument is the number of values to average */

    int iValue = 3;
    POW(iValue, 3);
    printf("%d\n", iValue);
    
    double fValue = 1.5;
    POW(fValue, 3);
    printf("%f\n", fValue);

    printf("%c ", TOUPPER('g'));
    printf("%c ", TOUPPER_STRICT('g'));
    printf("%c ", TOUPPER('2'));
    printf("%c ", TOUPPER_STRICT('2'));
    
    return 0;
}
