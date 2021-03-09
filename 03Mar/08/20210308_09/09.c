/* Задача 9. Напишете текст с форматиращ параметър. int fprintf(FILE* stream, const char *forma...); */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    fprintf(fp, "Compiled on %s", __DATE__);

    fclose(fp);
    fp = NULL;
    
    return 0;
}