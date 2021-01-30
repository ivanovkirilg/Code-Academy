/* Упражнение 10. Оператори за присвояване */

#include <stdio.h>

void printInBinary(int number, unsigned int bitsToPrint);

int main() {
    int iNumber = 13;
    int iX = 4;

    printf("\nNumber \t\t: %d", iNumber);
    iNumber += iX;
    printf("\nNumber += %d \t: %d", iX, iNumber);
    
    iNumber = 1;
    printf("\nNumber \t\t: %d", iNumber);
    iNumber <<= iX;
    printf("\nNumber <<= %d \t: %d\t", iX, iNumber);
    printInBinary(iNumber,8u);

    iNumber = 30;
    iX = 9;
    printf("\nNumber \t\t: %d\t", iNumber);
    printInBinary(iNumber,8u);
    iNumber &= iX;
    printf("\nNumber &= %d \t: %d\t", iX, iNumber);
    printInBinary(iNumber,8u);
    
    return 0;
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
