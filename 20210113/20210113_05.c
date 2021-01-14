#include <stdio.h>

int main() 
{
    char cValue = 'a';
    int iValue = 1;
    short int sValue = 1;
    long long int llValue = 1;
    unsigned long int ulValue = 1;
    float fValue = 0.1;
    double dValue = 0.1;
    long double ldValue = 0.1;

    printf("char: %d\n", sizeof(cValue));
    printf("int: %d\n", sizeof(iValue));
    printf("short: %d\n", sizeof(sValue));
    printf("long long: %d\n", sizeof(llValue));
    printf("unsigned long: %d\n", sizeof(ulValue));
    printf("float: %d\n", sizeof(fValue));
    printf("double: %d\n", sizeof(dValue));
    printf("long double: %d\n", sizeof(ldValue));

    return 0;
}
