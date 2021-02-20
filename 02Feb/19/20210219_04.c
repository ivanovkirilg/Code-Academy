/* Задача 4. Подравняване и пакетиране на структури */

#include <stdio.h>

struct tagTestA {
    char m_ch;
    short int m_si;
};
struct tagTestAP {
    char m_ch;
    short int m_si;
} __attribute__((packed));

struct tagTestB {
    char m_ch;
    int m_i;
};
struct tagTestBP {
    char m_ch;
    int m_i;
} __attribute__((packed));

int main() {
    printf("sizeof(A) = %d, sizeof(A-packed) = %d\n", 
        sizeof(struct tagTestA), sizeof(struct tagTestAP));
    printf("sizeof(B) = %d, sizeof(B-packed) = %d\n", 
        sizeof(struct tagTestB), sizeof(struct tagTestBP));

    /* I want to see where the padding is */
    struct tagTestA paddingTest = { .m_ch = 0xAA, .m_si = 0xAAAA };
    char *pTest = (char *) &paddingTest;
    for (int i = 0; i < sizeof(paddingTest); i++) {
        printf("Byte value: %d\n", pTest[i]);
    }
    /* Result on my machine: | -86 |  0  | -86 | -86 | */
    /*                       |char | ??? | short int | */
    
    /* Padding placed to accommodate largest type? */
    
    return 0;
}