/* Задача 6. Напишете макрос, който свързва (конкатенира) два идентификатора в един общ */

#include <stdio.h>
#define CONC(a,b) a##b

int main() {
    CONC(print,f)("Test.\n");
    
    return 0;
}
