/* Задача 1. Дефиниция и декларация на променлива */

#include <stdio.h>

extern int g_iNumber;

int main() {
    printf("Global integer variable: %d\n", g_iNumber);
    return 0;
}

int g_iNumber = 42;