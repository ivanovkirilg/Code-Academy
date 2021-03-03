#ifndef KILIB_GUARD
#define KILIB_GUARD

void binprint(unsigned long long value, unsigned n_bits);
void binprint_spaced(unsigned long long value, unsigned n_bits);

unsigned msb(unsigned long long number);

int atoi(char *string);
double atof(char *str);

unsigned lensz(char *string);
char *revsz(char string[]);

#endif