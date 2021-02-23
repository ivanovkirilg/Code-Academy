/*  Задача 11. Направете обединение с елементи тип int, int, char. Дайте стойност на елементите 
    един по един -7, 10 и 'c' и изведете тези стойности на конзолата. */

/*  Не разбрах идеята */

#include <stdio.h>

union wabadabadubdub {
    int waba;
    int daba;
    char dub;
};

int main() {
    union wabadabadubdub wbd;
    wbd.waba = -7;
    printf("%d\n", wbd.waba);
    wbd.daba = 10;
    printf("%d\n", wbd.daba);
    wbd.dub = 'c';
    printf("%c\n", wbd.dub);
    
    wbd.waba = -7;
    wbd.daba = 10;
    wbd.dub = 'c';
    printf("%d\n", wbd.waba);
    printf("%d\n", wbd.daba);
    printf("%c\n", wbd.dub);

    return 0;
}
