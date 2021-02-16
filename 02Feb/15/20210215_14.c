/* Задача 14. Решете задачата за генериране на 6 буквена парола с пойнтери. */

/*  Първото ми решение вече използваше пойнтер. 
    Новото може би не е по-добро, затова пипнах и някои други неща:
    - вече не е ограничено до използване само на букви,
    - и използва realloc, за да генерира парола с избрана дължина. */

#include <stdio.h>
#include <stdlib.h>
#define KEY "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define KEY_SIZE 63

void generatePassword(char *string, int length);

int main() {
    char *pass = NULL;
    size_t sz = 0;
    
    char input;
    do {
        printf("Enter password length: ");
        fflush(stdin);
        scanf("%d", &sz);

        pass = realloc(pass, sz);
        if (pass == NULL) {
            printf("memory allocation error");
            exit(1);
        }
        generatePassword(pass, sz-1);
        printf("%s\n", pass);
        
        printf("Enter Y to accept, or any other key to generate again: ");
        fflush(stdin);
        scanf("%c", &input);
    } while (input != 'y' && input != 'Y');
    
    /* do something with pass */
    
    free(pass);
    
    return 0;
}

void generatePassword(char *string, int length) {
    static char key[] = KEY;
    char *start = string;
    while (string - start <= length) {
        *string++ = key[rand() % KEY_SIZE];
    }
    *string = '\0';
}

/* My original solution: */
void generatePasswordOriginal(char *string, int length) {
    while (length--) {
        *string++ = rand() % 26 + 'a';
    }
}