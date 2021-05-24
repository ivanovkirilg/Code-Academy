#ifndef LIGHT_DATA_READER_H_
#define LIGHT_DATA_READER_H_

#include <stdlib.h>

float *readLightData(size_t *sensorCount);
char *binarizeLightData(size_t sensorCount, const float *data);

#endif /* LIGHT_DATA_READER_H_ */
