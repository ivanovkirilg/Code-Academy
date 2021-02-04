#include <stdio.h>

int recursiveFunction(int a, int b) {
    int sum = 1;
    if (a > 1 && b > 1) {
        sum += recursiveFunction(a - 1, b - 1);
    }
    return (a + b + sum);
}

int main() {
    printf("Recursive function: %d\n", recursiveFunction(5, 7));
    
    return 0;
}
