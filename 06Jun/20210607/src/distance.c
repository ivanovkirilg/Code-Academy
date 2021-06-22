/*Напишете функция, която изчислява разстоянието между две
точки в равнината. Нека функцията да приема два параметъра, които са
структури ТPoint с два члена X и Y координати*/

#include <stdio.h>
#include <math.h>

#define USAGE "Usage: %s [x1] [x2] [y1] [y2]\n", argv[0]

typedef struct {
    int x;
    int y;
} Point;

float distance(Point first, Point second);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf(USAGE);
        return 1;
    }
    
    float coords[4];
    for (int i = 1; i < 5; i++) {
        if (sscanf(argv[i], "%f", &coords[i - 1]) != 1) {
            printf("Arguments must be numbers. Received %s.\n", argv[i]);
            return 2;
        }
    }
    
    Point a = {coords[0], coords[1]};
    Point b = {coords[2], coords[3]};

    printf("%.2f\n", distance(a,b));

    return 0;
}

float distance(Point first, Point second) {
    float length = second.x - first.x;
    float height = second.y - first.y;

    return sqrt(pow(length, 2) + pow(height, 2));
}
