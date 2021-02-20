/* Задача 7. Направете функция struct point makepoint(int x, int y), която създава две точки. */

#include <stdio.h>

struct tagPoint {
    int x, y;
    char symbol;
};

struct tagPoint makepoint(int x, int y) {
    static const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static unsigned char i = 0;
    struct tagPoint point = { x, y, alphabet[i++] };
    if (i > 26) i = 0;
    return point;
}

int main() {
    struct tagPoint point0 = makepoint(1, 1);
    struct tagPoint point1 = makepoint(4, 16);

    printf("point0: %c(%d,%d)\n", point0.symbol, point0.x, point0.y);
    printf("point1: %c(%d,%d)\n", point1.symbol, point1.x, point1.y);
    
    return 0;
}
