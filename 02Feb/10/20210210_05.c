/*  Задача 5. Пренапишете функцията за сумиране елементите на масив 
    използвайки пойнтер аритметика вместо инкрементиращa променливa i */

#include <stdio.h>

int sum_array(const int a[], int n) {
    int sum = 0;
    while (n--) {
        sum += *a++;
    }
    return sum;
}

void sort (int *p_start, int *p_end) {
    int *p_mid = NULL;
    int temp = 0;
    for ( ; p_start < p_end - 1; ++p_start ) {
        for ( p_mid = p_start + 1; p_mid < p_end; ++p_mid ) {
            if ( *p_start > *p_mid ) {
                temp = *p_start;
                *p_start = *p_mid;
                *p_mid = temp;
            }
        }
    }
}


int main() {
    int arr[] = { 4, 2, 5, 1, -10 };
    
    printf("Sum of array: %d\n", sum_array(arr, sizeof(arr)/sizeof(int)));
    
    sort(arr, &arr[sizeof(arr)/sizeof(int)] );

    printf("Sorted array: ");
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}