#include <stdio.h>

int checkBarcode(char *barcode);
char calculateBarcodeLastDigit(char *barcode);

int main() {
    
    char barcode0[13] = "013800151735"; /* Example barcode */
    printf("%s\t", barcode0);
    checkBarcode(barcode0); /* Check full barcode */

    char barcode1[13] = "10645032510 ";
    barcode1[11] = calculateBarcodeLastDigit(barcode1); /* Set valid final digit */
    printf("%s\t", barcode1);
    checkBarcode(barcode1);

    char barcode2[13] = "012315239254";
    printf("%s\t", barcode2);
    checkBarcode(barcode2); /* Check invalid barcode */
    
    printf("Last digit should be %c", calculateBarcodeLastDigit(barcode2));

    return 0;
}

char calculateBarcodeLastDigit(char *barcode) {
    int i = 0;
    int check = 0;
    for ( ; i < 11; i += 2) {
        check += barcode[i] - '0';
    }
    check *= 3;
    for (i = 1 ; i < 10 ; i += 2) {
        check += barcode[i] - '0';
    }
    check = 9 - (check-1) % 10;
    return check + '0';
}

int checkBarcode(char *barcode) {
    if (barcode[11] == calculateBarcodeLastDigit(barcode)) {
        printf("Valid barcode.\n");
        return 1;
    } else {
        printf("Invalid barcode.\n");
        return 0;
    }
}