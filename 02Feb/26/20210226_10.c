/*  Задача 10. Опитайте се да използвате колкото се може
    повече неявни преобразувания на типове в С */

#include <stdio.h>

int main() {
    unsigned char meaningOfLife = -214; /* compiler warning */
    printf("The meaning of life is %d\n", meaningOfLife);
    int num0 = - meaningOfLife;
    unsigned int num1 = num0;
    printf("uchar to int: %d; to uint: %u\n", num0, num1);
    float num2 = num0;
    printf("int to float: %f\n", num2);
    num2 /= 1.65;
    printf("float/1.65: %f\n", num2);
    printf("casting to truncate: %f\n", (float) (int) num2);

    return 0;
}
