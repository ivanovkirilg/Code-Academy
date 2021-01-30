/*  Задача 16. Да се дефинира константата Пи (3.14159...) 
    и да се напише функция, която изчислява лицето на окръжност
    по даден радиус (Пи * R * R). В main() да се извика 
    горната функция с радиуси 1, 1.5, 13 */

#include <stdio.h>
#define PI 3.14159265359

double circleArea(double radius);

int main() {
    printf("r = %.2f A = %.2f\n", 1.0, circleArea(1.0));
    printf("r = %.2f A = %.2f\n", 1.5, circleArea(1.5));
    printf("r = %.2f A = %.2f\n", 13.0, circleArea(13.0));
    
    return 0;
}

double circleArea(double radius) {
    return (PI * radius * radius);
}