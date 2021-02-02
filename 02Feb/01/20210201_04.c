/*  Задача 4. Направете функцията :void copy(char *to, char *from), 
    която копира една последователност от символи в друга. 
    Копирайте символ по символ масива from[] в to[], докато не стигнете 
    знака '\0' терминираща нула – знак за край на стринг.*/

#include <stdio.h>

void copy(char *from, char *to);

int main() {
    char str1[] = "Print this twice";
    char str2[32];
    
    copy(str1,str2);
    printf("%s\n%s", str1, str2);
    
    return 0;
}

void copy(char *from, char *to) {
    int i = 0;
    while (from[i]) {
        to[i] = from[i];
        i++;
    }
    return;
}