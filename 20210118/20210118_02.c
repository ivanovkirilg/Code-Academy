/*  Задача 2. какъв ще бъде резултатът в променливата true: 
    int x = 10; int y = 10; int z = 30; int true = x==y+(z < y)!=20; */

#include <stdio.h>

int main() {
    int x = 10; 
    int y = 10;
    int z = 30; 
    int true = x == y + (z<y) != 20;
    //                    0
    //              y +   0        -> 10
    //         x ==(  10    ) 
    //           1            !=20 -> 1

    //      ред на действията:
    //      ( x== (y+(z<y)) )!=20

    printf("true: %d", true); // резултат 1
    
    return 0;
}