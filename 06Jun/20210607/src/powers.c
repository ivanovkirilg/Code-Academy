//Разбийте число като сума от степени на двойката.
#include <stdio.h>

#define USAGE_STR "Usage: %s [positive integer]\n"

int main(int argc, char *argv[])
{
    long number = 0;
    int power = 0;

    if (argc != 2) {
        printf(USAGE_STR, argv[0]);
        return 1; 
    }

    if (sscanf(argv[1], "%ld", &number) != 1) {
        printf("%s is not an integer.\n", argv[1]);
        printf(USAGE_STR, argv[0]);
        return 2;
    }

    if (number < 0) {
        printf("%ld is negative.\n", number);
        printf(USAGE_STR, argv[0]);
        return 3;
    }
    
    while (number != 0){

        if (number & 1u) {
            printf("2^%d ", power);
        }

        number >>= 1;
        power++;
    }

    putchar('\n');
    
    return 0;
}
