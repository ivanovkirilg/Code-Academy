/* Декларирайте функция, която събира две числа и връща резултата им
 * Декларирайте в мейн две променливи, дайте им стойности,
 * подайте променливите на функцията и принтирайте резултата.
 */

#include <stdio.h>

int addIntegers(int a, int b);

int main(){
    int a = 5;
    int b = 3;
    
    int sum = addIntegers(a, b);
    printf("%d", sum);
    
    return 0;
}

int addIntegers(int a, int b){
    return a+b;
}
