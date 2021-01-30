/*  3) Създайте функция iz4istiBitna. 
    Тя получава като параметър число и индекс,
    и прави на нула бита на съответния индекс в числото.
 */

#include <stdio.h>

int clearBitAt(int iNumber, int index);

int main(){
    
    printf("%d", clearBitAt(255,2));

    return 0;
}

int clearBitAt(int iNumber, int index) {
    int mask = ~ ( 1u << index );
    iNumber = iNumber & mask;
    return iNumber;
}
