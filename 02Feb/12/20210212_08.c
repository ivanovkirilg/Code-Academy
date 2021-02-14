/* Задача 8. Заделяне на памет от стека с alloca. Заделете памет в стека (няма нужда от free()) */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p = NULL;
    size_t sz = 1;

    printf("Enter size: ");
    scanf("%zu", &sz);
    p = (char*) alloca(sz);
    if (p == NULL) {
        printf("alloca error");
        exit(1);
    }

    for (unsigned int i = 0; i < sz-1; i++) {
        p[i] = i%26 + 'A';
    }
    p[sz-1] = '\0';

    printf("%s", p);
    
    return 0;
}

