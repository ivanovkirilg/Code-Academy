/*  Задача 4. Дефинирайте пойнтер и опитайте да отпечатате 
    стойността му на конзолата (%р) с printf. Какво се визуализира? */

/*  Визуализира се адресът на променливата, към която сочи пойнтерът. */

#include <stdio.h>

int main() {
    int iValue = 5;
    int *p_iAddress;
    printf("Before initialization: %p\n", p_iAddress);
    /* attempting to dereference it would give a segmentation fault */
    p_iAddress = &iValue;
    printf("After initialization:  %p\n", p_iAddress);
    
    return 0;
}
