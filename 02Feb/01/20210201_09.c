/*  Задача 9. Използвайте do-while цикъл, за да напишете функцията 
    void itoa(int n, char s[ ]), която преобразува число в символен низ. */

#include <stdio.h>

void reverseString(char *p_string);
void itoa(int n, char s[]) {
    int i = 0;
    do {
        s[i] = (n % 10 + '0');
        n /= 10;
        i++;
    } while (n > 0);
    s[i] = '\0'; /* makes it work on non-empty string */
    reverseString(s);
}

int main() {
    int iNumber = 278032;
    char cNumberString[16] = "";

    itoa(iNumber, cNumberString);
    printf("%s\n", cNumberString);
    
    itoa(0, cNumberString);
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