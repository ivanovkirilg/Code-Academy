/*  Задача 8. Напишете обединение от число и низ, както и описател с изброим тип за съдържанието на обединението. 
    Напишете функция, която получава указател към обединението и изброимия тип и извежда съответно низ или число. */

#include <stdio.h>

enum type { INT, SZ };
union data {
    long long int n;
    char sz[32];
};

void printData(union data *d, enum type *t) {
    switch (*t) {
        case INT:
            printf("%d\n", d->n);
            break;
        case SZ:
            printf("%s\n", d->sz);
            break;
        default:
            printf("Error!\n");
    }
}

int main() {
    enum type myType = INT;
    union data myData = { .n = 25 };

    printData(&myData, &myType);
    
    myType = SZ;
    for (int i = 0; i < 3; i++) {
        myData.sz[i] = 'A' + i;
    };
    printData(&myData, &myType);

    return 0;
}
