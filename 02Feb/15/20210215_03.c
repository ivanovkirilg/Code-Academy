/* Задача 3. Дефинирайте и инициализирайте три пойнтера, тип int, тип float, тип char. */

#include <stdio.h>

int main() {
    char cValue = 'a';
    int iValue = -5;
    float fValue = 0.5;

    char *p_cAddress = &cValue;
    int *p_iAddress = &iValue; 
    float *p_fAddress = &fValue; 
    
    return 0;
}
