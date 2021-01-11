/*  3) Създайте функция iz4istiBitna. 
    Тя получава като параметър число и индекс,
    и прави на нула бита на съответния индекс в числото.
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
