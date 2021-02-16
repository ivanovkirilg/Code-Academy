/* Задача 19. Дефинирайте стринг: „Baba, kaka, mama” заменете „а“ със „о“ */

#include <stdio.h>

int main() {
    char str[] = "Baba, kaka, mama";
    char *c = str;
    while (*c) {
        if (*c == 'a') *c = 'o';
        c++;
    }
    printf("%s", str);
    
    return 0;
}
