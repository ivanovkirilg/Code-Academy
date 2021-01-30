/*  Задача 7. Запишете в осем последователни байтове
    в паметта със стойност 0xBB(1011 1011) и разпечатайте 
    съдържанието на горните байтове, ако типът е: 
    double, signed long long, unsigned long long */

#include <stdio.h>

    /* Аналогично на 6-та задача */
int main(void) {
    unsigned long long customValue = 0xBBBBBBBBBBBBBBBBULL;
    printf("Hex value: 0x%X\n", customValue);

    printf("As double: %.45lf\n With cast: %lf\n", * (double *) &customValue, (double) customValue); // STILL a bad idea
    printf("As signed long long: %lld\n With cast: %lld\n", * (signed long long *) &customValue, (signed long long) customValue);
    printf("As unsigned long long: %llu\n With cast: %llu\n", * (unsigned long long *) &customValue, (unsigned long long) customValue);

    return 0;
}