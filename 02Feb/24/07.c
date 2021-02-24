/* Задача 7. Напишете макрос, който прави идентификатор на низ (стринг) */

#include <stdio.h>
#define STRINGIFY(x) #x

int main() {
    int nValue = 0;
    printf(STRINGIFY(nValue));
    
    return 0;
}
