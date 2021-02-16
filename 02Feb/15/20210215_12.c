/*  Задача 12. Напишете програма, която дефинира масив [10][10][10], 
    пълни го със случайни числа и смята средното аритметично, само с един цикъл. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[10][10][10];
    double average = 0;
    
    int *pArr = (int *) arr;
    *pArr = rand(); 
    int i = 1;
    do {
        pArr[i] = rand();
        average = ( (double) pArr[i] + (i-1) * average ) / i;
    } while (++i < sizeof(arr)/sizeof(int));

    printf("%d\n%lf", RAND_MAX, average); /* We expect the average to be around half of max */
    
    return 0;
}
