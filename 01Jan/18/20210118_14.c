/*  Упражнение 14. Comma operator */

#include <stdio.h>

int tripleNumber(int number);

int main() {

    /*           Това е същата задача като 5-та?
    int x = 1, y = 0;
    printf("Initialized as: x=%d, y=%d\n", x, y);

    x = 1+2, 2*3, 3+4;
    y = (7*8, 8+9, 9-4);
    printf("x=%d, y=%d\n", x, y);
    */
    int iX = 2, iY = 2;
    printf("Initial values: x=%d y=%d\n", iX, iY);
    iX = (++iY, iY = tripleNumber(iY), iY - iX);    // инкрементираме y, утрояваме го и накрая присвояваме на x стойността y-x
    printf("New values: x=%d y=%d\n", iX, iY);

    return 0;
}

int tripleNumber(int number) {
    return number * 3;
}