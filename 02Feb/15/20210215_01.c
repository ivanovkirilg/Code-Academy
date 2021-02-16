/*  Задача 1. Да напишем функция char *month_name(int n), 
    която връща указател към символен низ, съдържащ името на n-тия месец.  */

#include <stdio.h>

char *getMonthName(unsigned int n);

int main() {
    
    printf("%s", getMonthName(6));

    return 0;
}

char *getMonthName(unsigned int n) {
    static char* months[] = {
        "Illegal month", 
        "January", "February", "March", 
        "April", "May", "June", 
        "July", "August", "September", 
        "October", "November", "December" };

    if (n > 12) {
        return months[0];
    }
    return months[n];
}