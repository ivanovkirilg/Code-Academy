/* 7) Занулете всички битове на числата, намиращи се на четна позиция. */

#include <stdio.h>

int main() {
    int iNumber = 15; // 1111
    unsigned int evenMask = 0xAAAAAAAA;

    iNumber = iNumber & evenMask; // 1111 & 1010

    printf("%d", iNumber);

    return 0;
}
