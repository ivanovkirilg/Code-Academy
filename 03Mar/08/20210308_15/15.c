/*  Задача 15. Напишете програма, която печата съдържанието на файл в обратен ред.
    Използвайте fseek(), за да отидете накрая на файла. Използвайте ftell(), 
    за да намерите позицията на пойнтера. Покажете на екран файла, обърнат в обратен ред. */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    while (ftell(fp) > 0) {
        fseek(fp, -1L, SEEK_CUR);
        putchar( ungetc(fgetc(fp), fp) );
    }

    fclose(fp);
    fp = NULL;
    
    return 0;
}