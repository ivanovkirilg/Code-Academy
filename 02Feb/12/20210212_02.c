/* Задача 2. Разширяване на заделена памет с realloc */

/*  Основната разработка е във функцията generateGreetingMessage:
    тя създава съобщение, като избира комбинация от случайни приветствия.
    В тази версия, потребителят решава колко приветствия да добавя 
    към съобщението, като условието за добавяне е изведено в отделна функция,
    за да може лесно да се промени. При всяко добавяне се заделя нужната памет. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function allocates memory, make sure to free it! Returns NULL on error */
char *generateGreetingMessage(void);

int main() {
    char *greetingMessage = NULL;

    greetingMessage = generateGreetingMessage();
    if (greetingMessage == NULL) {
        exit(1);
    } else {
        printf("\n\n\n%s", greetingMessage);
    }
    free(greetingMessage);
    
    return 0;
}

/* this function is used by generateGreetingMessage(), change as needed */
int addGreetingCondition(void) {
    char input = 0;
    printf("Enter A to add another greeting or any character to quit\n");
    fflush(stdin);
    scanf("%c", &input);
    return (input == 'A' || input == 'a') ? 1 : 0;
}

char *generateGreetingMessage(void) {
    /* avoid magic numbers */
    #define NUM_OF_GREETINGS 5
    #define GREETING_SIZE 15

    /* you can change possible greeting strings, but make sure to set the proper #define constants above */
    const char greetings[NUM_OF_GREETINGS][GREETING_SIZE] = {"Hello! ", "Hi! ", "Hey there! ", "What's up? ", "How ya doin'? "};
    char *actualGreeting = NULL;
    
    /* initial allocation, so that we can realloc later */
    actualGreeting = (char*) malloc(1);
    if(actualGreeting == NULL) {
        printf("Memory allocation error");
        return NULL;
    }

    do {
        /* choose a random string from array */
        char chosenGreeting[GREETING_SIZE] = "";
        strcpy(chosenGreeting, greetings[rand() % NUM_OF_GREETINGS]);

        /* reallocate memory for new message */
        size_t neededMemory = strlen(actualGreeting) + strlen(chosenGreeting) + 1; /* + 1 for '\0' */
        actualGreeting = (char*) realloc(actualGreeting, neededMemory);
        if(actualGreeting == NULL) {
            printf("Reallocation error");
            return NULL;
        }

        /* add new string to message */
        strcat(actualGreeting, chosenGreeting);
        printf("The current message is: %s\n", actualGreeting);

    } while (addGreetingCondition());
    
    /* we don't need them outside function definition */
    #undef NUM_OF_GREETINGS
    #undef GREETING_SIZE

    return actualGreeting;
}