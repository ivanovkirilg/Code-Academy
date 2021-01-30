/* Задача 3. Напишете функция, която връща резултат (a+b)*4 */

#include <stdio.h>

int quadrupleSum(int a, int b);

int main() {
    
    printf("(2 + 3) times 4 = %d", quadrupleSum(2,3));
    
    return 0;
}

int quadrupleSum(int a, int b) {
    return (a + b) * 4;
}