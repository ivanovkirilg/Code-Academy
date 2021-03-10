#include <stdio.h>

int main() {
    FILE *console = NULL;

    console = fopen("CON", "w");

    fprintf(console, "console\n");
    
    printf("piped\n");

    return 0;
}
