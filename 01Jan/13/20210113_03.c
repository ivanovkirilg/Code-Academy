/*  3. Съберете signed char a = -10 с unsigned char z = 0 тип. */

#include <stdio.h>

void printInBinary(int number, unsigned int bitsToPrint);

int main() 
{
    signed char a = -10;
    unsigned char z = 0;
    
    char b = a+z;           // лоша практика (макар и с правилен резултат)
    printf("%d\n", b);

    unsigned char c = a+z;  // грешен резултат, защото типът не може да съдържа правилния
    printf("%d\n", c);

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
