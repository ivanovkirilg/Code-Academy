/*  Задача 1. Напишете програма, която сравнява два файла, 
    като отпечатва първият ред на който се различават и на двата файла. */

#include <stdio.h>
#include <string.h>

void compareFiles(FILE *fp1, FILE *fp2, char* name1, char *name2);

int main() {
    FILE *fp1 = NULL, *fp2 = NULL;
    char fileName1[32], fileName2[32];

    openFileOne:
    printf("Enter first file-name:  ");
    gets(fileName1);
    if ((fp1 = fopen(fileName1, "r")) == NULL) {
        printf("Couldn't open file.\n");
        goto openFileOne; 
    }
    
    openFileTwo:
    printf("Enter second file-name: ");
    gets(fileName2);
    if ((fp2 = fopen(fileName2, "r")) == NULL) {
        printf("Couldn't open file.\n");
        goto openFileTwo;
    }

    compareFiles(fp1, fp2, fileName1, fileName2);

    return 0;
}

void compareFiles(FILE *fp1, FILE *fp2, char* name1, char *name2) {
    char buf1[64], buf2[64];
    unsigned char state = 0;
    size_t line = 1;
    while (line > 0) {
        state |= ( fgets(buf1, 64, fp1) == NULL ) ? 1 : 0;
        state |= ( fgets(buf2, 64, fp2) == NULL ) ? 2 : 0;
        
        switch (state) {
            /* Still reading files, compare lines */
            case 0:
                if (strcmp(buf1, buf2)) {
                    printf("%s (%d): %s", name1, line, buf1);
                    printf("%s (%d): %s", name2, line, buf2);
                    return;
                }
                line++;
                break;
            /* Reached end of file 1, but not file 2 */
            case 1:
                printf("Last line of %s (%d): %s", name1, line-1, buf1);
                printf("%s goes on with (%d): %s", name2, line, buf2);
                return;
            /* Reached end of file 2, but not file 1 */
            case 2:
                printf("Last line of %s (%d): %s", name2, line-1, buf2);
                printf("%s goes on with (%d): %s", name1, line, buf1);
                return;
            /* Reached end of both files */
            case 3:
                printf("Files are identical. Read (%d) lines.\n", line);
                return;
            /* There shouldn't be any other possible states */
            default:
                fprintf(stderr, "ERROR How did we get here?\n");
                return;
        }
    }
    /* We reach this if size_t line overflows. Seems unrealistic */
    fprintf(stderr, "ERROR Files too large. Identical until line (%d)\n", line - 1);
}