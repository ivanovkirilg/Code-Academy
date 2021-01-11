/* 12) Вдигнете всички битове на число, на позиции делящи се на 3. */

#include <stdio.h>

int main() {
    int iNumber = 2;
    unsigned int mask = 011111111111; // 001 001 001 001 001 001 001 001 001 001 001: позиции 0,3,6,9 ... 30

    iNumber = iNumber | mask;
    printf("%d", iNumber);

    return 0;
}
