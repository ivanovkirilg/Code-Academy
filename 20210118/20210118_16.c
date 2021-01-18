/* Упражнение 16. Оператор за вземане на адрес(&) и дереференция(*) */

#include <stdio.h>

int main() {
    int iA = 20;
    int iB = 42;
    int *pA = NULL;
    pA = &iA;
    printf("Pointer address: %p\n", pA);
    printf("Pointer value: %d\n", *pA);
    pA += 4; // to iB
    printf("New pointer address: %p\n", pA);
    printf("New pointer value: %d\n", *pA);
}