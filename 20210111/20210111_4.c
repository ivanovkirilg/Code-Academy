/*  4) Създайте функция, която получава следните параметри - число и индекс. 
    Функцията трябва да "вдига" бита на съответния индекс в числото 
    (под "вдига" ще разбираме да му присвои стойност 1).
*/

#include <stdio.h>

int setBitAt(int iNumber, int index);

int main(){

    printf("%d", setBitAt(256,2));

    return 0;
}

int setBitAt(int iNumber, int index) {
    int mask = 1 << index;
    iNumber = iNumber | mask;
    return iNumber;
}
