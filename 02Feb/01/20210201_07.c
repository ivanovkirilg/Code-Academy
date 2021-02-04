/* Задача 7. Напишете функция, която прави същото, както в задача 6, но е рекурсивна. */

#include <stdio.h>

/* The product (proizvedenie) of numbers 1-30 is actually 30! (factorial) */
double factorial (double number) {
    if (number > 1) {
        return number * factorial(number - 1);
    } else {
        return number;
    }
} 

int main() {
    printf("30! = %e\n", factorial(30));
    printf("Too big for integer type: %lld (overflow)\n", (long long int) factorial(30));
    
    return 0;
}
