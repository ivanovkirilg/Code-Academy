/*  Задача 4. Дефинирайте структура "date" с членове ден, месец, година. 
    Създайте променлива към структурата "contractdate". По колко начина можете да я дефинирате?
    Задайте стойност на членовете на структурата по три различни начина. */

#include <stdio.h>

struct date {
    unsigned char day;
    unsigned char month;
    unsigned short year;
};

int main() {                        /*  първи начин            втори начин */
    struct date contractSignedDate = { .day = 21, .month = 12, 2021 };
                                /* (трети начин) */
    struct date contractEndDate = contractSignedDate;
                 /* четвърти начин */
    contractEndDate.year += 2;

    printf("Signed: %d.%d.%d\nEnding: %d.%d.%d", 
        contractSignedDate.day, contractSignedDate.month, contractSignedDate.year,
        contractEndDate.day, contractEndDate.month, contractEndDate.year);
    
    return 0;
}
