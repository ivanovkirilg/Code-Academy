/*  Задача 4. Заделяне и освобождаване на памет -malloc, free. 
    Заделете динамично памет за масив и попълнете елементите */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *piDynamicArray = NULL;
    size_t dynArrSize = 16 * sizeof(int);
    
    piDynamicArray = (int*) malloc(dynArrSize);
    if (piDynamicArray == NULL) {
        printf("Allocation error");
        exit(1);
    }

    /* random, but why not */
    for (int i = 0; i < dynArrSize / sizeof(int); i++) {
        int pow = 1;
        int num = 0;
        for (int j = i; j; j /= 2) {
            num += j % 2 * pow;
            pow *= 10;
        }
        piDynamicArray[i] = num;
        printf("%d ", piDynamicArray[i]);
    }

    free(piDynamicArray);
    
    return 0;
}
