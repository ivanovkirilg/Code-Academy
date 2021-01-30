/* Задача 1. Пребройте символите, подавани на конзолата с функцията getchar(); */


#include <stdio.h>

int main() {
    char c;
    int count = 0;
    while ( ( c=getchar() ) != EOF ) { 
        if (c == '\n') {
            printf("%d\n", count);
            count = 0;
        }
        else count ++;
    }
    return 0;
}

/* Първи опит, не толкова добър: */

// int main() {
//     char c;
//     int count;
//     while ( ( c=getchar() ) != EOF ) { /* С два цикъла програмката ни брои символите на всеки ред, докато подадем EOF */
//         count = 0;
//         ungetc(c, stdin);   /* <---------------- Нужно е, защото на 8-ми ред сме взели символ ... */
//         while ( ( c=getchar() ) != '\n' ) {   /* ... който искаме да вземем отново тук. */
//             count++;
//         }
//         printf("%d\n", count);
//     }
//     return 0;
// }