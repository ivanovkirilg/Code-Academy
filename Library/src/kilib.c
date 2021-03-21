#include <stdio.h>
#include <string.h>

void binprint(unsigned long long value, unsigned n_bits) {
    unsigned m = 1u << (n_bits - 1);
    do {
        putchar( (value & m) ? '1' : '0' );
    } while (m >>= 1u);
}

void binprint_spaced(unsigned long long value, unsigned n_bits) {
    union { unsigned char c: 3; } counterToEight = {1};
    unsigned m = 1u << (n_bits - 1);
    do {
        putchar( (value & m) ? '1' : '0' );
        !(counterToEight.c++) ? putchar(' ') : 1 ;
    } while (m >>= 1u);
    putchar('\n');
}

unsigned msb(unsigned long long number) {
    unsigned index = 0;
    while (number) {
        index++;
        number >>= 1u;
    }
    return index;
}

unsigned lensz(const char *string) {
    unsigned i = 0;
    while (string[i]) i++;
    return i;
}

char *revsz(char string[]) {
    for (unsigned i = 0, j = lensz(string) - 1; i < j; i++, j--) {
        string[i] += string[j];
        string[j] = string[i] - string[j];
        string[i] -= string[j];
    }
    return string;
}

int endcmpsz(const char *string, const char *ending) {
    string = strrchr(string, *ending);
    if (string == NULL) {
        return -1;
    }
    return strcmp(string, ending);
}

double atof(char *string) {
    int i = 0, j;
    signed char sign = 1;
    double result = 0, power = 1;
    if (string[i] == '-') {
        sign = -1;
        string++;
    }
    if ( (string[i] > '9' || string[i] < '0') && string[i] != '.' ) {
        return 0;
    }
    
    while (string[i] >= '0' && string[i] <= '9') {
        i++;
    }
    j = (i++) - 1;
    while (j >= 0) {
        result += (string[j] - '0') * power;
        power *= 10;
        j--;
    }

    power = 0.1;
    while (string[i] >= '0' && string[i] <= '9') {
        result += (string[i] - '0') * power;
        power *= 0.1;
        i++;
    }
    return result * sign;
}

int atoi(char *string) {
    int i = 0, power = 1, result = 0;
    signed char sign = 1;
    if (string[i] == '-') {
        sign = -1;
        string++;
    }
    if ( (string[i] > '9' || string[i] < '0') && string[i] != '.' ) {
        return 0;
    }
    while (string[i] >= '0' && string[i] <= '9') {
        i++;
    }
    while (--i >= 0) {
        result += (string[i] - '0') * power;
        power *= 10;
    }
    return result * sign;
}

void drawArray2D(char *array, unsigned rowLen, unsigned columnLen, char *formatString) {
    if (*formatString == '\0') {
        formatString = "%c ";
    }
    for (int i = 0; i < columnLen; i++) {
        for (int j = 0; j < rowLen; j++) {
            printf(formatString, array[i*rowLen + j]);
        }
        printf("\n");
    }
}
