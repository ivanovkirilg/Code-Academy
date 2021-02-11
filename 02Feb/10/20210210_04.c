/*  Задача 4. Напишете програма, която да генерира 
    случайна парола от 6 букви докато user-а я хареса.
    Вариант 1: може да използвате цикли while/for + стрингове
    Вариант 2: използвайте функция
    Указания: 
    1. Генерирайте парола
    2. Проверете дали потребителя е харесва
    3. Повторете докато потребителя си хареса паролата */

#include <stdio.h>
#include <stdlib.h>

void generatePassword(char *string, int length);

int main() {
    char pass[7] = "";
    
    char input;
    do {
        generatePassword(pass, 6);
        
        printf("Enter Y to accept the password: %s\n", pass);
        fflush(stdin);
        scanf("%c", &input);
    } while (input != 'y' && input != 'Y');


    return 0;
}

void generatePassword(char *string, int length) {
    while (length--) {
        *string++ = rand() % 26 + 'a';
    }
}
