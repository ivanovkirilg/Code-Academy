/* Задача 3. Дефинирайте и инициализирайте тримерен масив с по 5 елемента (5 x 5 x 5). */

#include <stdio.h>

int main() {
    int array3d [5] [5] [5] = { { { 00,00,00,00,00 }, { 01,01,01,01,01 }, { 02,02,02,02,02 }, { 03,03,03,03,03 }, { 04,04,04,04,04 } },
                                { { 10,10,10,10,10 }, { 11,11,11,11,11 }, { 12,12,12,12,12 }, { 13,13,13,13,13 }, { 14,14,14,14,14 } },
                                { { 20,20,20,20,20 }, { 21,21,21,21,21 }, { 22,22,22,22,22 }, { 23,23,23,23,23 }, { 24,24,24,24,24 } },
                                { { 30,30,30,30,30 }, { 31,31,31,31,31 }, { 32,32,32,32,32 }, { 33,33,33,33,33 }, { 34,34,34,34,34 } },
                                { { 40,40,40,40,40 }, { 41,41,41,41,41 }, { 42,42,42,42,42 }, { 43,43,43,43,43 }, { 44,44,44,44,44 } } };
                                
    for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    printf("%d\t", array3d[j][i][k]);
                }
                printf("\n");
            }
        }   
    
    return 0;
}
