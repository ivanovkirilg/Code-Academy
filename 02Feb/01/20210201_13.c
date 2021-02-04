/*  Задача 13. напишете функцията void lower(char s[]), която преобразува главните букви в малки. */

#include <stdio.h>

void lower(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= 'A' - 'a';
        }
        i++;
    }
}

int main() {
    char message[] = "Hello World!";
    lower(message);
    printf("%s", message);

    return 0;
}
