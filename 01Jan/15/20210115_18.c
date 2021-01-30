/*  Задача 18. Довършете задачата за кемперите от миналия път 
    като добавите променлива, в която да се събират парите, 
    които клиента дължи на компанията. Принтирайте резултата. 
    Питайте клиента дали иска още налични продукти. */

#include <stdio.h>

const float caravanPrice = 90;
const float camperPrice = 100;
unsigned char caravansInStock = 3;
unsigned char campersInStock = 3;

float paymentDue = 0;
float revenue = 0;

void rentCaravan(void);
void rentCamper(void);
void checkout(void);

int main() 
{
    char menuChoice = 0;
    printf("\nWelcome to Caravans and Campervans Co.!\n");
    mainMenu:
    printf("Would you like a caravan (1) or a camper (2)?\n");
    scanf("%d", &menuChoice);

    switch (menuChoice) {
        case 1:
            rentCaravan();
            break;
        case 2:
            rentCamper();
            break;
        default:
            printf("Please enter number 1 or number 2. ");
            goto mainMenu; // Сигурно е добре да се избягват лейбълите, но поне да ги пробвам :)
    }

    printf("\nWould you like anything else (1)\nor to proceed to checkout (2)? ");
    secondaryMenu:
    scanf("%d", &menuChoice);
    switch (menuChoice) {
        case 1:
            goto mainMenu;
            break;
        case 2:
            checkout();
            break;
        default:
            printf("Please enter number 1 or number 2. ");
            goto secondaryMenu;
    }


    return 0;
}

void rentCaravan(void) {
    unsigned int number = 0, days = 0;
    printf("The caravans are %.2flv/day each and we have %d in stock.\nHow many would you like? ", caravanPrice, caravansInStock);
    
    enterNumber:
    scanf("%d", &number);
    if (number < 1 || number > caravansInStock) {
        printf("Please enter a number between 1 and %d. ", caravansInStock);
        goto enterNumber;
    }

    printf("And for how many days? ");

    enterDays:
    scanf("%d", &days);
    if (days < 1 || days > 30) {
        printf("Please enter a number between 1 and 30. ");
        goto enterDays;
    }
    
    float total = number * days * caravanPrice;
    printf("%d caravan(s) for %d day(s) will cost %.2flv\n", number, days, total);
    paymentDue += total;
    caravansInStock -= number;
}

void rentCamper(void) {
    unsigned int number = 0, days = 0;
    printf("The campers are %.2flv/day each and we have %d in stock.\nHow many would you like? ", camperPrice, campersInStock);
    
    enterNumber:
    scanf("%d", &number);
    if (number < 1 || number > campersInStock) {
        printf("Please enter a number between 1 and %d. ", campersInStock);
        goto enterNumber;
    }

    printf("And for how many days? ");

    enterDays:
    scanf("%d", &days);
    if (days < 1 || days > 30) {
        printf("Please enter a number between 1 and 30. ");
        goto enterDays;
    }
    
    float total = number * days * camperPrice;
    printf("%d camper(s) for %d day(s) will cost %.2flv\n", number, days, total);
    paymentDue += total;
    campersInStock -= number;
}

void checkout(void) {
    printf("Your total is %.2f\n", paymentDue);
    revenue += paymentDue;
    paymentDue = 0;
}