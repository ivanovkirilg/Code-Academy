/*  Задача 2. *argv[ ] от горния пример е указател към низове, 
    пренапишете горния код като работите с указателите. */

/*  Аз вместо да препиша echo, написах програма за умножение.
    Работя с argv по начина, който се иска. */

#include <stdio.h>

int atoi(char *str);

int main(int argc, char *argv[]) {
    /* argc: 1 for program name + we need at least 2 numbers to multiply */
    if (argc >= 3) {
        /* first cmd argument string -> int */
        int result = atoi(*(++argv));
        /* iterate through all cmd arguments, except 1 (program name) */
        while (--argc > 1) {
            /* multiply by current argument -> int */
            result *= atoi(*(++argv));
        }
        printf("%d", result);
    }

    return 0;
}

/* my own old atoi implementation, not perfect */
int atoi(char *str) {
    char *position = str;
    int result = 0, power = 1;
    
    while (*position >= '0' && *position <= '9') {
        position++;
    }
    position--;

    while (position >= str) {
        result += (*position % '0') * power;
        power *= 10;
        position--;
    }
    return result;
}