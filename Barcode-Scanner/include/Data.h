#ifndef DATA_H_
#define DATA_H_

#include <stdlib.h>

float *readData(size_t *sensorCount);
char *binarizeData(size_t sensorCount, const float *data);

#endif /* DATA_H_ */