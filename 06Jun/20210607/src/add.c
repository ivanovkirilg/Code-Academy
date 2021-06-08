//Декларирайте функция, която събира две числа и връща резултата им:
#include <stdio.h>
#include <stdlib.h>

float addDigit(float a, float b);

int main (int argc, char* argv[]) {
    if (argc == 3) {
        float result = addDigit(atof(argv[1]), atof(argv[2]));
        printf("%.2f\n", result);
    }
    else {
        printf("Usage: %s [number1] [number2]\n", argv[0]);
    }

    return 0;
}

float addDigit(float a, float b) {
    return a + b;
}
