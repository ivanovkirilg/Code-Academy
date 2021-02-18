/*  Задача 11. Напишете програма, която да генерира парола с малки букви (i), 
    специални символи (j), големи букви (k) и цифри (l), ама разбъркано. Използвайте функции.  */

/*  1. Въвежда се дължина на паролата, колко символа от нея са малки букви (a..z), 
    големи букви(A..Z), колко са цифрите (0..9), колко специални символи (@#$%!^&*). 
    2. Използва се генератор на случайни числа за символите и тяхната позиция */

#include <stdio.h>
#include <stdlib.h> /* For memory allocation and rand() */
#include <string.h> /* For strlen() */

/* Change these for different characters in the password */
#define TYPES_OF_CHAR_FOR_PASS 4
#define CHAR_OPTIONS "lowercase letters", "uppercase letters", "special characters", "digits"
#define CHAR_KEYS "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "@#$%!^&*", "0123456789"

char *generatePassword(char *container);

int main() {
    char *password = NULL;

    /* Needs error checking, but main was not my focus */
    password = generatePassword(password);
    printf("%s", password);
    free(password);
    
    return 0;
}

void insertCharsFromKey(char *pass, unsigned int n, unsigned int passLength, const char *key) {
    int pos;
    while (n) {
        /* random position for each new char */
        pos = rand() % passLength;
        if (!pass[pos]) {
            /* if the position is empty, choose random char from the key */
            pass[pos] = key[rand() % strlen(key)];
            /* only decrement if we've written a new char into the password */
            n--;
        }
    }
}

/*  Change this function if the password is to be non-user-defined
    Sets the length of the password, and the number of each type of char */
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

/*  Allocates new memory with each use! 
    Make sure to free it, and not to use on previously allocated memory */
char *generatePassword(char *container) {
    /* The names of the char types, to be printed for the user */
    static const char *p_options[TYPES_OF_CHAR_FOR_PASS] = { CHAR_OPTIONS };
    static const char *p_keys[TYPES_OF_CHAR_FOR_PASS] = { CHAR_KEYS };
    /* How many of each type of char to put into the password */
    unsigned int lengths[TYPES_OF_CHAR_FOR_PASS] = { 0 };
    unsigned int totalLength = userMenu(lengths, p_options);

    if (totalLength == 0) {
        printf("Length is zero");
        return NULL;
    }
    
    container = calloc(totalLength + 1, sizeof(char));
    if (container == NULL) {
        printf("Memory error");
        return NULL;
    }

    for (int i = 0; i < TYPES_OF_CHAR_FOR_PASS; i++) {
        insertCharsFromKey(container, lengths[i], totalLength, p_keys[i]);
    }

    return container;
}