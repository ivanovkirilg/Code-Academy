/*  2) Създайте функция vzemiBitna. 
    Функцията получава параметър число и индекс. 
    Тя връща стойността на бита на съответния индекс.
*/

#include <stdio.h>

int getBitAt(int iNumber, int index);

int main(){
    
    printf("%d", getBitAt(20,4));

    return 0;
}

int getBitAt(int iNumber, int index) {
    int mask = 1;
    iNumber = iNumber >> index;
    iNumber = iNumber & mask;
    return iNumber;
}
