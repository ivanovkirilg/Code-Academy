/*  Задача 9. Използвайте функцията getchar(), с която въвеждате текст от клавиатурата, 
    докато не подадете ЕОF(Ctrl+D). Текстът се принтира с putchar(), 
    като преобразува главните букви в малки. */

#include <stdio.h>

int main() {
    char c;
    while ( (c = getchar()) != EOF) {
        /*                    така получаваме разликата на главна и малка буква, без да търсим ASCII таблица */
        if (c>='A' && c<='Z') c -= 'A'-'a';
        putchar(c);
    }
    return 0;
}