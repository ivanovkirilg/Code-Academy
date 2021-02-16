/*  Задача 11. Напишете програма, която умножава 2 числа, като използва пойнтер-и. 
    Продължение: Опитайте да умножите 2 променливи от различен тип, използвайки пойнтери. */

#include <stdio.h>

int main() {
    int a = 2, b = 5, *pa = &a, *pb = &b, prod = 0;
    prod = *pa * *pb;
    printf("%d\n", prod);
    float f = 5, *pf = &f;
    prod = *pb * *pf;
    printf("%d\n", prod);
    
    return 0;
}
