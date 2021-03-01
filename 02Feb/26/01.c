/*  Задача 1. Дефинирайте структура като потребителски тип. 
    Инициализирайте членовете на структурата, използвайки новия потребителски тип.
    Отпечатайте. */

#include <stdio.h>
#include <string.h>

typedef struct {
    char text[32];
    int l;
} test_t;

int main() {
    test_t myStruct = { "Lorem ipsum", .l = strlen(myStruct.text) };

    printf("%s\nLength: %d", myStruct.text, myStruct.l);

    return 0;
}