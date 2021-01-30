#include <stdio.h>
#include <string.h>
void itob();
int main(void){
    int n;
    int b;
    char s[64]="";
    printf("Enter a whole number: ");
    scanf("%d", &n);
    printf("\nEnter a base for conversion: ");
    scanf("%d", &b);
    printf("\n%d (10) -> ", n); 
    if (n>0){
    goto print;
    }
    else if (n<0){
        if (b == 2 || b == 8 || b == 16){
        
        n = __INT_MAX__ + n + 1;
        goto print; 
        }
        else {
            n=-n;
            printf("-");
            goto print;
        }
    }
    print:
    itob(n,s,b);       
    printf("%s",strrev(s));
    printf(" (%d)\n", b);
    
}
void itob(int n,char s[],int b){
    int i=0;
    int c=0;
    char m[64]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
    do{
      i=n%b;
      n/=b;
      s[c]=m[i];
      c++;
   }    
   while(n>0);
  
}