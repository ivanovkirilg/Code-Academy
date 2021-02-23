/*  Задача 3. Дефинирайте структура с три елемента, които са променливи тип int, char и float.
    Елементите да са наименование на продукт, цена и количество.Задайте стойност на всеки от елементите, 
    както следва: chocolate, 2.50, 50. Отпечатайте на екрана. */

#include <stdio.h>

struct product {
    char name[64];
    float price;
    int amount;
};

int main() {
    struct product chocolate = { "chocolate", 2.5, 50 };
    printf("Product name: %s\nPrice: %.2f\nAmount: %d\n-----\nTotal: %.2f\n", 
        chocolate.name, chocolate.price, chocolate.amount, chocolate.price * chocolate.amount);
    
    return 0;
}
