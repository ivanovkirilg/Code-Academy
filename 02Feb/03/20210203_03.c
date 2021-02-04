/*  Задача 3. Напишете функцията int linSearch(int a[], int l, int d), 
    която получава като първи аргумент началото на масив а, 
    втория аргумент е дължината на масива, а третия аргумент е числото, което търсим. 
    Претърсете масива елемент по елемент и ако някой елемент съвпада с търсеното число 
    върнете позицията на която се намира този елемент. В противен случай върнете –1. */

#include <stdio.h>

int linSearch(int a[], int l, int d) {
    for (int i = 0; i < l; i++) {
        if (a[i] == d) return i;
    }
    return -1;
}

int main() {
    int iArray[] = {4, 6, 8, 10, 12, 14, 16, 18, 20};
    printf("searching for 16 returns %d\n", linSearch(iArray, sizeof(iArray)/sizeof(int), 16));
    printf("searching for 15 returns %d\n", linSearch(iArray, sizeof(iArray)/sizeof(int), 15));
    return 0;
}
