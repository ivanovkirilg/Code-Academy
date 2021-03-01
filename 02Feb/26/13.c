/*  Задача 13. Опишете времето: часове:минути:секунди като структура tagTMyTime. 
    Използвайки тази структура, дефинирайте следните функции: добавяне на секунди, добавяне на минути. 
    Добавяне на часове към дадена променлива от тип struct tagTMyTime. Напишете следните функции: 
    връщане на броя секунди за дадена променлива от въведения тип и обратна функция 
    от секундите да се генерира променлива tagTMyTime. Напишете две функции, които изваждат и събират 
    две променливи от тип struct tagMyTime и връщат променлива от същия тип. 
    В решението трябва да се използва динамично заделяне на памет и typedef. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    short int hours;
    char minutes;
    char seconds;
} t_myTime;

void checkTime(t_myTime *t) {
    if (t->seconds > 60) {
        t->seconds %= 60;
        t->minutes++;
    }
    if (t->minutes > 60) {
        t->minutes %= 60;
        t->hours++;
    }
    if (t->seconds < 0) {
        t->seconds += 60;
        t->minutes--;
    }
    if (t->minutes < 0) {
        t->minutes += 60;
        t->hours--;
    }
    if (t->hours < 0) {
        printf("negative time!\n");
        t->hours = 0;
    }
}

/* добавяне на секунди */
unsigned char addSeconds(t_myTime *original, unsigned char seconds) {
    original->seconds += seconds;
    checkTime(original);
    return original->seconds;
}

/* добавяне на минути */
unsigned char addMinutes(t_myTime *original, unsigned char minutes) {
    original->minutes += minutes;
    checkTime(original);
    return original->minutes;
}

/*добавяне на часове*/
int addHours(t_myTime *original,unsigned short int hours){
    original->hours += hours;
    checkTime(original);
    return original->hours;
}

unsigned int timeInSeconds(t_myTime t) {
    return t.seconds + t.minutes * 60 + t.hours * 3600;
}

t_myTime *timeFromSeconds(unsigned int seconds) {
    t_myTime *t = (t_myTime *) malloc(sizeof(t_myTime));
    if (t == NULL) {
        printf("alloc error");
        exit(1);
    }
    t->hours = seconds / 3600;
    t->minutes = (seconds - (t->hours * 3600)) / 60;
    t->seconds = seconds % 60;
    return t;
}

t_myTime *sumTime(t_myTime t1, t_myTime t2) {
    t_myTime *t = (t_myTime *) malloc(sizeof(t_myTime));
        if (t == NULL) {
        printf("alloc error");
        exit(1);
    }
    t->seconds = t1.seconds + t2.seconds;
    t->minutes = t1.minutes + t2.minutes;
    t->hours = t1.hours + t2.hours;
    checkTime(t);
    return t;
}

t_myTime *subTime(t_myTime t1, t_myTime t2) {
    t_myTime *t = (t_myTime *) malloc(sizeof(t_myTime));
        if (t == NULL) {
        printf("alloc error");
        exit(1);
    }
    t->seconds = t1.seconds - t2.seconds;
    t->minutes = t1.minutes - t2.minutes;
    t->hours = t1.hours - t2.hours;
    checkTime(t);
    return t;
}

void printTime(t_myTime t) {
    printf("%.2d:%.2d:%.2d\n", t.hours, t.minutes, t.seconds);
}

int main() {
    t_myTime test = { 12, 40, 50 };
    t_myTime test1 = { 13, 20, 30 };
    
    printTime(test);
    // addSeconds(&test, 15);
    // printTime(test);
    // addMinutes(&test, 20);
    // printTime(test);
    // addHours(&test, 10);
    // printTime(test);
    // printf("%u", timeInSeconds(test));
    t_myTime *newTest = subTime(test, test1);
    printTime(*newTest);

    free(newTest);
    return 0;
}
