/*  Задача 1. Да се направи програма, която заделя динамичен масив с брой елементи, 
    зададени от потребителя. За всеки елемент от масива се очаква потребителят 
    да въведе цяло число и след това се изчислява сумата на всички елементи от масива. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int numberOfElements = 0;
    int *pNumbers = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &numberOfElements);

    pNumbers = (int*) malloc(numberOfElements * sizeof(int));

    if (pNumbers == NULL) {
        printf("Allocation error!");
        exit(1);
    }
    long int result = 0;
    int *pCurrentNumber = pNumbers;
    
    while (numberOfElements--) {
        printf("Enter a number: ");
        scanf("%d", pCurrentNumber);
        pCurrentNumber++;
    }

    while (--pCurrentNumber >= pNumbers) {
        result += *pCurrentNumber;
    }

    printf ("%ld", result);

    free(pNumbers);

    return 0;
}