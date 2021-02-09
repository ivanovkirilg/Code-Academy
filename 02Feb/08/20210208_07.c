/*  7. Напишете един глобален масив, който съдържа на всяка позиция броя на дните от месеца. 
    Направете функция, която на която се подават като аргументи година, месец и ден. 
    На база на това функцията трябва да върне поредния ден от годината. 
    Например 1 март е 60 тия ден от годината. */

#include <stdio.h>

const int g_daysInMonth[][12] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, /* non-leap year */
                                  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} }; /* leap year */

int consecutiveDayOfYear(int day, int month, int year) {
    char fl_leapYear = ( !(year%400) || ( !(year%4) && (year%100) ) ) ? 1 : 0;
    int result = day;
    for (int i = 0; i < month-1; i++) {
        result += g_daysInMonth[fl_leapYear][i];
    }
    return result;
}

int main() {
    printf("%d", consecutiveDayOfYear(1, 3, 2021));
    
    return 0;
}
