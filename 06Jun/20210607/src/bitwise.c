//Направете побитовите операции върху целите числа 3 и 5 в main().
//Покажете резултата с функцията printf(“%d”, rez);
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);

        printf("%d %d %d\n", a & b, a | b, a ^ b);
    } 
    else {
        printf("Usage: %s [number1] [number2]\n", argv[0]);
        return 1;
    }
 
    return 0;
}
