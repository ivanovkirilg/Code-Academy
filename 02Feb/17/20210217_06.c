/* Задача 6. Пребройте буквите 'а' в стринг (може да е число и масив). */

#include <stdio.h>

unsigned int countMatchesInArray(void *array, unsigned long int value, size_t szArr, size_t szElem);

int main() {
    /* works with strings */
    char string[] = "This is a test string that has some As";
    printf("'a' occurs in string %d times\n", countMatchesInArray(string, 'a', sizeof(string), sizeof(char)));

    /* works with ints */
    int iArray[] = { 0, 1, 2, 3, 2, 1, 1 };
    printf("1 occurs in array %d times\n", countMatchesInArray(iArray, 1, sizeof(iArray), sizeof(int)));

    /* works with long ints and negative numbers */
    long int lArray[] = { -2, 5, -2, 5};
    printf("-2 occurs in array %d times\n",countMatchesInArray(lArray, -2, sizeof(lArray), sizeof(long int)));
    
    return 0;
}

unsigned int countMatchesInArray(void *array, unsigned long int value, size_t szArr, size_t szElem) {
    unsigned int matches = 0;
    unsigned long int element;

    do {
        /* shift to keep only the bits of the type we are checking for */
        element = (*(unsigned long int *) array) >> (sizeof(unsigned long) - szElem) * 8;
        
        if (element == value) {
            matches++;
        }
        array += szElem; /* move pointer */
        szArr -= szElem; /* use szArr as decrement variable */
    } while (szArr + szElem); /* need +szElem to check last element */

    return matches;
}
