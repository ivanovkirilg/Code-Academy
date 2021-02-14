/*  Задача 9. Разширяване на заделена памет с realloc. Напишете програма, 
    която пита потребителя колко памет иска и заделя съответния блок памет.
    След това попитайте потребителя за нов размер и използвайте функция, която прави това. */

#include <stdio.h>
#include <stdlib.h>

void printAsType(void *pMemory, size_t szMemory);

int main() {
    void *pMemory = NULL;
    size_t szMemory = 1;

    printf("Input number of bytes to allocate: ");
    scanf("%zu", &szMemory);
    pMemory = malloc(szMemory);
    if (pMemory == NULL) {
        printf("malloc error");
        exit(1);
    }

    while (1) {
        printAsType(pMemory, szMemory);

        printf("Input new size or 0 to exit: ");
        fflush(stdin);
        scanf("%zu", &szMemory);
        if (szMemory == 0) {
            break;
        }
        pMemory = realloc(pMemory, szMemory);
        if (pMemory == NULL) {
            printf("realloc error");
            exit(1);
        }
    }
    
    free(pMemory);

    return 0;
}

void printAsType(void *pMemory, size_t szMemory) {
    char menu = 1;
    while (menu) {
        printf("Input type (c)har, (i)nt or (d)ouble: ");
        fflush(stdin);
        scanf("%c", &menu);
        switch (menu) {
            case 'c':
                printf("%d bytes may hold this many chars:\n", szMemory);
                char *pcMemory = (char*) pMemory;
                for (int i = 0; i < szMemory; i++) {
                    pcMemory[i] = i%26 + 'A';
                    printf("%c ", pcMemory[i]);
                }
                menu = 0;
                break;

            case 'i':
                printf("%d bytes may hold this many ints:\n", szMemory);
                int *piMemory = (int*) pMemory;
                for (int i = 0; i < szMemory/sizeof(int); i++) {
                    piMemory[i] = i + 1;
                    printf("%d ", piMemory[i]);
                }
                menu = 0;
                break;
                
            case 'd':
                printf("%d bytes may hold this many doubles:\n", szMemory);
                double *pdMemory = (double*) pMemory;
                for (int i = 0; i < szMemory/sizeof(double); i++) {
                    pdMemory[i] = (double) (i + 1)/10;
                    printf("%.2lf ", pdMemory[i]);
                }
                menu = 0;
                break;

            default: 
                menu = 1;
        }
        printf("\n");
    }
}