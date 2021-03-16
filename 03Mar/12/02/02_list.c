#include <stdio.h>
#include "kilist.h"

#define N 150000

int main() {
    list primes = lcreate();

    for (long i = 2; i < N; i++) {
        lappend(primes, i);
    }

    for (long long i = 2; i < N; i++) {
        int pos;
        if (pos = lfindindex(primes, i) != -1) {
            for (long long j = i; i * j < N; j++) {
                lremvalue(primes, i * j);
            }
        }
    }
    printf("1 ");
    lprint(primes);

    ldestroy(primes);
    return 0;
}