/*  8. Да прочетем какво се случва със стойността на променливата x:
    char x = 8;
    x = x -2;
    x= x+ 6;
    x= x – 10 +2;
    Каква ще бъде стойността на x, ако я отпечатаме на екрана след последната калкулация? */

#include <stdio.h>

int main() 
{
    char x = 8;
    x = x - 2; // 8-2=6
    x = x + 6; // 6+6=12
    x = x - 10 + 2; // 12-10+2=4
    
    printf("%d", x);

    return 0;
}
