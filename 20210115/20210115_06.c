/*  Задача 6. Запишете в четири последователни байтове в паметта
    със стойност 0xAA(10101010) и разпечатайте съдържанието
    на горните байтове, ако типът е: float, signed int, unsigned int */

#include <stdio.h>

int main(void) {
    int customValue = 0xAAAAAAAA; // 4 поредни байта със стойност 0xAA
    printf("Hex value: 0x%X\n", customValue);

    printf("As float: %.45f\n With cast: %f\n", * (float *) &customValue, (float) customValue); // Bad idea
    printf("As signed int: %d\n With cast: %d\n", * (signed int *) &customValue /* < still bad idea */, (signed int) customValue);
    printf("As unsigned int: %u\n With cast: %u\n", * (unsigned int *) &customValue, (unsigned int) customValue);

    return 0;
}

/* Отговор 6.              - Защо не го преписах:
int main(void){
    float f = 0xAA;        - Тук не записваме 10101010 в паметта, защото компилаторът каства 0xAA (170) към тип float (записва 0x432A0000)
    signed int i = 0xAA;   - Условието казва да запишем стойността в 4 байта, вече използваме 8, на следващия ред - 12
    unsigned a = 0xAAu;
    printf("f = %f, i = %d, a = %d", f, i, a);
    return 0;
} */