/*  Задача 5. Дефинирайте и инициализирайте int променлива = 34 и пойнтер към нея. 
    Опитайте да ги разместите, като поредност (първо да е пойнтерът, после променливата). */

#include <stdio.h>

int main() {
    int iValue = 34;
    int *p_iAddress = &iValue; /* variable needs to be defined before it is used */

    int *p_iSecondAddress; /* pointer can be defined first, but not initialized */
    int iSecondValue = 43;
    p_iSecondAddress = &iSecondValue;

    int iThirdValue; /* variable doesn't need to be initialized, only needs an address */
    int *p_iThirdAddress = &iThirdValue;
    iThirdValue = 42;

    /* Можете ли да умножите пойнтер по пойнтер? */
    /* p_iAddress * p_iSecondAddress; */ /* Error, multiplication of addresses doesn't make sense */
    *p_iThirdAddress = *p_iAddress * *p_iSecondAddress; /* valid, we don't change the addresses stored */

    /* При тази декларация колко пойнтера имаме: */
    int *p, k; /* only *p is a pointer, k is an int */
    int a;
    k = &a; /* Warning, autocasting 'int' to 'int *' */
    /* a = *k; */ /* Error, cannot dereference 'int' */
    
    return 0;
}
