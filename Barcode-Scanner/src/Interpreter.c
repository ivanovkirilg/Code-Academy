#include "Interpreter.h"
#include "ErrorChecks.h"
#include "Defines.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool writeMeaningfulBit(char *meaningfulBits, int *position, int *darkBits);

char *interpretBinLightData(const char *binData, size_t sensorCount) {
    char *meaningfulBits = (char *) malloc(sensorCount / 2);
    memAllocationCheck(meaningfulBits, __func__);

    int dark = 0, errors = 0, position = 0;

    for (int i = 0; i < sensorCount; i++) {
        if (binData[i] == '0') {
            dark++;
        }

        else if (binData[i] == '1') {
            bool end = writeMeaningfulBit(meaningfulBits, &position, &dark);
            
            if (end) {
                if (position > CODE_LEN) {
                    break;
                }
                position = 0;
            }
        }

        else {
            fprintf(stderr, "Error in %s: Corrupted binary sensor data.\n", __func__);
        }
    }

    meaningfulBits[position] = '\0';
    
    return meaningfulBits;
}

static bool writeMeaningfulBit(char *meaningfulBits, int *position, int *darkBits) {
    if (*darkBits == 1) {
        meaningfulBits[*position] = '0';
        *darkBits = 0;
        (*position)++;
        return false;
    }
    
    else if (*darkBits == 2) {
        meaningfulBits[*position] = '1';
        *darkBits = 0;
        (*position)++;
        return false;
    }
    
    else {
        return true;
    }
}

