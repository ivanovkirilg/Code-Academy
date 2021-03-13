/*  Задача 3. Напишете програма за отпечатване на файловете добавени след а.ехе, 
    като започнете всеки на нова страница със заглавие и номере на всяка страница за всеки файл. */

/*  Не написах отделни функции, за да не тръгна да се престаравам.
    Програмата разчита на това, че файловете вече са форматирани на отделни редове.
    За да изписва правилно заглавията, файловете трябва да се подават само с името:
    lorem_ipsum.txt   , а не   .\lorem_ipsum.txt   , но   "spaced title.txt"   работи.*/

#include <stdio.h>
#include <string.h>
#include <Ctype.h>

#define LINE_LEN 64
#define LINES_ON_PAGE 42

int main(int argc, char *argv[]) {
    FILE *fp = NULL;

    /* Print each file */
    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "Couldn't read file %s", argv[i]);
            continue;
        }
        /* Setup Title */
        char title[ strlen(argv[i]) + 1 ];
        int j = 0;
        while ( argv[i][j] != '.' && argv[i][j] != '\0' ) {
            char c = argv[i][j];
            title[j] = (c == '_') ? ' ' : c;
            j++;
        }
        title[j] = '\0';
        title[0] = toupper(title[0]);
        
        /* Print each page */
        unsigned page = 1;
        while (!feof(fp)) {
            /* Page number (and title) */
            if (page == 1) {
                printf("\n%-2d%*s\n", page, LINE_LEN / 2, title);
            } else {
                printf("\n%-2d\n", page);
            }
            char line[LINE_LEN];
            for (int l = 0; l < LINES_ON_PAGE; l++) {
                if (fgets(line, LINE_LEN, fp) != NULL) {
                    printf("%s", line);
                } else {
                    printf("\n");
                }
            }
            page++;
        }
        fclose(fp);
    }

    return 0;
}
