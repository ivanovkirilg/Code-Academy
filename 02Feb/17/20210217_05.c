/*  Задача 5. Намерете стойностите в интервала 1-5, включително, 
    в двумерен масив[5][5] пълен със случайни числа в интервала 0-10, включително.
    Използвайте функция, която да пълни числата със случайни. */

#include <stdio.h>
#include <stdlib.h>

void fillArrayWithRand(int *arr, size_t sz, int rangeMax);
unsigned int print2DPosOfValuesWithinRange(int *arr, size_t sz, size_t rowSz, int rangeMin, int rangeMax);

int main() {
    int array[5][5];

    fillArrayWithRand((int *)array, sizeof(array)/sizeof(int), 10);

    int oneToFive = print2DPosOfValuesWithinRange((int *) array, sizeof(array)/sizeof(int), 5, 1, 5);
    printf("\nFound %d numbers 1-5", oneToFive);

    return 0;
}

void fillArrayWithRand(int *arr, size_t sz, int rangeMax) {
    while (sz--) {
        *arr++ = rand() % rangeMax + 1;
    }
}

unsigned int print2DPosOfValuesWithinRange(int *arr, size_t sz, size_t rowSz, int rangeMin, int rangeMax) {
    unsigned int itemsFound = 0;
    for (int i = 0; i < sz; i++, arr++) {
        if (!(i % rowSz)) {
            putchar('\n');
        }
        if (*arr >= rangeMin && *arr <= rangeMax) {
            printf("[%d,%d]==%d  ", i/rowSz, i%rowSz, *arr);
            itemsFound++;
        }
    }
    return itemsFound;
}