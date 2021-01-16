/*  Задача 15. Използвайте статична локална променлива,
    за да постигнете същото поведение, описано в задача 14. */

#include <stdio.h>

int test();

int main() {
    
    test();
    test();
    printf("Function called %d times.",test());
    
    return 0;
}

int test(){
    static int functionCalled = 0;
    functionCalled++;
    return functionCalled;
}