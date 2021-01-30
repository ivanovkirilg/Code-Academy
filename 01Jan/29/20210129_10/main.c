/* Задача 10. Напишете програма на С, която съдържа 3 функции, изнесете прототипите им в отделен .h файл. */

#include <stdio.h>
#include "header.h"

int main() {

    printf("%d\n", lowestCommonDenominator(5,7));

    /* Кастът към float би се извършил автоматично, защото функцията изисква float */
    /* Но кастът към int е задължителен, защото формат-спецификаторът %d не изисква int, а форматира като int */
    printf("abs of neg: float %f\tinteger %d\n", absoluteValue(-5.6), (int) absoluteValue( (float) -4 ));
    printf("abs of pos: float %f\tinteger %d\n", absoluteValue(5.6), (int) absoluteValue( (float) 4 ));

    float x = -15;
    
    printf("%f\n", findSquareRoot(x));
    if (findSquareRoot(x) < 0) {
        printf("%f", findSquareRoot( absoluteValue(x) ));
    }

    return 0;
}
