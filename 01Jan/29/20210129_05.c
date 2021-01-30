/* Задача 5. Напишете програма на С, която чрез функция проверява дали дадено число е четно или не. */

#include <stdio.h>

int isEven(int number);
int isEvenBitwise(int number);

int main() {
    
    int n = 5;
    printf("Is %d even? %s.", n, (isEvenBitwise(n)) ? "Yes" : "No");
    
    return 0;
}

int isEven(int number) {
    return !(number % 2);
}

int isEvenBitwise(int number) {
    return !(number & 1u); /* Probably faster than modulus division */
}