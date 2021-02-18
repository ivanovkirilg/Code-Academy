/*  Задача 8. Напишете програма, която да представя Реда на Фибоначи в масив. 
    Ред на Фибоначи: Всяко число е равно на сумата на двете преди него. Първите 2 са 0 и 1.  */

#include <stdio.h>

int main() {
    unsigned int fib[16] = { 0, 1 };
    
    for (int i = 2; i < sizeof(fib)/sizeof(unsigned int); i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    for (int i = 0; i < sizeof(fib)/sizeof(unsigned int); i++) {
        printf("%d ", fib[i]);
    }

    return 0;
}
