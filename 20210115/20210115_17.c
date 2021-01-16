/*  Задача 17.* Към задача 16 да се добави втора функция,
    която изчислява лицето на елипса по зададени два параметъра ( Пи * A * B) */

#include <stdio.h>
#define PI 3.14159265359

double circleArea(double radius);
double ellipseArea(double axisA, double axisB);

int main() {
    printf("r = %.2f A = %.2f\n", 1.0, circleArea(1.0));
    printf("r = %.2f A = %.2f\n", 1.5, circleArea(1.5));
    printf("r = %.2f A = %.2f\n", 13.0, circleArea(13.0));
    
    printf("An ellipse with a = 4 and b = 3 has a radius of %.2f.", ellipseArea(4,3));
    
    return 0;
}

double circleArea(double radius) {
    return (PI * radius * radius);
}

double ellipseArea(double axisA, double axisB) {
    return (PI * axisA * axisB);
}