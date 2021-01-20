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