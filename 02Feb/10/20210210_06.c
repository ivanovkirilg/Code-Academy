/*  Задача 6. Пренапишете функцията int linear_search(const int a[], int n, int key); 
    използайки пойнтер аритметиката без инкрементиращи променливи. */

#include <stdio.h>

int linSearch(int *a, int l, int key) {
    int *pos = a;
    while (l--) {
        if (*pos == key) return (int) (pos - a);
        pos++;
    }
    return -1;
}

int main() {
    int iArray[] = {4, 6, 8, 10, 12, 14, 16, 18, 20};
    printf("searching for 16 returns %d\n", linSearch(iArray, sizeof(iArray)/sizeof(int), 16));
    printf("searching for 15 returns %d\n", linSearch(iArray, sizeof(iArray)/sizeof(int), 15));
    return 0;
}