/*  Задача 8. Напишете прототипите на разгледаните досега функции 
    int add(int a, int b) и int incr(int c) във файла f.h, 
    a телата на функциите във файла f.c. и използвайте тези функции във файла m.c,
    където е разписано тялото на функцията main(). */

#include <stdio.h>
#include "f.h"

int main() {
    int iNumberA = 1, iNumberB = 2, iNumberC = 3;

    printf("The sum of %d and %d is %d\n", iNumberA, iNumberB, add(iNumberA, iNumberB));
    
    printf("The initial value of C is %d\n", iNumberC);
    incr(&iNumberC);
    printf("The incremented value of C is %d\n", iNumberC);
    
    return 0;
}
