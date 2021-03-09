/*  Задача 4. Прочетете стринг от създадения файл. char *fgets(char * str, int nchars, FILE *stream) 
    първият параметър е стринг, вторият параметър е брой символи, който искаме да прочетем, 
    освен ако не стигне терминиращия символ за край на реда \n или \0 първо, третият е пойнтер към файла; */

#include <stdio.h>
#define FILE_NAME "test.txt"
#define BUFFER_SIZE 128

int main() {
    FILE *fp_text = NULL;
    char textBuffer[BUFFER_SIZE] = "";
    fp_text = fopen(FILE_NAME, "r");
    if (fp_text == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(textBuffer, BUFFER_SIZE, fp_text)) {
        printf("%s", textBuffer);
    }

    fclose(fp_text);
    fp_text = NULL;

    return 0;
}