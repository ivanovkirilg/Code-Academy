/*  Задача 7. Напишете програма на С, която съдържа 2 функции. 
    1. Първата смята лице на правоъгълен триъгълник. 
    2. Втората използва лицето на триъгълника, за да сметне лице на четириъгълник 
       със същите дължини на страните, като раменете на триъгълника.
    Напишете прототипите на функциите най-отгоре, а телата им под мейн функцията */

#include <stdio.h>

float rightAngleTriangleArea(float a, float b);
float rectangleFromTriangleArea(float area);

int main() {
    float triangleSideA = 2.2, triangleSideB = 2.8;
    float triangleArea;
    float rectangleArea;

    triangleArea = rightAngleTriangleArea(triangleSideA, triangleSideB);
    rectangleArea = rectangleFromTriangleArea(triangleArea);

    printf("Area of triangle with sides %.2f and %.2f: %.2f\n", triangleSideA, triangleSideB, triangleArea);
    printf("Area of rectangle: %.2f", rectangleArea);

    return 0;
}

float rightAngleTriangleArea(float a, float b) {
    return (a * b) / 2;
}

float rectangleFromTriangleArea(float area) {
    return area * 2;
}