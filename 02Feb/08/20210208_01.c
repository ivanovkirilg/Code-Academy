/*  Задача 1. Дефинирайте и инициализирайте едномерен масив с 5 елемента. 
    След като сте готови, направете въвеждане на данните в масива, 
    като четете от потребителя със scanf. */

#include <stdio.h>

int main() {
    int array[5] = { 0 };

    for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
        printf("Enter value for element %d: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
