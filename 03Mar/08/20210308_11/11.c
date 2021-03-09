/* Задача 11. Направете същото ползвайки fgetpos(). int fgetpos(FILE *pfile, fpos_t *position); */

#include <stdio.h>

int main() {
    FILE *fp = NULL;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    fpos_t secondLinePos;
    char line[32] = "";

    while (fgetc(fp) != '\n');

    fgetpos(fp, &secondLinePos);

    while (fgetc(fp) != '\n');

    fgets(line, 32, fp);
    printf("Line 3: %s", line);

    fsetpos(fp, &secondLinePos);
    fgets(line, 32, fp);
    printf("Line 2: %s", line);

    fclose(fp);
    fp = NULL;
    
    return 0;
}
