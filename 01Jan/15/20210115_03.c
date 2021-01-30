/* Задача 3. Литерали */

#include <stdio.h>

int main() {
    printf("Character literals: '%c', '%c', '%c'\n", '\014', '\x62', 'C');
    printf("Integer literals: %d, %d, %lld\n", 42, 0xFFF, 123456789012345ULL);
    printf("Float literals: %f, %lf, %lg, %lg\n", 1.23F, 1234.5678, 123E-12, 123E+28);
    printf("String literals: \"%s\", \"%s\", \"%s\"\n", "Hello", "wo" "rld", "!");

    return 0;
}