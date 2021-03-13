/* Задача 7. Напишете програма, която обработва Ctrl+C, Ctrl+D, Ctrl+Z */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

unsigned g_seconds = 0;
volatile int g_state = 0;
#define RUN_STATE 0
#define INT_STATE 1
#define STP_STATE 2

void interruptHandler(int sig) {
    g_state = INT_STATE;
    return;
}

/* Impossible on Windows */
void stopHandler(int sig) {
    g_state = STP_STATE;
    return;
}

int main(int argc, char *argv[]) {
    signal(SIGINT, interruptHandler);
#ifdef SIGTSTP
    /* Undefined on Windows */
    signal(SIGTSTP, stopHandler);
#endif

    while (++g_seconds) {
        switch (g_state) {
            case RUN_STATE:
                printf("%s running for %2d seconds.\n", argv[0], g_seconds);
                sleep(1);
                break;
            case INT_STATE:
                printf("Program closed after running for %d seconds.\n", g_seconds);
                exit(0);
            /* Impossible on Windows */
            case STP_STATE:
                printf("Program paused. Press CTRL+D to continue.\n");
                while (getchar() != EOF);
                g_state = RUN_STATE;
                break;
        }
    }

    fprintf(stderr, "Unsigned int 'g_seconds' has overflowed.\n");

    return 0;
}