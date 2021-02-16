/* Задача 21. Напишете функция, която сортира лексикографски масив от символи използвайки qsort. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* for memcmp(), unused */

int compare(const void *a, const void *b) {
    /* return memcmp(a, b, 1); */
    return (int) ( *(char *)a - *(char *)b );
}

int main() {
    char arr[] = {'c', 'g', 'a', 'd', 'b'};

    qsort((void*) arr, sizeof(arr), 1, compare);

    for (int i = 0; i < sizeof(arr); i++) {
        printf("%c ", arr[i]);
    }
    
    return 0;
}

