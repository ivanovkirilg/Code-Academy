/*  6. Дефинирайте променливи със стойност 
    -127, 255, 6 237 498, 4 294 967 292,
    -9 000 000 000 000 775 845.
    Изведете всяка променлива на екрана със printf() */

#include <stdio.h>

int main() 
{
    char a = -127;
    printf("%d\n", a);

    unsigned char b = 255;
    printf("%d\n", b);

    int c = 6237498;
    printf("%d\n", c);

    unsigned int d = 4294967292;
    printf("%u\n", d);

    long long int e = -9000000000000775845;
    printf("%lld\n", e);

    return 0;
}
