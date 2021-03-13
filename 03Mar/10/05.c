#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handleSignals(int sig) {
    switch (sig) {
        case SIGSEGV:
            printf("Just a crash.\n");
            sleep(1);
            break;
        case SIGINT:
            printf("Bye-bye.\n");
            exit(sig);
        case SIGFPE:
            printf("We've just divided by zero.\n");
            sleep(2);
            exit(sig);
        default:
            printf("Signal %d shouldn't be handled by this function.\n", sig);
            exit(sig);
    }
}

int main() {
    signal(SIGSEGV, &handleSignals);
    signal(SIGINT, &handleSignals);
    signal(SIGFPE, &handleSignals);

    printf("Try interrupting the program.\n");
    sleep(3);
    printf("Too late!\n");
    sleep(1);

    char a = 0;
    printf("Shall we devide by 0? (y/n)\n");
    scanf("%c", &a);
    if (a == 'y') {
        a /= 0;
    }
    
    printf("What is stored at NULL?\n");
    sleep(3);
    int *p = NULL;
    *p = 1;

    return 0;
}
