/* *
 * Напишете функция void itob(int n, char s[], int b), 
 * която преобразува цяло число n в низ s базиран на основа b. 
 * Например itob( n, s[], 16) представя числото n като шестнадесетично число в стринга s[].
 * */

#include <stdio.h>
#include <string.h>

void itob(int n,char s[],int b);
void reverseString(char *p_string); /* Alternative to library function */               /* I'll explain my choices/changes here: */

int main() {
    int number; /* Convert this number */                                               /* Variables have more meaningful names */
    int base;   /* into this base */

    char string[64]=""; /* Converted number goes here */


    printf("Enter a whole number: ");                                                   /* User input menu is from the original */
    scanf("%d", &number);                                                               /* But check if number<0 is moved into the function */
	
	do {    /* Make sure 'base' is initialized */
		printf("\nEnter a base for conversion (between 2 and 64): ");
		scanf("%d", &base);
	} while (base < 2 || base > 64); /* Loop to validate user input */


    itob(number, string, base); /* <--- Convert number */

    /* Print result */                                                                  /* Print section now only prints */
    printf("\n%d (10) -> %s (%d)", number, string, base);                               /* In original there were different operations */

    return 0;
}

void itob(int n,char s[],int b){                                                        /* Function works like the first review version */
    int digitIndex = 0; /* which character are we using for the current digit? */       /* Again, better variable names */
    int position = 0;
    char digitsContainer[64] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz#$";
    
    char isNegative = 0;                                                                /* This check wasn't in the function before */
    if (n < 0) {
		isNegative = 1;
		n = -n;
	}

    do {                                                                                /* Like previous versions, but easier to read */
        /* the remainder is the digit we need (28%16 = 12 -> 'C') */
        digitIndex = n % b;
        /* set the char in the string to the digit we calculated */
        s[position] = digitsContainer[digitIndex]; 
        
        n /= b;     /* prepare to calculate next digit */
        position++; /* ... for the next position */
    }
    while(n>0);

    if (isNegative) {        /* Add negative sign, */                                   /* Idea for two's complement not implemented */
        s[position++] = '-'; /* and increment for '\0' char */                          /* because it only works for base 2, */
    }                                                                                   /* which makes it inconsistent */
    
    s[position] = '\0';                                                                 /* Previous versions didn't have '\0' */
    strrev(s);                                                                          /* so it was impossible to reuse the string */
    /* Alternative to library function: */                                              /* Reverse also wasn't inside the function before */
    /* reverseString(s); */
}

/* Alternative to library function: */
/* 
void reverseString(char *p_string) {
    for (int i=0, j=strlen(p_string)-1; i < j; i++, j-- ) {
        char temp = p_string[i];
        p_string[i] = p_string[j];
        p_string[j] = temp;
    }
} */