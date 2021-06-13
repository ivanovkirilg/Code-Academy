#include <stdio.h>

#define USAGE "Usage: %s [seed]\n", argv[0]

long xorshift(long seed);

int main(int argc, char *argv[]) {
    long seed = 0;

    if (argc != 2) {
        printf(USAGE);
        return 1; 
    }

    if (sscanf(argv[1], "%ld", &seed) != 1) {
        printf("%s is not an integer.\n", argv[1]);
        printf(USAGE);
        return 2;
    }

    printf("%ld\n", xorshift(seed));

    return 0;
}

long xorshift(long seed) {
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    
    return seed;
}
