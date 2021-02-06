/*  Задача 7. Напишете функцията strend(s, t), която връща 1, 
    ако низът t се среща в края на низа s и 0 ако това не е изпълнено. */

#include <stdio.h>

int my_strend(char *s, char *t) {
    char *t_first = t;
    while (*s++); /* go to end of first string */
    while (*t++); /* go to end of second string */
    while (t > t_first) { /* only check until the first char of second string */
        if (*--s != *--t) return 0; /* prefix decrement, because we have gone outside the strings */
    }
    return 1;
}

int main() {
    char string1[] = "The end string is: A whole new string!";
    char string2[] = "A whole new string!";
    char string3[] = "A whole new string.";
    char string4[] = "a whole new string!";

    /* true */                                     /* good use of conditional (ternary) operator? */
    printf("String 2 %s at the end of string 1.\n", my_strend(string1, string2) ? "is" : "is NOT"); 
    /* difference in last character */
    printf("String 3 %s at the end of string 1.\n", my_strend(string1, string3) ? "is" : "is NOT"); 
    /* difference in first character of end string */
    printf("String 4 %s at the end of string 1.\n", my_strend(string1, string4) ? "is" : "is NOT");
    
    return 0;
}