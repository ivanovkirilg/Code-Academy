/*  Задача 4. Дефинирайте функция, която събирадве променливи и 
    приема и изпълнява предефиниран указател, като стойност. */

#include <stdio.h>

typedef long long int myint;
typedef myint* myiptr;

myint addByAddress(myiptr a, myiptr b) {
    return *a + *b;
}

int main() {
    myint x = 15000000000;
    myiptr p = &x;

    x = addByAddress(p, &x);
    printf("%lld", x);

    return 0;
}