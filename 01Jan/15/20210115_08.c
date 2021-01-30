/* Задача 8. Константи и задаване на тяхната стойност */

#include <stdio.h>
const int c_iMEANING_OF_LIFE = 42;
const char c_chMY_FAVOURITE_LETTER = 'M';
const double c_dCHANCE_TO_WIN_LOTTO = 1.0 / 33294800.0;

int main() {
    printf("Why are we here? %d.\n", c_iMEANING_OF_LIFE);
    printf("I really like the sound of %c.\n", c_chMY_FAVOURITE_LETTER);
    printf("If five of us play, we'll have a %.8lf chance of winning the lottery.\n", c_dCHANCE_TO_WIN_LOTTO * 5.0);
    return 0;
}