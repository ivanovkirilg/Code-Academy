/* Задача 8. Решете задачата за генериране на 6 буквена парола с пойнтери. */

#include <stdio.h>
#include <stdlib.h>

void generatePassword(char *string, char *lastChar);

int main() {
    char pass[7] = "";
    
    char input;
    do {
        generatePassword(pass, &pass[5]);
        
        printf("Enter Y to accept the password: %s\n", pass);
        fflush(stdin);
        scanf("%c", &input);
    } while (input != 'y' && input != 'Y');

    return 0;
}

void generatePassword(char *string, char *lastChar) {
    while (string <= lastChar) {
        *string++ = rand() % 26 + 'a';
    }
}
