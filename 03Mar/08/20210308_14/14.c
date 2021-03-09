/*  Задача 14. Напишете програма, която да обръща всички символи в текстов файл, 
    с главни букви запишете резултата в друг временен файл. След това 
    преименувайте новия файл с името на оригиналния файл и изтрийте временното име. 
    Отпечатайте съдържанието на файл на стандартния изход с главни букви. */

#include <stdio.h>
#include <Ctype.h>
#define F_IN "test.txt"
#define F_TEMP "upper.txt"

int main() {
    FILE *fp_in = NULL, *fp_temp = NULL;

    fp_in = fopen(F_IN, "r");
    fp_temp = fopen(F_TEMP, "w");
    if (fp_in == NULL || fp_temp == NULL) {
        printf("File open error.\n");
        return 1;
    }

    while (1) {
        char c = fgetc(fp_in);
        if (feof(fp_in))
            break;
        fputc(toupper(c), fp_temp);
    }

    fclose(fp_in);
    fclose(fp_temp);
    fp_in = fp_temp = NULL;

    remove(F_IN);
    rename(F_TEMP, F_IN);
    
    return 0;
}