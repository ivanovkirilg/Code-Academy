/*  11. Създайте С програма, която калкулира стойността на покупки
    в магазин за хранителни стоки. Клиентът може да закупи 
    различна комбинация от продукти. В магазина има 
    следните налични продукти и цени:
    Домати-4.5 лв.за килограм, Брашно 1.80 лв. за килограм,
    Кисело мляко -0.50 лв. за брой, Сладолед на фунийки 0.60 лв.броя 
    Бонбони 1.50 лв. за килограм, Близалки 0.15 лв. за брой.
    Указания: Помислете какви променливи ще дефинирате?
    Помислете в каква последователност ще изпълнявате действията?
    В момента няма да проверяваме въведените стойности от клиента. */

#include <stdio.h>
#include <math.h> // за trunc() за продуктите, които не са на килограм

void chooseProduct(void);

float tomatoPrice=4.5, flourPrice=1.8, yoghurtPrice=0.5, iceCreamPrice=0.6, candyPrice=1.5, lollipopPrice=0.15;
float tomatoTotal=0, flourTotal=0, yoghurtTotal=0, iceCreamTotal=0, candyTotal=0, lollipopTotal=0; // Сметката поотделно
float total = 0; // Общата сметка

int main() 
{
    chooseProduct();

    // пресмята се общата сметката
    total = (tomatoTotal + flourTotal + yoghurtTotal + iceCreamTotal + candyTotal + lollipopTotal);
    printf("\nTotal: %.2f", total);

    return 0;
}

void chooseProduct(void) 
{
    // клиентът избира продукт
    char menuChoice = 0;
    printf("\nPlease choose the product you'd like to add to your cart, or enter (0) to finish shopping.\n");
    printf("We're offering tomatoes(1), flour(2), yoghurt(3), icecream(4), candy(5), and lollipops(6).\n");
    scanf("%d", &menuChoice);

    float amount = 0;
    switch (menuChoice)
    {
        case 0:
            // когато клиентът е приключил с пазаруването, излизаме от функцията
            return;
        case 1:
            // клиентът избира количество и пресмятаме цената
            // тази част можеше да е втора функция
            printf("The tomatoes are %.2f per kg.\nHow many kgs would you like? ", tomatoPrice);
            scanf("%f", &amount);
            tomatoTotal = amount*tomatoPrice;
            printf("That will be %.2f", tomatoTotal);
            break;
        case 2:
            printf("The flour is %.2f per kg.\nHow many kgs would you like? ", flourPrice);
            scanf("%f", &amount);
            flourTotal = amount*flourPrice;
            printf("That will be %.2f", flourTotal);
            break;
        case 3:
            printf("The yoghurt is %.2f each.\nHow many would you like? ", yoghurtPrice);
            scanf("%f", &amount);
            yoghurtTotal = trunc(amount)*yoghurtPrice; // киселото мляко е на кофички, трябва да е цяло число
            printf("That will be %.2f", yoghurtTotal);
            break;
        case 4:
            printf("The icecream is %.2f each.\nHow many would you like? ", iceCreamPrice);
            scanf("%f", &amount);
            iceCreamTotal = trunc(amount)*iceCreamPrice;
            printf("That will be %.2f", iceCreamTotal);
            break;
        case 5:
            // ако имаше толкова евтини бонбони, щях да ги ям с тонове!
            printf("The candy is %.2f per 100g.\nHow many grams would you like? ", candyPrice/10);
            scanf("%f", &amount);
            candyTotal = amount*candyPrice/1000;
            printf("That will be %.2f", candyTotal);
            break;
        case 6:
            printf("The lollipops are %.2f each.\nHow many would you like? ", lollipopPrice);
            scanf("%f", &amount);
            lollipopTotal = trunc(amount)*lollipopPrice;
            printf("That will be %.2f", lollipopTotal);
            break;
        default:
            // ако клиентът не е въвел валидно число
            printf("Please enter a valid item number or 0.\n");
            chooseProduct();
    }
    // извикваме функцията отново, за да продължим пазаруването
    chooseProduct();
    // ако клиентът е поръчал грешно количество, 
    // може да избере същия продукт отново и да го поправи
}
