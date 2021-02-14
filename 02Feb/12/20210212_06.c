/*  Задача 6. Заделете динамично с malloc памет за char* buffer с размер size = 2,
    въвеждайте символи от конзолата с getchar() ги четете, записвайте ги в буфера. 
    Увеличавайте размера на буфера преди да се препълни с realloc().
    Прекъснете цикъла с EOF. Принтирайте буфера и освободете паметта. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char c = 0;
    char *pBuffer = NULL;
    size_t szBuffer = 2;
    size_t szCharsEntered = 0;

    pBuffer = (char*) malloc(szBuffer);
    if (pBuffer == NULL) {
        printf("alloc error");
        exit(1);
    }

    while ((c = getchar()) != EOF) {
        szCharsEntered++;
        if (szCharsEntered >= szBuffer) {
            szBuffer *= 2;
            pBuffer = realloc(pBuffer, szBuffer);
            if (pBuffer == NULL) {
                printf("realloc error");
                exit(1);
            }
        }
        pBuffer[szCharsEntered-1] = c;
    }
    pBuffer[szCharsEntered] = '\0';

    printf("%s", pBuffer);

    free(pBuffer);

    return 0;
}