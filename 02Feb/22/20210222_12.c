/*  Задача 12. Напишете програма, която използва битови полета. 
    Битовите полета да са членове на структура и да са от следните типове: 
    unsigned int и char. Задайте им размер short int 3 бита, char 6 бита.  */

#include <stdio.h>

struct bitField {
    unsigned short int h: 3;
    unsigned char c: 6; /* max value is 63! */
};

/*  Дефинирайте променлива на структурата и ги инициализирайте със стойности 7 и 'c'.
    Разпечатайте елементите. Разпечатайте и големината на структурата. */

int main() {
    struct bitField myField = { .h = 7, .c = 'c' }; /* 'c' overflows, compiler warning */
    printf("Int element: %d\tChar element: %c\n", myField.h, myField.c);
    printf("size of field: %d\n", sizeof(myField)); /* 4 bytes */

/*  Добавете още членове от съществуващите типове и разпечатайте големината на структурата отново. 
    Пренаредете ги като последователност, да са char, char, short int, short int. 
    Как се променя големината на структурата? */

#pragma pack(1) /* STILL 4 bytes?? */

    struct bitField1 {
        unsigned char c0: 6;
        unsigned char c1: 6;
        unsigned short h0: 3;
        unsigned short h1: 3;
    };

    struct bitField1 mySecondField = { '!', '.', 4, 5 };
    printf("size of field1: %d\n", sizeof(myField)); /* Still 4 bytes */

    
    return 0;
}
