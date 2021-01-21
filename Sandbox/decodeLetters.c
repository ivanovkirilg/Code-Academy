#include <stdio.h>
                               /* 0123456789012345 */
const char g_c_LOOK_UP_TABLE[] = "ABCDEFGHIJKLMNOP";
void decode(unsigned int num1, unsigned int num2);

int main() {
    decode(0x74BBE34Du,0x88888888u);
    
    return 0;
}

/* 0000 0000 0000 0000 0000 0000 0000 0000 */

void decode(unsigned int num1, unsigned int num2) {
    unsigned int n = num1;
    for (int i = 0 ; i<8 ; num1 <<= 4u, i++) {
        n = num1 >> 28;
        printf("%c ", g_c_LOOK_UP_TABLE[n]);
    }
    for (int i = 0 ; i<8 ; num2 <<= 4u, i++) {
        n = num2 >> 28;
        printf("%c ", g_c_LOOK_UP_TABLE[n]);
    }
}

