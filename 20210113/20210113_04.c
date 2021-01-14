/* Упражнение 4: съберете 10 - 127 */

#include <stdio.h>

void printInBinary(int number, unsigned int bitsToPrint);

int main() 
{
    char a = 10;
    char b = -127;
    char c = a + b;

    printf("%d + %d = %d\n", a, b, c); // в рамките на типа сме, няма проблем
    printInBinary(a,8);
    printInBinary(b,8);
    printInBinary(c,8);

    return 0;
}


void printInBinary(int number, unsigned int bitsToPrint)
{
    unsigned int i = 1;
    for(i <<= bitsToPrint - 1; i > 0; i >>= 1)
    {
        if (i&number) { // поради някаква причина, не работи правилно с условие (i&number != 0) ????
            printf("1");
        } else { 
            printf("0");
        }
    }
    printf("\n");
}
