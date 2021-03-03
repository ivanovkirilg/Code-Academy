/* Задача 6. Напишете структура с потребителски тип  key_t, която съдържа символен низ и число. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char holder[31];
    unsigned char len;
} key_t;

int main() {
    key_t alphabet = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ", strlen(alphabet.holder) };
    
    for (int i = 0; i < alphabet.len; i++) {
        printf("%c ", alphabet.holder[i]);
    }
    putchar('\n');

    /* Generate random 6-letter sequence */
    for (int i = 0; i < 6; i++) {
        putchar( alphabet.holder[rand() % alphabet.len] );
    }

    return 0;
}