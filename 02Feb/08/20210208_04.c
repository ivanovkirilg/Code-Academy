/*  Задача 4. Даден е едномерен масив с N елемента (вие изберете стойност на N),
    напишете функция, която изчислява средната стойност на елементите в масива, 
    като я връща като double. */

#include <stdio.h>

double averageOfArray(int arr[], int length) {
    double result = 0;
    for (int i = 0; i < length; i++) {
        result += arr[i];
    }
    result /= length;
    return result;
}

int main() {
    int array[] = { 5, 6, 7, 8, 9, 10 };

    printf("%lf", averageOfArray(array, sizeof(array)/sizeof(int)));
    
    return 0;
}