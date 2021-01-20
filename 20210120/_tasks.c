/* #include <stdio.h>

int main() {
    int menuChoice = 0;
    printf("Press 1 for a greeting. \n");
    printf("Press 2 for a poem. \n");
    printf("Press 3 for a secret. \n");
    while(1){
        scanf("%d", &menuChoice);
        if (menuChoice == 1) {
            printf("Hello!\n");
            break;
        } else if (menuChoice == 2) {
            printf("Roses are red\nViolets are blue\nComputers are dead\nAnd so is this stu-\n");
            break;
        } else if (menuChoice == 3) {
            printf("I'm good at keeping secrets.\n");
            break;
        } else {
            printf("Learn numbers.\n");
        }
    }

    return 0;
} */

/* #include <stdio.h>
#include <unistd.h>

int main() {
    int menuChoice = 0;
    int inMenu = 1;
    while(inMenu){
        printf("\nPress 1 for a greeting. \n");
        printf("Press 2 for a poem. \n");
        printf("Press 3 for a secret. \n");
        printf("Press 4 to exit. \n");
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1:
                printf("Hello!\n");
                sleep(1);
                break;
            case 2:
                printf("Roses are red\nViolets are blue\nComputers are dead\nAnd so is this stu-\n");
                sleep(4);
                break;
            case 3:
                printf("I'm good at keeping secrets.\n");
                sleep(2);
                break;
            case 4:
                printf("Goodbye!\n");
                inMenu = 0;
                break;
            break;
                default:
                printf("Learn numbers.\n");
                sleep(1);
        }
    }

    return 0;
} */

/* #include <stdio.h>

int main() {
    int iValue = 13;
    do {
        printf("Value: %d\n", iValue);
        iValue++;
    } while (iValue < 20);
    
    return 0;
} */

/* #include <stdio.h>

int main() {
    int iValue = 0;
    for(;;){
        printf("%d ", iValue);
        if (iValue++ >= 48) break;
    }    
    
    return 0;
} */
