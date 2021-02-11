/* Задача 7. Разгледайте и имплементирайте quicksort алгоритъма. */

/*  Имплементацията ми използва указатели, вместо индекси, 
    за да ги упражня; но може би я прави по-трудно четима. */

#include <stdio.h>
#define array_size(array) sizeof(array)/sizeof(array[0])

void quicksort(int *arrLow, int *arrHigh);

int main() { 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    
    quicksort(arr, &arr[array_size(arr)-1]); 

    printf("Sorted array: \n"); 
    for (int i = 0; i < array_size(arr); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
} 

void swap(int *a, int *b) {
    *b += *a;
    *a = *b - *a;
    *b -= *a;
}

int* partition(int *arrLow, int *arrHigh) {
    int pivot = *arrHigh;
    int *i = arrLow-1;
    for ( ; arrLow < arrHigh; arrLow++) {
        if (*arrLow < pivot) {
            i++;
            swap(i, arrLow);
        }
    }
    swap(i+1, arrHigh);
    return i+1;
}

void quicksort(int *arrLow, int *arrHigh) {
    if (arrLow < arrHigh) {
        int *part = partition(arrLow, arrHigh);

        quicksort(arrLow, part-1);
        quicksort(part+1, arrHigh);
    }
}