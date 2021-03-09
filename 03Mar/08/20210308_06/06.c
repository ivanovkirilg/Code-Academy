/* Задача 6. Отворете и прочетете съдържанието от файл с fscanf. */

#include <stdio.h>
#define FILE_NAME "test.txt"

int main() {
    FILE *fp_in = NULL;

    fp_in = fopen(FILE_NAME, "r");
    if (fp_in == NULL) {
        printf("File open error.\n");
        return 1;
    }

    struct person {
        char firstName[16];
        char lastName[16];
        short age;
        short height;
    } jim;

    fscanf(fp_in, "%s %s %hd %hd", &jim.firstName, &jim.lastName, &jim.age, &jim.height);

    printf("%s %s is %d years old and %dcm tall.\n", jim.firstName, jim.lastName, jim.age, jim.height);

    return 0;
}
