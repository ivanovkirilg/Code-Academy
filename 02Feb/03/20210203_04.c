/*  Задача 4. Напишете функцията int binarySearch(int a[], int n, int x). 
    Знаем, че масива в който ще търсим елемента е предварително подреден. 
    Сравняваме тъсения елемент с елемента в средата на масива. 
    Ако той е по голям от този в средата търсим елемента от средата до края, 
    ако е по-малък го търсим в частта от началото до средата. 
    Това се повтаря, докато елемента от масива не стане равен с търсения. 
    Тогава връщаме номера на който се намира елемента в масива или -1 ако не се съдържа в масива. */


#include <stdio.h>

int binSearch(int a[], int l, int d) {
    int mid = l/2, low = 0, high = l, i = 0;
    while (i <= l/2) {
        if (a[mid] == d) {
            /* printf("iterations: %d\n", i); - debug code */
            return mid;
        }
        else if (a[mid] > d) {
            high = mid;
            mid = (mid+low)/2;
        }
        else if (a[mid] < d) {
            low = mid;
            mid = (mid + high)/2;
        }
        i++;
    }
    /* printf("iterations: %d\n", i); */
    return -1;
}

int main() {
    int iArray[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int pos = binSearch(iArray, sizeof(iArray)/sizeof(int), 6);
    printf("%d", pos);

    return 0;
}
