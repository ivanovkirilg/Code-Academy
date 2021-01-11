#include <stdio.h>

int main() {
    /* -- Подробен вариант --

    int three = 3;
    int five = 5;

    int bitAnd = three & five;
    printf("%d ", bitAnd);

    int bitOr = three | five;
    printf("%d ", bitOr);

    int bitXor = three ^ five;
    printf("%d ", bitXor); */

    /* -- Пестелив вариант -- */
    printf("%d ", 3&5);
    printf("%d ", 3|5);
    printf("%d ", 3^5);

    return 0;
}
