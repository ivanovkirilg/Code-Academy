#include "Data.h"
#include "Defines.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static void resolveUncertain(int count, char *from, char value);

float *readData(size_t *sensorCount) {
    if (scanf("%lu", sensorCount) != 1) {
        fprintf(stderr, "Error in %s: Invalid input in scanf()\n", __func__);
        exit(EXIT_FAILURE);
    }

    float *data = (float *) malloc(sizeof(float) * (*sensorCount));
    
    if (data == NULL) {
        fprintf(stderr, "Error in %s: %s\n", __func__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *sensorCount; i++) {
        if (scanf(" %f", data + i) != 1) {
            fprintf(stderr, "Error in %s: Invalid input in scanf()\n", __func__);
            exit(EXIT_FAILURE);
        }
    }

    return data;
}

char *binarizeData(size_t sensorCount, const float *data) {
    #define isWithinUpper(x) (x) > 1.0 - (MARGIN)
    #define isWithinLower(x) (x) < (MARGIN)
    
    char *binData = (char *) malloc(sensorCount + 1);
    if (binData == NULL) {
        fprintf(stderr, "Error in %s: %s\n", __func__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    int uncertainDataCount = 0;
    for (int i = 0; i < sensorCount; i++) {
        if (isWithinUpper(data[i])) {
            binData[i] = '1';
            resolveUncertain(uncertainDataCount, &binData[i-1], '0');
            uncertainDataCount = 0;
        } 
        
        else if (isWithinLower(data[i])) {
            binData[i] = '0';
            resolveUncertain(uncertainDataCount, &binData[i-1], '1');
            uncertainDataCount = 0;
        }
        
        else {
            uncertainDataCount++;
            binData[i] = '#';
        }
    }

    binData[sensorCount] = '\0';

    if (uncertainDataCount > 0) {
        fprintf(stderr, "Warning in %s: Not all data has been interpreted.", __func__);
    }

    return binData;

    #undef isWithinUpper
    #undef isWithinLower
}

static void resolveUncertain(int count, char *from, char value) {
    while (count--) {
        *from = value;
        from--;
    }
}
