#include <stdio.h>
#include "kilist.h"

int main() {
    list february = lcreate();
    list march = lcreate();

    ladd(march, 15);
    ladd(march, 12);
    ladd(march, 10);
    ladd(march, 8);
    ladd(march, 5);

    lappend(february, 1);
    lappend(february, 3);
    lappend(february, 5);
    lappend(february, 8);
    lappend(february, 10);
    lappend(february, 12);
    lappend(february, 15);
    lappend(february, 17);
    lappend(february, 19);
    lappend(february, 22);
    lappend(february, 24);
    lappend(february, 26);

    printf("Dates of February lectures:\t");
    lprint(february);
    printf("(len %d)\n", lgetlen(february));
    printf("Dates of March lectures:\t");
    lprint(march);
    printf("(len %d)\n", lgetlen(march));

    printf("\n---Deleting 10.3 and 08.2---\n");
    lremindex(march, 2);
    lremindex(february, 3);
    printf("Dates of February lectures:\t");
    lprint(february);
    printf("(len %d)\n", lgetlen(february));
    printf("Dates of March lectures:\t");
    lprint(march);
    printf("(len %d)\n", lgetlen(march));

    printf("\n---Readding 10.3 and 08.2---\n");
    linsindex(march, 10, 2);
    linsindex(february, 8, 3);
    printf("Dates of February lectures:\t");
    lprint(february);
    printf("(len %d)\n", lgetlen(february));
    printf("Dates of March lectures:\t");
    lprint(march);
    printf("(len %d)\n", lgetlen(march));

    ldestroy(february);
    ldestroy(march);

    return 0;
}
