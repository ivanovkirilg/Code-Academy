/* 6) Променете стойността на бита на дадено число на определена позиция. */

#include <stdio.h>

int main() {
    int iNumber = 7; // дадено число
    unsigned int position = 3; // определена позиция
    
    iNumber = iNumber ^ 1u << position; // променяме стойността с XOR 

    printf("%d", iNumber);

    return 0;
}
