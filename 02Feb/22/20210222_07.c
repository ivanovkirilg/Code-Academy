/*  Задача 7. Напишете обединение от три стойности: цяло число, число с плаваща запетая и низ. 
    Инициализирайте отделните членове и ги изведете на екрана. */

#include <stdio.h>
#include <stdlib.h> /* For atof(), atoi() */
#include <string.h> /* For strcpy() */
#include <math.h> /* For modf() */

enum type { INT, FLOAT, SZ };
/* This is the union required */
union commandlineValue {
    int i;
    double f;
    char sz[32];
};

/* I use it to store commandline arguments from argv as appropriate types */
struct commandlineArgument {
    union commandlineValue value;
    enum type type;
};

/* Helper function */
void printArgument(const struct commandlineArgument *arg, unsigned n);

int main(int argc, char *argv[]) {
    /* We have nothing to do if there are no commandline arguments (argc==1) */
    if (argc < 2) {
        printf("Please run with some commandline arguments\n");
        exit(1);
    }
    
    /* Array to store the arguments, -1 because we exclude the executable name argv[0] */
    struct commandlineArgument argument[argc - 1];

    /* Iterate through the arguments, starting at argv[1] */
    for (int i = 1; i < argc; i++) {
        /* modf() gives us the fractional part of atof(), if this is zero, we have an int or not a number */
        if (modf(atof(argv[i]), NULL)) {
            argument[i-1].value.f = atof(argv[i]);
            argument[i-1].type = FLOAT;
        /* atoi() returns zero if it cannot convert, same as atof() */
        } else if (atoi(argv[i])) {
            argument[i-1].value.i = atoi(argv[i]);
            argument[i-1].type = INT;
        /* if it's neither a float, nor an int, store it as a string */
        /* note that zero-valued inputs will be stored as strings, not numbers */
        } else {
            strcpy(argument[i-1].value.sz, argv[i]);
            argument[i-1].type = SZ;
        }
    }

    for (int i = 0; i < argc - 1; i++) {
        /* i + 1 so that we start the numbering from 1: stylistic choice, not necessary */
        printArgument(argument + i, i+1);
    }

    return 0;
}

/* Checks the type of the value stored in the struct and prints it accordingly */
void printArgument(const struct commandlineArgument *arg, unsigned index) {
    switch (arg->type) {
        case INT:
            printf("%d. Integer: %d\n", index, arg->value.i);
            break;
        case FLOAT:
            printf("%d. Float: %f\n", index, arg->value.f);
            break;
        case SZ:
            printf("%d. String: %s\n", index, arg->value.sz);
            break;
        default:
            printf("No valid type specified!\n");
    }
}