/*  Задача 10. Да намерим простите числа до 1000 и да ги сложим в масив. 
    Да напишем функция, която да ни казва дали дадено число от 0 до 1000 е просто. */

#include <stdio.h>
#include <stdlib.h>

int *calcPrimesUpTo1000(void);
int lookUpIfPrime(int n, int *lookUpTable);

int main() {
    int *primeLookUpTable = calcPrimesUpTo1000();

    int iValue = 0;
    printf("Enter number up to 1000: ");
    scanf("%d", &iValue);
    printf("%s", (lookUpIfPrime(iValue, primeLookUpTable) ? "Prime" : "Not prime"));
    
    return 0;
}

int calcIfPrime(int n) {
    if (!(n % 2) || !(n % 3) || n < 3) {
        return 0;
    }
    for (int i = 5; i*i <= n; i += 6) {
        if ( !(n % i) || !(n % (i+2)) ) {
            return 0;
        }
    }
    return 1;
}

int *calcPrimesUpTo1000(void) {
    static int primes[200];
    primes[0] = 2;
    primes[1] = 3;
    int i = 2;

    for (int n = 5; n <= 1000; n += 2) {
        if (calcIfPrime(n)) {
            primes[i++] = n;
        }
    }
    return (int *) primes;
}

int lookUpIfPrime(int n, int *lookUpTable) {
    for (int i = 0; lookUpTable[i] <= n; i++) {
        if (lookUpTable[i] == n) {
            return 1;
        }
    }
    return 0;
}
