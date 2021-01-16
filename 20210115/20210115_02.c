/* Задача 2. Числови литерали */

#include <stdio.h>

int main() {
    printf("Size of literal default integer: %ld\n", sizeof(3));
    printf("Size of literal I: %ld\n", sizeof(3I)); // Изглежда I не е стандартен спецификатор 
                                                    // и зависи от компилатора (и версията?) дали се разпозава.
                                                    // При мен, MinGW-W64 GCC 8.1.0 го интерпретира като константата i
                                                    // за сложно число, изписва предупреждение и cast-ва 3i в тип double.
    printf("Size of literal U: %ld\n", sizeof(3U));
    printf("Size of literal L: %ld\n", sizeof(3L));
    printf("Size of literal LL: %ld\n", sizeof(3LL));
    printf("Size of literal default float: %ld\n", sizeof(3.1));
    printf("Size of literal F: %ld\n", sizeof(3.1F));
    printf("Size of literal D: %ld\n", sizeof(3.1D)); // Подобна ситуация, интерпретира D като текст; 
                                                      // предупреждава и при компилация го игнорира.
    printf("Size of literal L: %ld\n", sizeof(3.1L));

    return 0;
} 