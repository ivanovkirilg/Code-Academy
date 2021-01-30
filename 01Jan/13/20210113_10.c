/*  10. Представете си, че имате фирма за отдаване на каравани
    и кемпери под наем, за която трябва да разработите софтуер.
    Вие сте малка фирма и имате общо 3 каравани 
    на цена 90 лв. на ден и 3 кемпера на цена 100 лв. на ден.
    Декларирайте променливи за броя на караваните,
    цената на караваните, броя на кемперите и цената им.
    Направете меню, което пита клиента каравана или кемпер ще иска:
    printf("Dobre doshli v Karavani Kempeti pod naem\n");
    printf("Ako zelaete karavana natisnete 1\n");
    printf("Ako zelaete kemper natisnete 2\n");
    Направете една променлива, в която да запишем резултатът от неговия избор. */

#include <stdio.h>

int main() 
{
    unsigned char caravans = 3;
    unsigned char campers = 3;
    float caravanPrice = 90;
    float camperPrice = 100;

    char menuChoice = 0;
    printf("Welcome to Caravans and Campervans Co.!\n");
    printf("Would you like a caravan (1) or a camper (2)?\n");
    scanf("%d", &menuChoice);

    return 0;
}
