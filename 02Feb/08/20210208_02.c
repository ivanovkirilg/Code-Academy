/*  Задача 2. Дефинирайте и инициализирайте двумерен масив с по 5 елемента (5 x 5). 
    След като сте готови, направете въвеждане на данните в масива със scanf. */

#include <stdio.h>

int main() {
    int array [5] [5] = { 0 };

    unsigned int x = 0, y = 0;
    while (1) {
        do {
            printf("Enter x coordinate (0-4): ");
            scanf("%d", &x);
        } while( x >= 5 );
        
        do {
            printf("Enter y coordinate (0-4): ");
            scanf("%d", &y);
        } while( y >= 5 );
        
        printf("Enter value: ");
        scanf("%d", &array[x][y]);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d\t", array[j][i]);
            }
            printf("\n");
        }

        printf("Enter any character to continue or 'q' to exit: ");
        scanf(" %c", &x);
        if (x == 'q') break;
    }

    return 0;
}