/* 6. Напишете функция, която получава указател към масив с числа и връща най-голямото от тях. */

#include <stdio.h>

int maxOfArray(int arr[], int length) {
    --length;
    int max = arr[length];
    while (--length) {
        if (arr[length] > max) {
            max = arr[length];
        }
    }
    return max;
}

int main() {
    int array[] = { 4, 8, 6, 2, 12, 7, 5, 4 };

    printf("%d", maxOfArray(array, sizeof(array)/sizeof(int)));
    
    return 0;
}