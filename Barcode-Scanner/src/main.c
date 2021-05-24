#include "LightDataReader.h"
#include "Interpreter.h"

#include <stdio.h>

int main(void) {
    size_t sensorCount;
    float *rawLightData = readLightData(&sensorCount);
    char *binLightData = binarizeLightData(sensorCount, rawLightData);
    free(rawLightData);

    printf("%s", interpretBinLightData(binLightData, sensorCount) ); /* mem leak */

    free(binLightData);

    return 0;
}
