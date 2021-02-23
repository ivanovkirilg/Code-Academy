/* Задача 9. Напишете функция, която преобразува число в низ и обратното, като използва описанието от предишната задача. */

#include <stdio.h>
#include <stdlib.h>

enum type { INT, SZ };
union data {
    long long int n;
    char sz[32];
};

void printData(union data *d, enum type *t) {
    switch (*t) {
        case INT:
            printf("Int: %d\n", d->n);
            break;
        case SZ:
            printf("Str: %s\n", d->sz);
            break;
        default:
            printf("Error!\n");
    }
}

void toggleData(union data *d, enum type *t) {
    switch (*t) {
        case INT:
            *t = SZ;
            itoa(d->n, d->sz, 10);
            break;
        case SZ:
            *t = INT;
            d->n = atoi(d->sz);
            break;
        default:
            printf("Error!\n");
    }
}

int main() {
    enum type myType = INT;
    union data myData = { .n = 25 };

    printData(&myData, &myType);

    toggleData(&myData, &myType);
    
    printData(&myData, &myType);

    toggleData(&myData, &myType);

    printData(&myData, &myType);
    
    return 0;
}
