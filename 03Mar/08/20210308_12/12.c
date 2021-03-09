/*  Задача 12. Изместете позицията си във файла 7 байта след началото, ползвайки fseek.
    int fseek(FILE *pfile, long offset, int original); */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    fseek(fp, 7L, SEEK_SET);

    /* Positions start at 0 */
    printf("Eighth letter of the alphabet: %c", fgetc(fp));

    fclose(fp);
    fp = NULL;
    
    return 0;
}