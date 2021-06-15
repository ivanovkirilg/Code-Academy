#include <stdio.h>

#define USAGE "Usage: %s [string1] [string2]\n", argv[0]

int our_strcmp(char *s, char *t);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf(USAGE);
        return 1; 
    }
    
    int difference = our_strcmp(argv[1], argv[2]);
    
    if (!difference) {
        printf("The contents of both strings are equal.\n");
    
    } else if (difference > 0) {
        printf("The first character that does not match has a greater value in string1 than in string2.\n");
    
    } else {
        printf("The first character that does not match has a lower value in string1 than in string2.\n");
    }

    return 0;
}

int our_strcmp(char *s, char *t){
    int diff;

    for (int i = 0; s[i] || t[i]; i++) {
        diff = s[i] - t[i];
        
        if (diff) {
            return diff;
        }
    }
    
    return 0;
}