/*  Задача 12. Представете служителите във фирма в структура с членове: 
    пореден номер, име, презиме, фамилия, позиция, трудов стаж в години, заплата в лева, 
    указател към структурата, описващ неговия началник. Напишете програма, която въвежда 10 служителя, 
    които се съхраняват в масив от описаните структури. Въвеждането на служителите може да стане на два паса, 
    първо въвеждане на всички данни без указателя към началника и на втори пас, 
    указване на всеки служител кой е неговият началник.
    В решението трябва да се използва динамично заделяне на памет и typedef. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define NUMBEOFMONTHS 12
#define SALARYNONMANAGER 2500
#define SALARYMANAGER 3500
#define NUMOFMANAGERS 2

char *firstNames[] = {
    "Ivan", "Dragan", "Stoyan", "Pesho", "Georgi", "George"
};
char *surNames[] = {
    "Ivanov", "Draganov", "Stoyanov", "Petkov", "Georgiev", "George"
};
char *positions[] = {
    "Waiter", "Bartender", "Cook", "Head chef"
};
#define RANDOM_FIRSTNAME firstNames[rand() % (sizeof(firstNames)/sizeof(char *) - 1)]
#define RANDOM_SURNAME surNames[rand() % (sizeof(surNames)/sizeof(char *) - 1)]
#define RANDOM_POSITION positions[rand() % (sizeof(positions)/sizeof(char *) - 1)]

typedef struct experience{
    int years;
    int months;
} exp;

typedef struct employee{
    int id;
    char *name;
    char *middleName;
    char *lastName;
    char *position;
    exp experience;
    int pay;
    struct employee *manager;
} employee;

exp makeExperience(int years, int months);
employee makeEmployee(char *name, char *middleName,
    char *lastName, char *position, exp experience, int pay);
void fillEmployeeArray(employee arr[], int size);
void printEmployees(employee arr[], int size);

int main(void){
    srand(time(NULL));

    employee employees[SIZE];
    fillEmployeeArray(employees,SIZE);
    printEmployees(employees,SIZE);

    for (int i = 0; i < SIZE; i++) {
        free(employees[i].name);
        free(employees[i].middleName);
        free(employees[i].lastName);
        free(employees[i].position);
    }
    return 0;
}

exp makeExperience(int years, int months){
    years+=months / NUMBEOFMONTHS;
    months=months % NUMBEOFMONTHS;
    exp experience = {years,months};
    return experience;
}

employee makeEmployee(char *name, char *middleName,
char *lastName, char *position, exp experience, int pay){
    static int currentID = 1;
    employee employee = { currentID, 
        .name = (char *) malloc(strlen(name) + 1),
        .middleName = (char *) malloc(strlen(middleName) + 1), 
        .lastName = (char *) malloc(strlen(lastName) + 1), 
        .position = (char *) malloc(strlen(position) + 1),
        experience, pay, NULL};
    if (!employee.name || !employee.middleName || !employee.lastName || !employee.position) {
        printf("Allocation error.");
        exit(1);
    }
    strcpy(employee.name, name);
    strcpy(employee.middleName, middleName);
    strcpy(employee.lastName, lastName);
    strcpy(employee.position, position);
    currentID++;
    return employee;
}

void fillEmployeeArray(employee arr[], int size){
    arr[0] = makeEmployee(RANDOM_FIRSTNAME, RANDOM_SURNAME, RANDOM_SURNAME, "Manager", 
        makeExperience(rand()%SIZE + NUMOFMANAGERS, (rand()%NUMBEOFMONTHS)+1), 
        rand()%SALARYMANAGER);
    arr[0].manager = &arr[0];
    arr[1] = makeEmployee(RANDOM_FIRSTNAME, RANDOM_SURNAME, RANDOM_SURNAME, "Assistant Manager", 
        makeExperience(rand()%SIZE + 1, (rand()%NUMBEOFMONTHS)+1), 
        rand()%SALARYMANAGER );
    arr[1].manager = &arr[0];
    for(int i = NUMOFMANAGERS; i < size; i++){
        arr[i] = makeEmployee(RANDOM_FIRSTNAME, RANDOM_SURNAME, RANDOM_SURNAME, RANDOM_POSITION, 
            makeExperience(rand()%SIZE, (rand()%NUMBEOFMONTHS)+1), 
            rand()%SALARYNONMANAGER);
        arr[i].manager = &arr[rand() % NUMOFMANAGERS];
    }
}


void printEmployees(employee arr[], int size){
    for(int i = 0; i < size; i++){
        printf("Id: %d\n",arr[i].id);
        printf("First name: %s\n",arr[i].name);
        printf("Middle name: %s\n",arr[i].middleName);
        printf("Last name: %s\n",arr[i].lastName);
        printf("Job: %s\n",arr[i].position);
        printf("Experience: %d years %d months\n",arr[i].experience.years,
        arr[i].experience.months);
        printf("Pay: %d\n",arr[i].pay);
        printf("Manager id: %d\n",arr[i].manager->id);
        printf("\n\n");
    }
}