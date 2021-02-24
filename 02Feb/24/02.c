/* Задача 2. Използвайте предефинирани макроси */

#include <stdio.h>

int main() {
    printf("File: %s\n", __FILE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("Line: %d\n", __LINE__);
    printf("ANSI: %d\n", __STDC_VERSION__); 
    /* STDC expands to 1, to show the implementation is standard-compliant */
    
    return 0;
}