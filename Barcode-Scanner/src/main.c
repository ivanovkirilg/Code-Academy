#include "Data.h"
#include <stdio.h>

int main(void) {
    size_t sensorCount;
    float *data = readData(&sensorCount);
    char *binData = binarizeData(sensorCount, data);
    free(data);

    printf("%s\n", binData);

    free(binData);

    return 0;
}
