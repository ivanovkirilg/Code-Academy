/* Задача 3. Направете едносвързан списък, съдържащ числата 1-14 и принтирайте петия елемент от края му. */

#include <stdio.h>
#include "kilist.h"

int main() {
    list numbers = lcreate();

    for (int i = 1; i <= 14; i++) {
        lappend(numbers, i);
    }
    lprint(numbers);

    printf("\n" "Fifth element from the end: %d", lreadindex(numbers, lgetlen(numbers) - 5));

    ldestroy(numbers);
    return 0;
}
