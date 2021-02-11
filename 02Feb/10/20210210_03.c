/*  Задача 3. Използвайте Задача 1(2?). за да напишете програма, 
    която проверява дали съобщението не е палиндром. Палиндром е съобщение, 
    в което буквите от ляво на дясно са същите като от дясно на ляво. */

#include <stdio.h>

int checkPalindrome(char *p_start, char *p_end);

int main() {
    char input[128];
    char *p_pos = input;

    printf("Enter a message: ");
    while ((*p_pos++ = getchar()) != '\n');

    if (checkPalindrome(input, p_pos - 2)) {
        printf("That's a palindrome!");
    } else {
        printf("Not a palindrome!");
    }
    
    return 0;
}

int checkPalindrome(char *p_start, char *p_end) {
    while (p_start < p_end) {
        /* Convert to lowercase (ignore case) */
        if (*p_start > 'a' && *p_start < 'z') {
            *p_start -= 'a' - 'A';
        }
        if (*p_end > 'a' && *p_end < 'z') {
            *p_end -= 'a' - 'A';
        }

        /* Ignore non-letter characters */
        if (*p_start < 'A' || *p_start > 'Z') {
            p_start++;
            continue;
        }
        if (*p_end < 'A' || *p_end > 'Z') {
            p_end--;
            continue;
        }

        if (*p_start != *p_end) {
            return 0;
        }
        p_start++, p_end--;
    }
    return 1;
}