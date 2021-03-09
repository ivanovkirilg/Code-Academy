/* Задача 5. Напишете програма, която чете числа от един текстов файл и ги записва в друг текстов файл */

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp_in = NULL;
    FILE *fp_out = NULL;
    
    if (argc != 3) {
        printf("Usage:\n%s [inputfile] [outputfile]\n", argv[0]);
        return 1;
    }

    fp_in = fopen(argv[1], "r");
    fp_out = fopen(argv[2], "w");
    if (fp_in == NULL || fp_out == NULL) {
        printf("File open error.\n");
        return 2;
    }

    do {
        int num = 0;
        fscanf(fp_in, "%d ", &num);
        fprintf(fp_out, "%d ", num);
    } while (!feof(fp_in));

    fclose(fp_in);
    fclose(fp_out);
    fp_out = fp_in = NULL;

    return 0;
}
