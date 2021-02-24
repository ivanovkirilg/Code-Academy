/* Задача 4. Напишете макрос с променлив брой параметри, който извиква printf със префикс “TRACE: ” */

#include <stdio.h>
#define MY_PRINT(...) printf("TRACE: " __VA_ARGS__)

int main() {
    MY_PRINT("%s", "What is the point of this?");
    
    return 0;
}