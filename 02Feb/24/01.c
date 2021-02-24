/*  Задача 1. Реализирайте условна компилация в зависимост от макрос DEBUG 
    (дефиниране на макрос през компилатора: gcc -DDEBUG) */

#include <stdio.h>

void debugMessage(const char *msg) {
#ifdef DEBUG
    printf("DEBUG: %s\n", msg);
#endif
}

int main() {
    debugMessage("Tralala");
    
    return 0;
}