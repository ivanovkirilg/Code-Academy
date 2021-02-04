/* Задача 6. Напишете функция, която изчислява произведението на числата от 1 до 30. */

#include <stdio.h>

/* The product (proizvedenie) of numbers 1-30 is actually 30! (factorial) */
double factorial (int number) {
    double result = number;
    while (--number > 0) {
        result *= number;
    }
    return result;
} 

int main() {
    printf("30! = %e\n", factorial(30));
    printf("Too big for integer type: %lld (overflow)\n", (long long int) factorial(30));
    
    return 0;
}