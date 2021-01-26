/*  4. Напишете програма, която копира входа си на изхода, 
    като замества всеки низ от една или повече шпации, с една единствена шпация. */

#include <stdio.h>

int main() {
    char c, c1 = 0;        
    while ( (c=getchar()) != EOF ) {
        while (c==' ' && c1==' ') {
            c = getchar();
        }
        c1 = c;
        putchar(c);
    }
    return 0;
}