/*  Упражнение 10. Напишете функция reverse(s), която обръща символния низ s. 
    Използвайте я, за да напишете програма, която преобръща входа си ред по ред. */

#include <stdio.h>
#include <string.h>

int stringLength(char *p_string);
void reverseString(char *p_string);

int main() {
    char input[256] = "\0";
    char c;
    int i = 0;
    while ( ( c=getchar() ) != EOF ) {
        if (c == '\n') {
            input[i] = '\0';
            reverseString(input);
            printf("%s", input);
            i = 0;
        } else input[i++] = c;
    }
    return 0;
}

void reverseString(char *p_string) {
    for (int i=0, j=stringLength(p_string)-1; i < j; i++, j-- ) {
        char temp = p_string[i];
        p_string[i] = p_string[j];
        p_string[j] = temp;
    }
}

int stringLength(char *p_string) {
    int i = 0;
    for ( ; p_string[i]!='\0'; i++);
    return i;
}