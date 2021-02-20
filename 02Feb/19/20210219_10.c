/* Задача 10. Направете два триъгълника с отместване. */

#include <stdio.h>

struct tagPoint {
    int x, y;
    char symbol;
};

struct tagPoint add(struct tagPoint a, struct tagPoint b) {
    struct tagPoint c = { a.x + b.x, a.y + b.y };
    return c;
}

void writeSimpleTriangle(struct tagPoint point, char *array, size_t dimensionSz, char symbol) {
    for (int y = 0; y <= 3; y++ ) {
        for (int x = 0; x <= y; x++) {
            array[(point.y + y) * dimensionSz + point.x + x] = symbol;
        }
    }
}

void printArray2D(char *array, size_t arrSz, size_t dimensionSz);
int writePointToCanvas(struct tagPoint point, char *array, size_t arrSz, size_t dimensionSz);
int writeRectangleToCanvas(struct tagPoint point1, struct tagPoint point2, char *array, size_t dimensionSz, char symbol);

int main() {
    size_t CANVAS_DIMENSION = 15;
    char canvas[CANVAS_DIMENSION][CANVAS_DIMENSION];
    struct tagPoint a = { 3, 4, 'A' }, b = { 4, 4, 'B' };
    struct tagPoint zeroCoord = { 0, 0, '-' }, maxCoord = { CANVAS_DIMENSION, CANVAS_DIMENSION, '-'};

    writeRectangleToCanvas(zeroCoord, maxCoord, (char *) canvas, CANVAS_DIMENSION, zeroCoord.symbol);
    
    writeSimpleTriangle(a, (char *) canvas, CANVAS_DIMENSION, '@');

    struct tagPoint c = add(a, b);

    writeSimpleTriangle(c, (char *) canvas, CANVAS_DIMENSION, '@');

    printArray2D((char *) canvas, sizeof(canvas), CANVAS_DIMENSION);

    return 0;
}

/* Write the symbol inherent to the point, to the canvas */
int writePointToCanvas(struct tagPoint point, char *array, size_t arrSz, size_t dimensionSz) {
    if (point.x < dimensionSz && point.y < dimensionSz) {
        array[point.y*dimensionSz + point.x] = point.symbol;
        return 0;
    } else {
        return point.y*dimensionSz + point.x; /* Coordinates are invalid, return linear position */
    }
}

/* Write rectangle between two points, using specified symbol */
int writeRectangleToCanvas(struct tagPoint point1, struct tagPoint point2, char *array, size_t dimensionSz, char symbol) {
    int lowX, highX, lowY, highY;
    if (point1.x < point2.x) {
        lowX = point1.x;
        highX = point2.x;
    } else {
        lowX = point2.x;
        highX = point1.x;
    }
    if (point1.y < point2.y) {
        lowY = point1.y;
        highY = point2.y;
    } else {
        lowY = point2.y;
        highY = point1.y;
    }
    for (int i = lowY; i <= highY; i++) {
        for (int j = lowX; j <= highX; j++) {
            array[i*dimensionSz + j] = symbol;
        }
    }
}

void printArray2D(char *array, size_t arrSz, size_t dimensionSz) {
    for (int i = 0; i < arrSz/dimensionSz; i++) {
        for (int j = 0; j < dimensionSz; j++) {
            printf("%c ", array[i*dimensionSz + j]);
        }
        printf("\n");
    }
}
