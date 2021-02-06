/*  Задача 8. Напишете функците  atoi, itoa, atof и reverse, 
    които писахме преди като използвате указател вместо индексиране на масив. */

#include <stdio.h>

void reverse(char *str);
void itoa(int n, char *s);
int atoi(char *str);
double atof(char *str);

int main() {
    char string[] = "Hello world!";
    char stringF[] = "512.215";
    int number = 512;
    
    printf("Original:\t%s\n", string);
    reverse(string);
    printf("Reversed:\t%s\n", string);
    itoa(number, string);
    printf("int to string:\t%s\n", string);
    printf("string to int:\t%d\n", atoi(string));
    printf("atof(stringF):\t%lf\n", atof(stringF));

    return 0;
}

void reverse(char *str) {
    if (!*str) return;
    char *strEnd = str;
    char temp;
    while (*++strEnd);
    for (strEnd--; str < strEnd; str++, strEnd--) {
        temp = *str;
        *str = *strEnd;
        *strEnd = temp;
    }
}

int atoi(char *str) {
    char *position = str;
    int result = 0, power = 1;
    
    while (*position >= '0' && *position <= '9') {
        position++;
    }
    position--; /* out of loop, so char at position is not a digit */

    while (position >= str) { /* until we reach the leftmost digit */
        result += (*position % '0') * power;
        power *= 10;
        position--;
    }
    return result;
}

void itoa(int n, char *s) {
    char *sStart = s;
    do {
        *s = (n % 10 + '0');
        n /= 10;
        s++;
    } while (n > 0);
    *s = '\0';
    reverse(sStart);
}

double atof(char *str) {
    char *decimal = str, *integral;
    double result = 0, power = 1;
    
    while (*decimal >= '0' && *decimal <= '9') {
        decimal++;
    }

    integral = decimal - 1;
    while (integral >= str) {
        result += (*integral % '0') * power;
        power *= 10;
        integral--;
    }
    
    if ( !(*decimal == '.' || *decimal == ',') ) {
        return result;
    }
    decimal++;
    power = 0.1;
    while (*decimal != '\0') {
        result += (*decimal % '0') * power;
        power *= 0.1;
        decimal++;
    }
    return result;
}