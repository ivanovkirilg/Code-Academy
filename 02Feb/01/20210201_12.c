/*  Задача 12. напишете функцията int any(char s1[], char s2[]), която връща 
    първата позиция в низа s1, където се появява някой от символите в низа s2 */

#include <stdio.h>

int any(char str1[], char str2[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        while (str2[j] != '\0') {
            if (str1[i] == str2[j]) return i;
            j++;
        }
        j = 0;
        i++;
    }
    return -1;
}

int main() {
    char message[] = "hey there, how's the weather?";
    
    printf("%d\n", any(message, "rock")); /* 7 - 'r' */
    
    printf("%d\n", any(message, "low")); /* 12 - 'o' */

    printf("%d\n", any(message, "?',")); /* 9 - ',' */

    printf("%d\n", any(message, "xz")); /* -1 - not found */

    return 0;
}
