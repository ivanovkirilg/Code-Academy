/*  Задача 7. Направете програма, в която инициализирате пойнтер към променлива 
    и след това изчислявате сбор на променливата (използвайки пойнтера) + 5. Отпечатайте на екрана. */

#include <stdio.h>

int main() {
    int a = 10, *p = &a;
    printf("%d", *p + 5);
    
    return 0;
}
