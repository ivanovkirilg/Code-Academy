/*  Упражнение 3.* Добавете проверка във функцията int atof(char *s) 
    дали подаденият стринг няма показни позиции преди числото и, 
    ако има, ги премахнете. Проверете дали числото не е отрицателно и, 
    ако е така, включете знака в резултата. */

#include <stdio.h>

double atof(char *str);

int main() {
    
    printf("%lf", atof("ab cd -12345.54321"));
    
    return 0;
}

double atof(char *str) {
    int i = 0, j, mostSignChar, sign = 1;
    double result = 0, power = 1;

    /* count positions that aren't digits */
    while (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0') i++;
    mostSignChar = i; /* this is the first digit */

    /* check if there's a negative sign */
    if (str[i-1] == '-') sign = -1;

    /* count the digits before decimal point */
    while (str[i] >= '0' && str[i] <= '9') i++;
    j = i-1; /* this is the last digit before decimal */

    /* iterate from 10^0 to the most significant digit */
    while (j >= mostSignChar) {
        result += (str[j] % '0') * power;
        power *= 10;
        j--;
    }
    /* if there is a decimal part, go to it */
    if (str[i] == '.' || str[i] == ',') i++;
    else return (result * sign); /* if there is an unexpected symbol, return number so far */

    /* calculate decimal part */
    power = 0.1;
    while (str[i] != '\0') {
        result += (str[i] % '0') * power;
        power *= 0.1;
        i++;
    }
    return (result * sign);
}