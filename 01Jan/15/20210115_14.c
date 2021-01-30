/*  Задача 14. Напишете глобална променлива, която 
    увеличаваме с 1 във функция void test(). 
    Извикайте функцията три пъти test() от main() 
    и принтирайте стойността на глобалната променлива. */

#include <stdio.h>

int functionCalled = 0;

void test();

int main() {
    test();
    test();
    test();
    
    printf("Function called %d times.", functionCalled);
    
    return 0;
}

void test() {
    functionCalled++;
    return;
}
