/*  Задача 1. Декларирайте три масива с три елемента: 
    Първият от тип char, Вторият от тип int, Третият от тип double
    Отпечатайте размерите на масивите използвайки оператора sizeof(arr); 
    Задача 1.2 принтирайте последния елемент от декларираните по горе масиви. */

#include <stdio.h>

/* Прецених, че това е идеална употреба за макро, затова прочетох достатъчно да напиша следното: */
#define last_elem(array)  array[sizeof(array)/sizeof(array[0])-1]
/* Това ни дава последния елемент на кой да е масив - от какъвто и да е тип, с какъвто и да е размер */
/* Не може да бъде функция, защото тя може да приеме само един определен тип */

int main() {
    char arrChar[3] = {'a', 'b', 'c'};
    int arrInt[3] = {1, 2, 3};
    double arrDouble[3] = {0.1, 0.2, 0.3};
    
    printf("Size of 3-element char array:\t%d\n", sizeof(arrChar));
    printf("Size of 3-element int array:\t%d\n", sizeof(arrInt));
    printf("Size of 3-element double array:\t%d\n", sizeof(arrDouble));

    printf("Last element of char array:\t%c\n", last_elem(arrChar));
    printf("Last element of int array:\t%d\n", last_elem(arrInt));
    printf("Last element of double array:\t%lf\n", last_elem(arrDouble));
    
    char arrInt1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("Last element of int array1:\t%d\n", last_elem(arrInt1));

    return 0;
}