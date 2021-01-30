/* 3. Напишете програма, която преброява шпациите, табулациите и новите редове. */

#include <stdio.h>

int main() {
    char c;
    int lineCount = 0, tabCount = 0, spaceCount = 0;
    while ( ( c=getchar() ) != EOF ) {
        lineCount += (c=='\n') ? 1 : 0;
        tabCount += (c=='\t') ? 1 : 0;
        spaceCount += (c==' ') ? 1 : 0;
    }
    printf("%d lines\n%d tabs\n%d spaces", lineCount, tabCount, spaceCount);
    return 0;
}