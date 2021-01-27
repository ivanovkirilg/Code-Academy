void printInBinary(long long number, unsigned int bitsToPrint)
{
    unsigned int i = 1;
    for(i <<= bitsToPrint - 1; i > 0; i >>= 1) {
        if (i&number) printf("1");
        else printf("0");
    }
    printf("\n");
}

int findMSB(int iNumber) {
    unsigned int mask = 0x80000000;
    int bit = 0;
    int index = 31;
    for (bit = mask & iNumber; bit == 0 && index >= 0; index-- ){ 
        mask >>= 1u;
        bit = mask & iNumber;
    }
    return index;
}

int stringLength(char *p_string) {
    int i = 0;
    for ( ; p_string[i]!='\0'; i++);
    return i;
}

/* DEPENDENT ON ^ stringLength() */
void reverseString(char *p_string) {
    for (int i=0, j=stringLength(p_string)-1; i < j; i++, j-- ) {
        char temp = p_string[i];
        p_string[i] = p_string[j];
        p_string[j] = temp;
    }
}