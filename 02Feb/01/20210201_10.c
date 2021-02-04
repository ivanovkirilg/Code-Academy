/*  Задача 10.  Напишете функция void itob(int n, char s[], int b), 
    която преобразува цяло число n в низ s базиран на основа b. */

#include <stdio.h>

int stringLength(char *p_string);
void reverseString(char *p_string);

void itob(unsigned int num, char str[], unsigned int base) {
    int i = 0;
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    /* if base is too large for available digits */
    if (base > stringLength(digits)) {
        str[0] = 'e', str[1] = str[2] = 'r', str[3] = '\0';
        return;
    }
    
    do {
        str[i] = digits[num % base];
        num /= base;
        i++;
    } while (num > 0);

    str[i] = '\0';
    reverseString(str);
}

int main() {
    int iNumber = 278439;
    char cNumberString[16] = "";

    itob(iNumber, cNumberString, 16);
    printf("%s\n", cNumberString);
    
    itob(iNumber, cNumberString, 32);
    printf("%s\n", cNumberString);
    
    itob(iNumber, cNumberString, 50); /* base too large, 'err' result */
    printf("%s\n", cNumberString);

    return 0;
}

int stringLength(char *p_string) {
    int i = 0;
    for ( ; p_string[i]!='\0'; i++);
    return i;
}

void reverseString(char *p_string) {
    for (int i=0, j=stringLength(p_string)-1; i < j; i++, j-- ) {
        char temp = p_string[i];
        p_string[i] = p_string[j];
        p_string[j] = temp;
    }
}