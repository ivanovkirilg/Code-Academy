/*  Задача 16. Имаме 2 сортирани масиви А и В с по 88 елемента.
    Образувайте масив С с 2х88 елемента образуван от смесването на А и В, 
    така че С да съдържа елементите на А и В, но да е подреден и да не се налага 
    да го сортираме отново. Насоки: Проверяваме от кой масив да вземем следващия елемент */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { 
    return ( *(int*)a - *(int*)b );
}

int main() {
    int arrA[88], arrB[88], arrC[88*2];
    
    for (int i = 0; i < 88; i++) {
        arrA[i] = rand();
        arrB[i] = rand();
    }
    qsort(arrA, 88, sizeof(int), compare);
    qsort(arrB, 88, sizeof(int), compare);

    for (int i = 0, a = 0, b = 0; i < sizeof(arrC)/sizeof(int); i++) {
        if (arrA[a] >= arrB[b]) {
            arrC[i] = arrA[a++];
        } else {
            arrC[i] = arrB[b++];
        }
        printf("%d ", arrC[i]);
    }


    return 0;
}
