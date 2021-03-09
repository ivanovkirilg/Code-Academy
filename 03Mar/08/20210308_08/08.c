/* Задача 8. Напишете стринг в текстов файл. int fputs (const char *str, FILE *pfile); */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    fputs("Some text", fp);

    fclose(fp);
    fp = NULL;
    
    return 0;
}
