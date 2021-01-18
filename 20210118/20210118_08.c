/*  Упражнение 8*. Напишете функция int isLetter(char c), 
    която проверява дали подадения параметър е буква или 
    не е буква от ASCII таблицата. */

#include <stdio.h>

int isLetter(char c);

int main() {
    char chLetter = 55; // произволен символ
    // тестваме функцията с диапазон от символи
    for ( ; chLetter > 0 ; chLetter += 4) {
        if (isLetter(chLetter)) printf("%c is a letter.\n", chLetter);
        else printf("%c is not a letter.\n", chLetter);
    }
    
    return 0;
}

int isLetter(char c){
    // Буквите в ASCII се намират между 64-91 и между 96-123
    // Използваме условния (тернарен) оператор, за да върнем 
    // или стойността на буквата, 
    // или 0 (което да се използва като "НЕ е буква")
    return ( (c>64 && c<91) || (c>96 && c<123) ) ? c : 0;
}