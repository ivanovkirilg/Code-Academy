/* 10) Премахнете всички битове на число след n-тия бит включително. */

#include <stdio.h>

int main() {
    int iNumber = 255;
    int index = 5;

    unsigned int mask = ~(0xFFFFFFFF << index);
    iNumber = iNumber & mask;

    printf("%d", iNumber);

    return 0;
}
