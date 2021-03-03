/*  Задача 3. Дефинирайте потребителски тип към указател. Създайте променлива, 
    насочете указателя към нея, използвайки новия потребителски тип. */

#include <stdio.h>

typedef long long int myint;
typedef myint* myiptr;

int main() {
    myint x = 15;
    myiptr p = &x;

    printf("Enter value: ");
    scanf("%lld", p);
    printf("%lld", x);

    return 0;
}