/*  Задача 9. Аритметични оператори 
    homework: examples for '*' и '+', float */

#include <stdio.h>

int main() {
    int iX = 13;
    int iY = 44;
    int iResult = 0;
    float fX = 13.0;
    float fY = 44.0;
    float fResult = 0;
    
    // изваждане
    iResult = iX - iY;
    printf("%d - %d = %d\n", iX, iY, iResult);
    // деление
    iResult = iY / iX;
    printf("%d / %d = %d\n", iX, iY, iResult);
    // остатък
    iResult = iY % iX;
    printf("%d / %d Remainder: %d\n", iX, iY, iResult);

    // умножение
    iResult = iY * iX;
    printf("%d * %d = %d\n", iX, iY, iResult);

    // float деление
    fResult = fX / fY;
    printf("%.0f / %.0f = %.3f\n", fX, fY, fResult);

    return 0;
}