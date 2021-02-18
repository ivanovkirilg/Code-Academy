/*  Задача 12. Напишете програма, която да генерира парола с малки букви (i), 
    специални символи (j), големи букви (k) и цифри (l), ама разбъркано. Използвайте функции.  */

/*  Това решение използва масив от пойнтери към функции, за да ги упражня,
    но не е ефикасно приложение на техниката, защото 4-те функции могат да са една.
    В следващата задача ще приложа това опростяване. Има и други подобрения. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPES_OF_CHAR_FOR_PASS 4
char *generatePassword(char *container);
unsigned int userMenu(unsigned int lengths[], const char** options);
void insertLowercase(char *pass, unsigned int n, unsigned int passLength);
void insertUppercase(char *pass, unsigned int n, unsigned int passLength);
void insertSpecial(char *pass, unsigned int n, unsigned int passLength);
void insertDigits(char *pass, unsigned int n, unsigned int passLength);

int main() {
    char *password = NULL;

    password = generatePassword(password);
    
    printf("%s", password);
    free(password);
    
    return 0;
}

char *generatePassword(char *container) {
    static const void (*p_insertCharsFunctions[TYPES_OF_CHAR_FOR_PASS]) (char *, unsigned int, unsigned int) = {
        &insertLowercase, &insertUppercase, &insertSpecial, &insertDigits };
    static const char *p_stringsForOptions[TYPES_OF_CHAR_FOR_PASS] = {
        "lowercase letters", "uppercase letters", "special characters", "digits" };
    unsigned int lengths[TYPES_OF_CHAR_FOR_PASS] = { 0 };
    unsigned int totalLength = userMenu(lengths, p_stringsForOptions);
    
    container = calloc(totalLength + 1, sizeof(char));
    if (container == NULL) {
        printf("Memory error");
        return container;
    }

    for (int i = 0; i < TYPES_OF_CHAR_FOR_PASS; i++) {
        p_insertCharsFunctions[i](container, lengths[i], totalLength);
    }

    return container;
}

unsigned int userMenu(unsigned int lengths[], const char** options) {
    unsigned int total = 0;
    for (int i = 0; i < TYPES_OF_CHAR_FOR_PASS; i++) {
        fflush(stdin);
        printf("Enter number of %s for your password: ", options[i]);
        scanf("%u", &lengths[i]);
        total += lengths[i];
    }
    return total;
}

void insertLowercase(char *pass, unsigned int n, unsigned int passLength) {
    const char key[] = "abcdefghijklmnopqrstuvwxyz";
    while (n) {
        int i = rand() % passLength;
        if (!pass[i]) {
            pass[i] = key[rand() % strlen(key)];
            n--;
        }
    }
}

void insertUppercase(char *pass, unsigned int n, unsigned int passLength){
    const char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (n) {
        int i = rand() % passLength;
        if (!pass[i]) {
            pass[i] = key[rand() % strlen(key)];
            n--;
        }
    }
}

void insertSpecial(char *pass, unsigned int n, unsigned int passLength){
    const char key[] = { '@', '#', '$', '%', '!', '^', '&', '*', '\0' };
    while (n) {
        int i = rand() % passLength;
        if (!pass[i]) {
            pass[i] = key[rand() % strlen(key)];
            n--;
        }
    }
}

void insertDigits(char *pass, unsigned int n, unsigned int passLength){
    const char key[] = "0123456789";
    while (n) {
        int i = rand() % passLength;
        if (!pass[i]) {
            pass[i] = key[rand() % strlen(key)];
            n--;
        }
    }
}