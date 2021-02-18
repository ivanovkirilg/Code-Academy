/*  Задача 14. Напишете програма, която да проверява дали 2 стринга (масива) 
    са анаграми и имат всичките букви на другата дума. Използвайте функции.
    Примери за анаграми: реклама: карамел; босилек: обелиск. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAnagram(const char str1[], const char str2[]);

int main() {
    char string1[16];
    char string2[16];

    printf("Enter first word: ");
    gets(string1);
    printf("Enter second word: ");
    gets(string2);

    printf("%s and %s %s anagrams", string1, string2, (isAnagram(string1, string2)) ? "are" : "are NOT");
    
    return 0;
}

int isAnagram(const char str1[], const char str2[]) {
    int len1 = strlen(str1);
    if (len1 != strlen(str2)) {
        return 0;
    }
    char *buffer = strdup(str2);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j <= len1; j++) {
            if (j == len1) {
                return 0;
            }
            if (str1[i] == buffer[j]) {
                buffer[j] = 0;
                break;
            }
        }
    }
    free(buffer);
    return 1;
}