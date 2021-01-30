/* Задача 2. Пребройте редовете, подадени чрез текст на конзолата. */

#include <stdio.h>

int main() {
    char c;
    int lineCount = 0;
    while ( ( c=getchar() ) != EOF ) {
        if (c == '\n') lineCount++;
    }
    printf("%d lines.", lineCount);
    return 0;
}