/* Задача 5. L-value и R-value */

#include <stdio.h>

int main() {
    int x = 1;
    int y = 1;
    y = x + 1; // 1+1 = 2
    x = 1 + x + y; // 1+1+2 = 4
    y = 2 * x++ * (y = x * 3) + x++ + y--; // what?
    printf("x = %d, y = %d\n", x, y);
 
/*  y = 2 * x++ * (y = x * 3) + x++ + y--;
            x=5    y =5*3= 15   x=6   y=14
        2 * 4   * 15          + 5   + 15 = 140
    
    Нека не пишем такива неща. Това е абсолютно нечетимо. */

/* Тук тествах поотделно */
    int a = 2;
    int b = 3;
    b = a++ - 1;
/*  b = 2 - 1   a++   */
    printf("a %d\nb %d\n", a, b);

    int c = 2;
    int d = 3;
    d = 2 * (d = c) + d;
/*  d = 2 *  2      + 2  */
    printf("c %d\nd %d\n", c, d);
    
    return 0;
}