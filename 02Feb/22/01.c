/* Задача 1. Дефиниране и инициализация на обединение */

#include <stdio.h>

union tagData {
    int m_iValue;
    float m_fValue;
    char m_szText[25];
}/* __attribute__((packed)) */; /* 28 bytes padded, 25 packed */

int main() {
    union tagData myData = { 65 };
    printf("Memory used: %d\n", sizeof(myData));
    printf("iValue: %d, fValue: %.45f, Text: %s\n", myData.m_iValue, myData.m_fValue, myData.m_szText);

    return 0;
}