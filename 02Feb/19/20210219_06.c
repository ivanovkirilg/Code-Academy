/* Задача 6. Направете по подобен начин триъгълник */

/* Далеч не е перфектно решение, има доста начини да се счупи */

#include <stdio.h>

struct tagPoint {
    int x, y;
    char symbol;
};

void printArray2D(char *array, size_t arrSz, size_t dimensionSz);
int writePointToCanvas(struct tagPoint point, char *array, size_t arrSz, size_t dimensionSz);
int writeRectangleToCanvas(struct tagPoint point1, struct tagPoint point2, char *array, size_t dimensionSz, char symbol);
int writeTriangleToCanvas(struct tagPoint point1, struct tagPoint point2, char *array, size_t dimensionSz, char symbol);
void waitWithMessage(char *message);

int main() {
    /* For simplicity, validation only works with a square canvas!!! */
    size_t CANVAS_DIMENSION = 15;
    char canvas[CANVAS_DIMENSION][CANVAS_DIMENSION];
    /* Points contain the symbol used to display them */
    struct tagPoint a = { 3, 4, 'A' }, b = { 7, 10, 'B' };
    /* The top-left point and bottom-right point, containing the 'empty' symbol */
    /* Used for clearing the canvas */
    struct tagPoint zeroCoord = { 0, 0, '-' }, maxCoord = { CANVAS_DIMENSION, CANVAS_DIMENSION, '-'};

    /* Initialize canvas to '-' (cannot be done in definition, due to variable size) */
    writeRectangleToCanvas(zeroCoord, maxCoord, (char *) canvas, CANVAS_DIMENSION, zeroCoord.symbol);
    printArray2D((char *) canvas, sizeof(canvas), CANVAS_DIMENSION);
    
    waitWithMessage("Press enter to show two points.");

    /* Write the points from the Task to the canvas and print it */
    writePointToCanvas(a, (char *) canvas, sizeof(canvas), CANVAS_DIMENSION);
    writePointToCanvas(b, (char *) canvas, sizeof(canvas), CANVAS_DIMENSION);
    printArray2D((char *) canvas, sizeof(canvas), CANVAS_DIMENSION);

    waitWithMessage("Press enter to show triangle.");

    /* Draw the triangle between the two points */
    writeTriangleToCanvas(a, b, (char *) canvas, CANVAS_DIMENSION, '@');
    printArray2D((char *) canvas, sizeof(canvas), CANVAS_DIMENSION);

    waitWithMessage("Press enter to clear canvas.");

    /* Clear the canvas, same as initialization with '-' */
    writeRectangleToCanvas(zeroCoord, maxCoord, (char *) canvas, CANVAS_DIMENSION, zeroCoord.symbol);
    printArray2D((char *) canvas, sizeof(canvas), CANVAS_DIMENSION);

    /* Let the user input coordinates for two points */
    /* writePointToCanvas() returns non-zero if the coords are invalid */
    inputA:
    printf("Enter two numbers for x and y. (Less than %d) ", CANVAS_DIMENSION);
    fflush(stdin);
    scanf("%d %d", &a.x, &a.y);
    if ( writePointToCanvas(a, (char *) canvas, sizeof(canvas), CANVAS_DIMENSION) )
        goto inputA;
    printArray2D((char *) canvas, sizeof(canvas), CANVAS_DIMENSION);
    
    inputB:
    printf("Enter two more numbers for x and y. (Less than %d) ", CANVAS_DIMENSION);
    fflush(stdin);
    scanf("%d %d", &b.x, &b.y);
    if ( writePointToCanvas(b, (char *) canvas, sizeof(canvas), CANVAS_DIMENSION) )
        goto inputB;
    writeTriangleToCanvas(a, b, (char *) canvas, CANVAS_DIMENSION, '@');
    printArray2D((char *) canvas, sizeof(canvas), CANVAS_DIMENSION);

    /* Let the user input more points/triangles, if they wish */
    waitWithMessage("Press enter to input again, or EOF to exit.");
    writeRectangleToCanvas(zeroCoord, maxCoord, (char *) canvas, CANVAS_DIMENSION, zeroCoord.symbol);
    goto inputA;

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

int writeTriangleToCanvas(struct tagPoint point1, struct tagPoint point2, char *array, size_t dimensionSz, char symbol) {
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
    float gradient = ((float)highX - lowX) / ((float)highY - lowY);
    for (int y = lowY; y <= highY; y++) {
        int hypotenuseX = gradient * y + 1;
        for (int x = lowX; x < hypotenuseX; x++) {
            array[y*dimensionSz + x] = symbol;
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

void waitWithMessage(char *message) {
    printf("%s\n", message);
    fflush(stdin);
    scanf(".");
}
