/*  Задача 3. Създайте test1.txt файл в избрана от вас директория. 
    Сложете някакви данни в него на латиница - име, поздрав, брой. 
    Отворете за четене. Използвайте fgetc(), която взема само един char от файла. 
    Направете while цикъл, за да изпишете всички символи, проверявайте за край на файл с EOF. 
    Проверявайте дали файловият пойнтер не е NULL, ако е NULL, изпишете грешка. */

#include <stdio.h>

void copyLine(FILE *fp, char dest[]);

int main() {
    FILE *p_file = NULL;
    p_file = fopen("test.txt", "r");
    
    if (p_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    /* Task */
    char temp;
    printf("Data in file:\n");
    while ( (temp = fgetc(p_file)) != EOF) {
        putchar(temp);
    }

    /* Use the data in a more sophisticated way: */

    fseek(p_file, 0L, SEEK_SET);

    char message[64] = "";
    char name[32] = "";
    char flightNumber[8] = "";
    
    copyLine(p_file, message);
    copyLine(p_file, name);
    copyLine(p_file, flightNumber);

    printf("%s, %s, on flight number %s.", message, name, flightNumber);

    fclose(p_file);
    p_file = NULL;

    return 0;
}

void copyLine(FILE *fp, char dest[]) {
    char c = 0;
    int i = 0;
    while ((c = fgetc(fp)) != '\n') {
        dest[i++] = c;
    }
}