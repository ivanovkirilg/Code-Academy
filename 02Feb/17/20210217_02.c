/*  Задача 1. Направете две функции и извикайте желаната функция 
    с указател към функция, съобразно знака, подаден от командния ред. */

/*  Задача 2. Добавете към горния код функции за умножение и деление. */

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main(int argc, char *argv[]) {
    int (*pCalculate) (int, int) = NULL;

    int x = atoi(argv[1]);
    int y = atoi(argv[3]);

    if (argc != 4) {
        printf("Usage:\n%s [integer] [+ - . :] [integer]\n", argv[0]);
    }
    /* switch probably not better than else if, but I thought it was interesting to try */
    else switch(*argv[2]) {
        case '+':
            pCalculate = &add;
            break;
        case '-':
            pCalculate = &subtract;
            break;
        case '.':
            pCalculate = &multiply;
            break;
        case ':':
            if (y == 0) {
                printf("Cannot divide by 0!");
                return 1;
            }
            pCalculate = &divide;
            break;
        default:
            printf("Valid operations: + - . :\n");
    }
    if (pCalculate == NULL) {
        return 1;
    } else {
        printf("%d", pCalculate(x, y));
    }

    return 0;
}