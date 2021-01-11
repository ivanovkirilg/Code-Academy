/* 9) Направете на нула битовете в числа, намиращи се на позиции между 3 и 7. */

#include <stdio.h>

int main() {
    int iNumber = 511; // 0001 1111 1111
    unsigned int mask = 0xF8; // 0000 1111 1000

    iNumber = iNumber & ~mask; // result: 0001 0000 0111 (263)

    printf("%d", iNumber);

    return 0;
}
