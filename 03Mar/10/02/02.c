/*  Задача 2. Напишете програма, която проверява дали всички отворени скоби {, (, [ 
    за затворени ], ), }. Хвърлете грешка при липса на затварящи скоби и реда на който са. */

#include <stdio.h>

typedef struct Bracket {
    const char   open, close;
    unsigned int unclosedCount;
    unsigned int firstUnclosedAtLine;
} t_br;

FILE *inputFile(void);
int checkBracketsOfFile(FILE *fp);

int main() {
    FILE *fp_toCheck;

    fp_toCheck = inputFile();

    if (checkBracketsOfFile(fp_toCheck)) {
        printf("File has unmatched brackets. Check error log.\n");
    } else {
        printf("No unmatched brackets found.");
    }

    return 0;
}

FILE *inputFile(void) {
    FILE *fp = NULL;
    char name[64];
    printf("Enter file name: ");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL) {
        printf("Couldn't open file.\n");
        return inputFile();
    }
    return fp;
}


int trackBracketCheck(t_br *bracket, char c, unsigned line);
int finalizeBracketCheck(t_br *bracket);

int checkBracketsOfFile(FILE *fp) {
    t_br round  = { '(', ')', .unclosedCount = 0, .firstUnclosedAtLine = 0 }, 
         square = { '[', ']', .unclosedCount = 0, .firstUnclosedAtLine = 0 }, 
         curly  = { '{', '}', .unclosedCount = 0, .firstUnclosedAtLine = 0 };
    
    char errFlag = 0;
    
    char curChar = fgetc(fp);
    unsigned int curLine = 1;
    
    while (!feof(fp)) {
        if (curChar == '\n') {
            curLine++;
        } else {
            errFlag |= trackBracketCheck(&round, curChar, curLine);
            errFlag |= trackBracketCheck(&square, curChar, curLine);
            errFlag |= trackBracketCheck(&curly, curChar, curLine);
        }

        curChar = fgetc(fp);
    }
    
    errFlag |= finalizeBracketCheck(&round);
    errFlag |= finalizeBracketCheck(&square);
    errFlag |= finalizeBracketCheck(&curly);

    return errFlag;
}

int trackBracketCheck(t_br *bracket, char c, unsigned line) {
    if (c == bracket->close) {
        if (bracket->unclosedCount == 0) {
            fprintf(stderr, "Bracket %c closed on line %d before being opened.\n", bracket->close, line);
            return 1;
        } else {
            bracket->unclosedCount--;
            return 0;
        }
    } else if (c == bracket->open) {
        bracket->unclosedCount++;
        if (bracket->unclosedCount == 1) {
            bracket->firstUnclosedAtLine = line;
        }
    }
    return 0;
}

int finalizeBracketCheck(t_br *bracket) {
    switch (bracket->unclosedCount) {
        case 0:
            return 0;
        case 1:
            fprintf(stderr, "Bracket %c opened on line %d left unclosed.\n", 
                bracket->open, bracket->firstUnclosedAtLine);
            return 1;
        default:
            fprintf(stderr, "Bracket %c left unclosed %d times, starting on line %d.\n", 
                bracket->open, bracket->unclosedCount, bracket->firstUnclosedAtLine);
            return 1;
    }
}