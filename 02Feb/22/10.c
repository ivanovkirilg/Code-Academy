/*  Задача 10. Използвайки горните две задачи като база, обединете обединението и описателя 
    в една структура. Напишете функция, която извежда съдържанието на новата структура. */


#include <stdio.h>
#include <stdlib.h>

enum type { INT, SZ };
union data {
    long long int n;
    char sz[32];
};
struct dataOfType {
    enum type type;
    union data data;
};

void printData(struct dataOfType *dt) {
    switch (dt->type) {
        case INT:
            printf("Int: %d\n", dt->data.n);
            break;
        case SZ:
            printf("Str: %s\n", dt->data.sz);
            break;
        default:
            printf("Error!\n");
    }
}

void toggleData(struct dataOfType *dt) {
    switch (dt->type) {
        case INT:
            dt->type = SZ;
            itoa(dt->data.n, dt->data.sz, 10);
            break;
        case SZ:
            dt->type = INT;
            dt->data.n = atoi(dt->data.sz);
            break;
        default:
            printf("Error!\n");
    }
}

int main() {
    struct dataOfType myData = { .type = INT, .data.n = 35 };

    printData(&myData);

    toggleData(&myData);
    
    printData(&myData);

    toggleData(&myData);

    printData(&myData);
    
    return 0;
}
