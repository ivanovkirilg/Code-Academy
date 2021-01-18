/* Упражнение 12. Relational operators */

#include <stdio.h>

int main() {
    int iA = 0;
    int iB = 0;

    printf("Enter first number: ");
    scanf("%d", &iA);
    printf("Enter second number: ");
    scanf("%d", &iB);

    if (iA == iB) {
        printf("%d and %d are equal.\n", iA, iB);
    } else {
        printf("%d and %d are not equal.\n", iA, iB);
        if (iA > iB) {
            printf("%d is larger than %d.\n", iA, iB);
        } else {
            printf("%d is larger than %d.\n", iB, iA);
        }
    }
    if (iA < 0) {
        printf("%d is a negative number.\n", iA);
        if (iB <= -1) printf("And so is %d!\n", iB);
    } else if (-1 >= iB) printf("%d is a negative number.\n", iB);

    return 0;
}