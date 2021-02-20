/*  Задача 8. Направете структура struct rect, която съдържа в себе си две точки. 
    Създайте обект от тип тази структура наречен screen. Използвайте функцията makepoint 
    за да зададете начална точка на екрана (0, 0) и крайна точка (15, 15). 
    Запълнете пространството между тях с тирета. */

#include <stdio.h>

struct tagPoint {
    int x, y;
    char symbol;
};

struct tagRect {
    struct tagPoint start, end;
};

struct tagPoint makepoint(int x, int y);

int main() {
    struct tagRect screen = { makepoint(0,0), makepoint(15,15) };

    for (int y = screen.start.y; y <= screen.end.y; y++) {
        for (int x = screen.start.x; x <= screen.end.x; x++) {
            putchar('-');
            putchar(' ');
        }
        putchar('\n');
    }
    
    return 0;
}

struct tagPoint makepoint(int x, int y) {
    static const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static unsigned char i = 0;
    struct tagPoint point = { x, y, alphabet[i++] };
    if (i > 26) i = 0;
    return point;
}