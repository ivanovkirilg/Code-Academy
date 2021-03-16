#include <stdio.h>
#include "kilist.h"
#define N 500000

int main(){
    long long i, j;
    int a[N];
    
    for (i=2; i<N; i++) 
        a[i]=1;
    
    for (i=2; i<N; i++)
        if (a[i])
            for (j=i; i*j<N; j++)
                a[i*j]=0;
    // printf("1 ");
    a[1] = 1;
    // for (i=2; i<N; i++)
    //     if (a[i]) 
    //         printf("%d ",i);
    
    list primes = lcreate();
    for (i=1; i<N; i++)
        if (a[i])
            lappend(primes, i);
    
    lprint(primes);

    ldestroy(primes);

    return 0;
}