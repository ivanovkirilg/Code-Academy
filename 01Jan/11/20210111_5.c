/*  5) Създайте функция, която получава следните параметри - число и индекс.
    Като резултат функцията обръща бита на съответната позиция
    в числото (съответно от 0 на 1 или от 1 на 0). 
*/

#include <stdio.h>

int toggleBitAt(int iNumber, int index);

int main(){

    printf("%d", toggleBitAt(85,2));

    return 0;
}

int toggleBitAt(int iNumber, int index) {
    int mask = 1 << index;
    iNumber = iNumber ^ mask;
    return iNumber;
}
