/* Задача 4. Напишете функция, която връща резултат a*2 + b*c. */

#include <stdio.h>

int magic(int a, int b, int c);

int main() {
    
    printf("Here's a magic number: %d", magic(5,3,2));

    return 0;
}

int magic(int a, int b, int c) {
    return a*2 + b*c;
}