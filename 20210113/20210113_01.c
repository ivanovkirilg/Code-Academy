/* Упражнение 1: Съберете char (255 + 10). Какво ще се получи? Защо? */

#include <stdio.h>

int main() 
{
    unsigned char a = 255;
    unsigned char b = 10;

    unsigned char c = a + b;
    printf("%d\n", c); // char типа не е достатъчно голям за число, по-голямо от 255

    printf("%d\n", a+b); // така заобикаляме това ограничение, но не сме запаметили резултата
    
    unsigned int addedChars = a + b;
    printf("%d\n", addedChars); // сега вече резултатът ни се съдържа в променлива

    return 0;
}
