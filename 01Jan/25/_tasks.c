/* #include <stdio.h>

int main() {
    char c;
    int count;
    while ((c = getchar()) != EOF) {
        count = 1;
        while (c = getchar() != '\n') {
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
} 
 */
//////////////////////////////////////////////////////////////////
/* #include <stdio.h>

int main() {
    char c;
    int lineCount = 0;
    while ( ( c=getchar() ) != EOF ) {
        if (c == '\n') lineCount++;
    }
    printf("%d lines.", lineCount);
    return 0;
} 
 */

/* #include <stdio.h>

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
} */

#include <stdio.h>

int main() {
    char c;
    while ( (c = getchar()) != EOF) {
        if ( (c>='a' && c<='z') || (c>='A' && c<='Z') || c=='\n' ) {
            putchar(c);
        }
    }
    return 0;
}