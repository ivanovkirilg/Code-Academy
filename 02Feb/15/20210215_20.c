/* Задача 20. Дефинирайте стринг "I am a poor programmer". Заменете през пойнтер "poor" с "great". */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceWithinString(char string[], char *source, char *target, size_t szString);

int main() {
    char text[32] = "I am a poor programmer";
    char wordToReplace[] = "poor";
    char newWord[] = "great";
    
    int retValue = replaceWithinString(text, wordToReplace, newWord, 32);
    printf("%s\nValue returned by function: %d\n", text, retValue); /* 0 indicates success */

    retValue = replaceWithinString(text, "a great", "the greatest ever", 32);
    printf("%s\nValue returned by function: %d\n", text, retValue); /* 2 chars truncated */
    
    retValue = replaceWithinString(text, "programm", "coder", 32);
    printf("%s\nValue returned by function: %d\n", text, retValue); /* success */

    retValue = replaceWithinString(text, "coder", "creator of buggy programs", 32);
    printf("%s\nValue returned by function: %d\n", text, retValue); /* 22 chars truncated */
    
    return 0;
}

int replaceWithinString(char string[], char *source, char *target, size_t szString) {
    int sourceLen = strlen(source), targetLen = strlen(target);
    int buffPos = 0, strPos = 0;
    char *strEnd = string + strlen(string);
    char *buffer = (char*) malloc(szString);

    if (buffer == NULL) {
        return -1; /* allocation error code */
    }

    /* Go through entire original string */
    while (string + strPos <= strEnd) {

        /* Check each letter, then ... */
        if (string[strPos] == *source) {
            /* ... check for the rest of the word */
            for (int sourcePos = 0; sourcePos < sourceLen; sourcePos++) {
                /* If this is not the word we want to replace, skip ahead */
                if (string[strPos + sourcePos] != source[sourcePos]) {
                    break;
                }
                /* If we matched the entire word ... */
                if (sourcePos == sourceLen - 1) {
                    /* Copy the replacement into the buffer */
                    for (int targetPos = 0; targetPos < targetLen; buffPos++, targetPos++) {
                        buffer[buffPos] = target[targetPos];
                        /* (check if we're about to overflow the string, terminate it if so) */
                        if (buffPos == szString - 1) {
                            buffer[buffPos] = '\0';
                            strcpy(string, buffer);
                            free(buffer);
                            /* return the number of characters we have failed to store (original + replacement) */
                            return strEnd - string - strPos + targetLen - targetPos;
                        }
                    }
                    /* Skip the entire word we have replaced */
                    strPos += sourceLen;
                }
            }
        }

        /* (check if we're about to overflow the string, terminate it if so) */
        if (buffPos == szString - 1) {
            buffer[buffPos] = '\0';
            strcpy(string, buffer);
            free(buffer);
            /* return the number of characters we have failed to store (only original) */
            return strEnd - string - strPos;
        }

        /* Go to next character */
        buffer[buffPos++] = string[strPos++];
    }

    strcpy(string, buffer);
    free(buffer);
    return 0; /* indicates success */
}