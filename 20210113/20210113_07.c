/*  7. Дефинирайте променливи със стойност 
    24 212, -1 357 674, 1 357 674, 
    -1 357 674 000, 3 657 895 000.
    Изведете всяка променлива на екрана със printf() */


#include <stdio.h>

int main() 
{
    short int a = 24212;
    printf("%d\n", a);

    int b = -1357674;
    printf("%d\n", b);

    int c = 1357674; // или unsigned int
    printf("%d\n", c);

    int d = -1357674000;
    printf("%d\n", d);

    unsigned int e = 3657895000;
    printf("%u\n", e);

    return 0;
}
