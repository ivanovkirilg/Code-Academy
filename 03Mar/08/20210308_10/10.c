/* Задача 10. Намерете позицията си във файла. long ftell(FILE *pfile); */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    while (fgetc(fp) != '\n');

    long nextLinePos = ftell(fp);
    printf("Second line starts at position %d\n", nextLinePos);

    fclose(fp);
    fp = NULL;
    
    return 0;
}
