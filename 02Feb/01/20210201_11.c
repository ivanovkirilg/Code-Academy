/* Задача 11. Напишете функция void squeeze(char s[], int c), която премахва символа с от низа s[] */

#include <stdio.h>

/* "abacd"
.3  bcd    */

void squeeze(char s[], int c) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        if (s[j] == c) j++;
        s[i] = s[j];
        i++, j++;
    }
}

int main() {
    char string[] = "Hey there, how are you?";
    squeeze(string, 'e');
    printf("%s", string);
    
    return 0;
}
