/* 1. Дефинирайте константи PI, Е, и други с помощта на макроси. Използвайте ги в кода. */
/* 2. Напишете макрос swap(t, x, y), койти променя местата на двата аргумента от тип t. */

#include <stdio.h>
#define PI 3.14159
#define E 2.71828
#define degToRad(deg) (deg) * PI/180
#define swapType(T,x,y) { T temp = x; \
                          x = y; y = temp; } /* need scope to free temp */
#define swap(x,y) x+=y; y=x-y; x-=y; /* more economical, but prone to overflow with large numbers */

int main() {
    printf("pi: %f\n", PI);
    printf("e:  %f\n", E);
    printf("90 degrees = %.2f radians\n\n", degToRad(90));

    int a = 5, b = 3;
    char c = 'C', d = 'D';
    float f = 1.5, g = 5.1;

    printf("Initial: a=%d, b=%d,\n\t c=%c, d=%c\n\t f=%.2f, g=%.2f\n\n", a, b, c, d, f, g);
    swap(a,b);
    swap(c,d);
    swap(f,g);
    printf("Swapped: a=%d, b=%d\n\t c=%c, d=%c\n\t f=%.2f, g=%.2f\n\n", a, b, c, d, f, g);
    swapType(int, a, b);
    swapType(char, c, d);
    swapType(float, f, g);
    printf("By type: a=%d, b=%d\n\t c=%c, d=%c\n\t f=%.2f, g=%.2f\n\n", a, b, c, d, f, g);
    
    return 0;
}

