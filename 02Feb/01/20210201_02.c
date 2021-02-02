/*  Задача 2. Напишете функцията int atof(char *s), 
    която преобразува стринг в число с десетична запетая. */

#include <stdio.h>

double atof(char *str);

int main() {
    
    printf("%lf", atof("12345.54321"));
    
    return 0;
}

/* The function is explained in the next task */
double atof(char *str) {
    int i = 0, j;
    double result = 0, power = 1;
    while (str[i] >= '0' && str[i] <= '9') {
        i++;
    }
    j = i-1;
    while (j >= 0) {
        result += (str[j] % '0') * power;
        power *= 10;
        j--;
    }
    if (str[i] == '.' || str[i] == ',') i++;
    power = 0.1;
    while (str[i] != '\0') {
        result += (str[i] % '0') * power;
        power *= 0.1;
        i++;
    }
    return result;
}