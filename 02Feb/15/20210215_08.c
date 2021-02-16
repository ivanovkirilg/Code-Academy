/*  Задача 8. Дефинирайте и инициализирайте променлива и пойнтер към нея. 
    Отпечатайте адреса на пойнтера с %p с printf. */

#include <stdio.h>

int main() {
    int a = 5, *p = &a;
    printf("Pointer address: %p\nPoints to: %p", &p, p);
    
    return 0;
}
