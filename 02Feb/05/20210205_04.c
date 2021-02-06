/*  Задача 4. Напишете финкцията int our_strcmp(char *s, char *t), 
    която сравнява низовете s и t и връща нула 0 ако двата низа са равни. 
    Ако елемента в който се различават s[i] е по-малък от t[i] 
    връща стойност по-малка от нула < 0. Ako s[i] е по-голям от t[i] 
    връща стойност по-голяма от нула > 0 */

#include <stdio.h>

int my_strcmp(char *s, char *t) {
    while (*s || *t) {
        if (*s == *t) {
            s++, t++;
        } else {
            return (int) (*s - *t);
        }
    }
    return 0;
}

int main() {
    char string1[] = "A whole new compare function!";
    char string2[] = "A whole new world!";
    char string3[] = "A whole new world!";

    printf("%d\n", my_strcmp(string1, string2)); /* 1 and 2 are different, 'c' < 'w' */
    printf("%d\n", my_strcmp(string3, string2)); /* 2 and 3 are identical */
    
    return 0;
}
