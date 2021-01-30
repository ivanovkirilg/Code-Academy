/* Задача 6. Напишете програма на С, която чрез функция да обръща десетични числа в двоични. */

#include <stdio.h>

void decToBin(int number);

int main() {
    
    decToBin(1024*1023);
    
    return 0;
}

void decToBin(int number) {
    unsigned int i = 1; /* mask */
    for(i <<= sizeof(int)*8 - 1; i > 0; i >>= 1) { /* go over each bit */
        if (i&number) putchar('1');
        else putchar('0');
    }
}