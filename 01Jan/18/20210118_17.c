/*  Упражнение 17* Направете генератор на случайни числа 
    по следния алгоритъм (xorshift): int A = 1, акумулатор с начална стойност 
    При всяко вземане на число от генератора се прави следното:
    (i) A ^= A << 13; 
    (ii) A ^= A >> 17; 
    (iii) A ^= A << 5;
    При всяка итерация изведете числото на екрана.*/

#include <stdio.h>

void printInBinary();
long long xorshift();

int main() {

    int A = 33;
    printf("\n%d\t", A);
    printInBinary(A,32);
    A ^= A << 13;
    printf("\n%d\t", A);
    printInBinary(A,32);
    A ^= A >> 17;
    printf("\n%d\t", A);
    printInBinary(A,32);
    A ^= A << 5;
    printf("\n%d\t", A);
    printInBinary(A,32);

    long long A1 = 8094123;
    printf("\n%lld ", xorshift(A1));

    return 0;
}

long long xorshift(long long seed) {
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
}
    
void printInBinary(int number, unsigned int bitsToPrint)
{
    unsigned int i = 1;
    for(i <<= bitsToPrint - 1; i > 0; i >>= 1)
    {
        if (i&number) {
            printf("1");
        } else { 
            printf("0");
        }
    }
}