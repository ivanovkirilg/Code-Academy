/*  Задача 7. Заделяне на памет с calloc. Заделете динамична памет за масив от елементи, 
    като извикате функцията, която нулира заделената памет. */

#include <stdio.h>
#include <stdlib.h>

void printDynArray(int *pStart, size_t sz);

int main() {
    int *piDynArray = NULL;
    size_t szDynArray = 0;

    printf("Enter number of elements: ");
    scanf("%zu", &szDynArray);

    piDynArray = (int*) calloc(szDynArray, sizeof(int));
    if (piDynArray == NULL) {
        printf("calloc error");
        exit(1);
    }
    printDynArray(piDynArray, szDynArray);

    unsigned int input = 0;
    while (input < szDynArray) {
        printf("Enter element index (0-%d), or any other number to quit. ", szDynArray-1);
        scanf("%u", &input);
        if (input < szDynArray) {
            piDynArray[input]++;
        }
        printDynArray(piDynArray, szDynArray);
    }

    free(piDynArray);
    
    return 0;
}

void printDynArray(int *pStart, size_t sz) {
    while (sz--) {
        printf("%d ", *pStart++);
    }
    printf("\n");
}