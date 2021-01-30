/*  Упражнение 13. Логически оператори */
#include <stdio.h>

int main() {
    int age = 0;
    int height = 0;

    printf("Welcome to the water park!\n");
    printf("How old are you? ");
    scanf("%d", &age);
    printf("How tall are you in cm? ");
    scanf("%d", &height);

    if (age>=18 && height >= 170) {             // &&
        printf("You can go on any slide!\n");
    } else if (age<8 || height < 110) {         // ||
        printf("Unfortunately, you can't use our slides.\n");
    } else if ( age<=18 && !(height<170) ) {    // && !
        printf("You need adult supervision for the red slides.");
    } else if ( height < 170) {
        printf("You can go on any slides except the red ones.");
    }

    return 0;
}