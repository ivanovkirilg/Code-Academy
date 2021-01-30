/* Задача 4. Специални символни литерали */

#include <stdio.h>

int main() {
    char escapeCharacters[] = {'\t', '\n', '\r', '\v', '\\', '\'', '\"', '\?', '\a', '\b', '\f' };

    for ( int i = 0; i < sizeof(escapeCharacters)/sizeof(char); i++ ) {
        printf("Special character: value %d, representation '%c'.\n", (int) escapeCharacters[i], escapeCharacters[i]);
    }

    return 0;
}