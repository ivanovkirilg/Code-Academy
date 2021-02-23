/*  Задача 13. Направете обединение с членове unsigned short и char. 
    Ограничете използваните битове до 6. Инициализирайте и изведете на конзолата. */

#include <stdio.h>

union small {
    char c: 6;
    unsigned short h: 6;
};

int main() {
    union small uni = { 60 };

    printf("%d %c\nsize: %d", uni.h, uni.c, sizeof(uni));
    
    return 0;
}
