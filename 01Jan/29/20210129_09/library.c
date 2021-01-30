#include <stdio.h>

void askUserForIntegerInput(int *number) {
    printf("Please enter a whole number: ");
    scanf("%d", number);
    fflush(stdin);
    return;
}

double foodOrderMenu(char *foodType, double price) {
    int amount;
    double bill;
    printf("How many %s would you like?\n", foodType);
    askUserForIntegerInput(&amount);
    printf("That will be %.2lf please\n", bill = (double) amount * price);
    return bill;
}

void chooseFoodMenu(void) {
    char choice = 0;
    do {
        printf("For icecream enter 1\nFor muffins enter 2\nFor waffles enter 3\n");
        choice = getchar();
        switch (choice)
        {
            case '1':
                foodOrderMenu("icecreams", 0.9);
                break;
            case '2':
                foodOrderMenu("muffins", 0.75);
                break;
            case '3':
                foodOrderMenu("waffles", 1.8);
                break;
            default:
                choice = 0;
                break;
        }
    } while (!choice);
}