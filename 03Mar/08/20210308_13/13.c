/* Задача 13. Напишете програма, която да намери общия брой на редовете в текстови файл. */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    /* Counts empty lines as well */
    int lineCount = 1;
    char c = 0;
    while ( (c = fgetc(fp)) != EOF)
        if (c == '\n')
            lineCount++;

    printf("%d lines", lineCount);

    fclose(fp);
    fp = NULL;
    
    return 0;
}