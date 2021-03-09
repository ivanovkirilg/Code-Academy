/* Задача 17. Пренапишете задачи 14 и 15 от лекция 22 за Потребителски типове в pipe. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_OF_PARTICIPANTS 5
#define PARTICIPANT_FORMAT "%d %s %s %d\n" /* number, first, last name, age */

typedef struct {
    unsigned number, age;
    char *firstName, *lastName;
} participant;

participant *generateParticipants(unsigned numOfParticipants);
void deleteParticipants(participant *participants, unsigned numOfParticipants);
void outputParticipants(participant *participants, unsigned numOfParticipants);

int main() {
    participant *allParticipants = NULL;
    
    allParticipants = generateParticipants(NUM_OF_PARTICIPANTS);

    outputParticipants(allParticipants, NUM_OF_PARTICIPANTS);

    deleteParticipants(allParticipants, NUM_OF_PARTICIPANTS);

    return 0;
}

participant *generateParticipants(unsigned numOfParticipants) {
    char *firstNames[] = { "John", "Mike", "Patrick", "Jessica", "Karen" };
    char *lastNames[] = { "Johnson", "Smith", "Steinbech", "Burger", "Walker" };
    #define MIN_AGE 18
    #define MAX_AGE 40
    
    participant *allParticipants = NULL;
    allParticipants = (participant *) malloc(sizeof(participant) * numOfParticipants);
    if (allParticipants == NULL) {
        printf("Allocation Error\n");
        exit(1);
    }

    char nameBuffer[32] = "";
    for (int i = 0; i < numOfParticipants; i++) {
        /* Generate age within range, set number */
        allParticipants[i].number = i + 1;
        allParticipants[i].age = MIN_AGE + rand() % (MAX_AGE - MIN_AGE);

        /* Generate first name */
        strcpy(nameBuffer, firstNames[rand() % sizeof(firstNames)/sizeof(char *)]);
        allParticipants[i].firstName = (char *) malloc(strlen(nameBuffer + 1));
        if (allParticipants == NULL) {
            printf("Allocation Error\n");
            exit(1);
        }
        strcpy(allParticipants[i].firstName, nameBuffer);
        
        /* Generate last name */
        strcpy(nameBuffer, lastNames[rand() % sizeof(lastNames)/sizeof(char *)]);
        allParticipants[i].lastName = (char *) malloc(strlen(nameBuffer + 1));
        if (allParticipants == NULL) {
            printf("Allocation Error\n");
            exit(1);
        }
        strcpy(allParticipants[i].lastName, nameBuffer);
        /* debug */
        /* printf("%d. %s %s age: %d\n", 
            allParticipants[i].number, allParticipants[i].firstName, allParticipants[i].lastName, allParticipants[i].age); */
    }

    return allParticipants;
}

void deleteParticipants(participant *participants, unsigned numOfParticipants) {
    for (int i = 0; i < numOfParticipants; i++) {
        free(participants[i].firstName);
        free(participants[i].lastName);
    }
    free(participants);
}

void outputParticipants(participant *participants, unsigned numOfParticipants) {
    printf("%d\n", numOfParticipants);
    for (int i = 0; i < numOfParticipants; i++) {
        printf(PARTICIPANT_FORMAT, 
            participants[i].number, participants[i].firstName, participants[i].lastName, participants[i].age);
    }
}