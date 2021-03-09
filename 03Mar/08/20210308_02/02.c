/*  Задача 2. Създайте test.txt файл в избрана от вас директория. 
    Сложете някакви данни в него на латиница - име, поздрав, брой. 
    Отворете файла за редактиране. */

#include <stdio.h>
#include <string.h>

/* Extra function to do something with the file after opening it */
void useFile(FILE *fp);

int main(int argc, char *argv[]) {
    FILE *p_testFile = NULL;
    p_testFile = fopen("test.txt", "r");

    if (p_testFile == NULL) {
        printf("Coudn't open file.\n");
        return 1;
    }

    /* Print a message using the contents of the file */
    useFile(p_testFile);

    fclose(p_testFile);
    p_testFile = NULL;

    if (rename("test.txt", "tested.txt") == 0) {
        printf("File renamed successfully.\n");
    } else {
        printf("File couldn't be renamed.\n");
    }

    /* If the program was called with 'clean' argument, delete the text file */
    if (argc > 1 && strcmp("clean", argv[1]) == 0) {
        remove("tested.txt");
        printf("Cleaned up.");
    }

    return 0;
}

void useFile(FILE *fp) {
    /* new-line-separated strings */
    char greeting[32];
    char name[16];
    char number[8];

    fgets(greeting, 32, fp);
    fgets(name, 16, fp);
    fgets(number, 8, fp);

    /* terminate each string */
    greeting[strlen(greeting)-1] = '\0';
    name[strlen(name)-1] = '\0';
    number[strlen(number)-1] = '\0';

    printf("%s, %s! Your number in line is %s.\n", greeting, name, number);
}