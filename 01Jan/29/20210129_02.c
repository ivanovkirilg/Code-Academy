/*  Задача 2. Напишете функция area() без параметри. Поискайте от потребителя да въведе радиуса.
    Използвайте горната функция 1. за изчисляване на  площта на кръг, която написахме преди малко 
    за да изчислите площта на кръга с този радиус и върнете резултата. */

#include <stdio.h>

const float PI = 3.14159;

float circleArea(float);
void area(void);

int main() {
    
    area();
    
    return 0;
}

void area(void) {
    float r;
    printf("Enter circle radius: ");
    scanf("%f", &r);
    printf("R = %f\nA = %f", r, circleArea(r));
    return;
}

float circleArea(float radius) {
    return PI * radius * radius;
}