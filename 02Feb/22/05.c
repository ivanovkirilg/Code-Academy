/* Задача 5. Направете масив от 10 структури от задача 4. Задайте стойност на 10-те дати, по избор. */

#include <stdio.h>

struct date {
    unsigned char day;
    unsigned char month;
    unsigned short year;
};

int main() {
    struct date dates[10] = {             {  5, 7, 1966 },
        {  6, 2, 1998 }, {  6, 2, 1999 }, { 14, 5, 1996 },
        {  4, 4, 2000 }, { 16, 4, 1991 }, { 18, 6, 1938 },
        { 21, 9, 1992 }, { 19, 3, 1997 }, { 16, 12, 1987 }
    };
    
    return 0;
}
