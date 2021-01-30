/* Упражнение 11. Increment / decrement operators */

#include <stdio.h>

int main() {
    int iCounter = 0;
    while ( ++ iCounter < 3 ) {
        printf("Counter %d\n", iCounter);
        printf("++ Counter: %d\n", ++ iCounter);
        printf("-- Counter: %d\n", -- iCounter);
        printf("Counter ++: %d\n", iCounter ++);
        printf("Counter --: %d\n", iCounter --);
    }
    /*  Какво става, ако се препълни броячът? 
      - Ако надхърли максималната стойност на signed int, 
        ще стане отрицателно число; ако остане така в края на блока,
        ще седим в цикъла, докато стане отново 3 или повече */
        
    return 0;
}