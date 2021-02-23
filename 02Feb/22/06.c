/*  Задача 6. Опишете времето в структура: часове:минути:секунди като структура tagTMyTime. 
    Използвайки тази структура, дефинирайте следните функции: добавяне на секунди, добавяне на минути. 
    Добавяне на часове към дадена променлива от тип struct tagTMyTime. Напишете следните функции: 
    връщане на броя секунди за дадена променлива от въведения тип и обратна функция от секундите 
    да се генерира променлива tagTMyTime. Напишете две функции, които изваждат и събират 
    две променливи от тип struct tagMyTime и връщат променлива от същия тип. 
    Използвайте тези функции, за да се уверите, че работят коректно. */

#include <stdio.h>

struct tagTime {
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
};

void showTime(struct tagTime t) {
    printf("%d:%.2d:%.2d\n", t.hours, t.minutes, t.seconds);
}

struct tagTime addSeconds(struct tagTime, unsigned int);
struct tagTime addMinutes(struct tagTime, unsigned int);
struct tagTime addSecondsStrict(struct tagTime, unsigned int);
unsigned int timeToSeconds(struct tagTime);
struct tagTime secondsToTime(unsigned int);
struct tagTime addTime(struct tagTime, struct tagTime);
struct tagTime subtractTime(struct tagTime, struct tagTime);

int main() {
    struct tagTime clock = { 5, 25, 38 };

    printf("Testing addSeconds:\n");
    showTime(clock);
    clock = addSeconds(clock, 5); /* Basic functionality */
    printf("+ 5s = "), showTime(clock);
    clock = addSeconds(clock, 20); /* Overflowing the minute */
    printf("+ 20s = "), showTime(clock);
    clock = addSeconds(clock, 2440); /* Overflowing the hour */
    printf("+ 2440s = "), showTime(clock);
    printf("+ 100000s (regular) = "), showTime( addSeconds(clock, 100000) ); /* Overflowing the day */
    printf("strict (throws message):\n");
    clock = addSecondsStrict(clock, 100000); /* Strict version throws a message */
    showTime(clock);

    printf("\nTesting conversion:\n");
    unsigned int sec = timeToSeconds(clock);
    printf("In seconds: %d\n", sec);
    sec += 37; /* Go into new minute */
    clock = secondsToTime(sec); 
    showTime(clock); /* Correct after conversion */

    printf("-\t-\t-\nTesting addTime:\n");
    struct tagTime clock1 = { 2, 2, 30 };
    struct tagTime clock2 = { 12, 55, 45 };
    showTime(clock);
    printf("+ "), showTime(clock1);
    clock = addTime(clock, clock1);
    printf("= "), showTime(clock);

    printf("+ "), showTime(clock2);
    clock = addTime(clock, clock2);
    printf("= "), showTime(clock);

    printf("\nTesting subtractTime:\n");
    showTime(clock2);
    printf("- "), showTime(clock1);
    clock = subtractTime(clock2, clock1);
    printf("= "), showTime(clock);
    printf("- "), showTime(clock2);
    clock = subtractTime(clock, clock2);
    printf("= "), showTime(clock);
    
    return 0;
}

struct tagTime addSeconds(struct tagTime initial, unsigned int addedSec) {
    unsigned int newSec = initial.seconds + addedSec;
    unsigned int newMin = newSec/60 + initial.minutes;
    unsigned int newHours = newMin/60 + initial.hours;
    initial.seconds = newSec % 60;
    initial.minutes = newMin % 60;
    initial.hours = newHours % 24;
    return initial;
}

struct tagTime addMinutes(struct tagTime initial, unsigned int addedMinutes) {
    return addSeconds(initial, addedMinutes * 60);
}

struct tagTime addHours(struct tagTime initial, unsigned int addedHours) {
    return addMinutes(initial, addedHours * 60);
}

unsigned int timeToSeconds(struct tagTime t) {
    return (t.seconds + t.minutes * 60 + t.hours * 3600);
}

struct tagTime secondsToTime(unsigned int seconds) {
    struct tagTime t = { 0, 0, 0 };
    return addSeconds(t, seconds);
}

struct tagTime addTime(struct tagTime t1, struct tagTime t2) {
    return addSecondsStrict(t1, timeToSeconds(t2));
}

struct tagTime subtractTime(struct tagTime minuend, struct tagTime subtrahend) {
    if (minuend.seconds >= subtrahend.seconds) {
        minuend.seconds -= (signed) subtrahend.seconds;
    } else {
        minuend.seconds = 60 + minuend.seconds - (signed) subtrahend.seconds;
        minuend.minutes--;
    }
    if (minuend.minutes >= subtrahend.minutes) {
        minuend.minutes -= (signed) subtrahend.minutes;
    } else {
        minuend.minutes = 60 + minuend.minutes - (signed) subtrahend.minutes;
        minuend.hours--;
    }
    if (minuend.hours >= subtrahend.hours) {
        minuend.hours -= (signed) subtrahend.hours;
    } else {
        minuend.hours = 24 + minuend.hours - (signed) subtrahend.hours;
        printf("It's an old day!\n");
    }
    return minuend;
}

struct tagTime addSecondsStrict(struct tagTime initial, unsigned int addedSec) {
    unsigned int newSec = initial.seconds + addedSec;
    if (newSec < 60) {
        initial.seconds = newSec;
    } else  {
        unsigned int newMin = newSec/60 + initial.minutes;
        initial.seconds = newSec % 60;
        if (newMin < 60) {
            initial.minutes = newMin;
        } else {
            unsigned int newHours = newMin/60 + initial.hours;
            initial.minutes = newMin % 60;
            if (newHours < 24) {
                initial.hours = newHours;
            } else {
                printf("It's a new day!\n");
                initial.hours = newHours % 24;
            }
        }
    }
    return initial;
}