/* Задача 17. Пренапишете задачи 14 и 15 от лекция 22 за Потребителски типове в pipe. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PARTICIPANT_FORMAT "%d %s %s %d\n" /* number, first, last name, age */

typedef struct {
    unsigned number, age;
    char *firstName, *lastName;
} participant;

participant *storeParticipants(unsigned numOfParticipants);
void deleteParticipants(participant *participants, unsigned numOfParticipants);
void sortByName(participant *participants, unsigned numOfParticipants);
void printParticipants(participant *participants, unsigned numOfParticipants);

int main() {
    unsigned numOfParticipants = 0;
    participant *allParticipants = NULL;

    scanf("%d", &numOfParticipants);
    allParticipants = storeParticipants(numOfParticipants);

    sortByName(allParticipants, numOfParticipants);

    printParticipants(allParticipants, numOfParticipants);

    deleteParticipants(allParticipants, numOfParticipants);

    return 0;
}

participant *storeParticipants(unsigned numOfParticipants) {
    participant *all = (participant *)malloc(sizeof(participant) * numOfParticipants);
    if (all == NULL) {
        printf("Allocation error.");
        exit(1);
    }

    char firstName[32] = "";
    char lastName[32] = "";
    for (int i = 0; i < numOfParticipants; i++) {
        scanf(PARTICIPANT_FORMAT, &all[i].number, firstName, lastName, &all[i].age);
        all[i].firstName = (char *) malloc(strlen(firstName + 1));
        all[i].lastName = (char *) malloc(strlen(lastName + 1));
        strcpy(all[i].firstName, firstName);
        strcpy(all[i].lastName, lastName);
        
        /* debug */
        /* printf("Received participant: " PARTICIPANT_FORMAT, 
            all[i].number, all[i].firstName, all[i].lastName, all[i].age); */
    }

    return all;
}

void deleteParticipants(participant *participants, unsigned numOfParticipants) {
    for (int i = 0; i < numOfParticipants; i++) {
        free(participants[i].firstName);
        free(participants[i].lastName);
    }
    free(participants);
}

int compare(const void *a, const void *b) {
    int result = 0;
    result = strcmp(((participant *)a)->firstName, ((participant *)b)->firstName);
    if (result == 0) {
        result = strcmp(((participant *)a)->lastName, ((participant *)b)->lastName);
    }
    return result;
}

void sortByName(participant *participants, unsigned numOfParticipants) {
    qsort(participants, numOfParticipants, sizeof(participant), &compare);
}

void printParticipants(participant *participants, unsigned numOfParticipants) {
    for (int i = 0; i < numOfParticipants; i++) {
        participant cur = participants[i];
        printf("%-7s %7s, number %d, %d years old\n", cur.firstName, cur.lastName, cur.number, cur.age);
    }
}