/* Задача 7. Напишете символ в текстов файл. Int fputc(int ch, FILE *pfile); */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    fputc('A', fp);

    fclose(fp);
    fp = NULL;
    
    return 0;
}
