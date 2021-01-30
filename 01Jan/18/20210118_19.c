/*  Упражнение 19*. Докажете опитно теоремите на ДеМорган: 
    ! ( А && B ) = ! A || ! B 
    ! ( A || B ) = ! A && ! B 
    Под опитно доказване се разбира да се направят всичките 
    четири комбинации на A и B и за тях да се провери горното. */

#include <stdio.h>

int main() {

    int A = 0;
    int B = 0;
    if ( ! ( A && B ) == ! A || ! B ) printf("T1 proven for A=0 B=0\n"); 
    if ( ! ( A || B ) == (!A && ! B) ) printf("T2 proven for A=0 B=0\n");

    A = 1;
    B = 0;
    if ( ! ( A && B ) == ! A || ! B ) printf("T1 proven for A=1 B=0\n"); 
    if ( ! ( A || B ) == (!A && ! B) ) printf("T2 proven for A=1 B=0\n");
    
    A = 0;
    B = 1;
    if ( ! ( A && B ) == ! A || ! B ) printf("T1 proven for A=0 B=1\n"); 
    if ( ! ( A || B ) == (!A && ! B) ) printf("T2 proven for A=0 B=1\n");
    
    A = 1;
    B = 1;
    if ( ! ( A && B ) == ! A || ! B ) printf("T1 proven for A=1 B=1\n"); 
    if ( ! ( A || B ) == (!A && ! B) ) printf("T2 proven for A=1 B=1\n");
    
    return 0;
}