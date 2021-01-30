/*  2. Да съберем пак две числа от тип char 255 + 10, 
    да използваме функцията за представяне на числата в двоичен вид. */

#include <stdio.h>

void printInBinary(int number, unsigned int bitsToPrint);

int main() 
{
    char a = 255;
    unsigned char a1 = 255;
    unsigned char b = 10;
    unsigned char c = a + b; // това ни интересува

    printf("a:  %d\t: ", a);
    printInBinary(a,8);
    printf("a1: %d\t: ", a1);
    printInBinary(a1,8);
    printf("b:  %d\t: ", b);
    printInBinary(b,8);

    printf("  c = a + b\n");
    printf("c:  %d\t: ", c); // тук виждаме резултата
    printInBinary(c,8);      // а тук - в битове

    return 0;
}

// моята функция взема като параметър колко бита искаме да видим
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
