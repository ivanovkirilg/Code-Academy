/*  Задача 4. Пренапишете Задача 2 от 05.03.2021г за Пощенските такси.
    
    При влизане в някоя функция отваряте файл за писане и при успешно
    излизане от функцията записвате във файла function_name() success.
    Това го правим за всички функции. Ако има някаква грешка записваме
    грешката във файла и името на функцията.*/

#include <stdio.h>
#include <stdlib.h>

FILE *fp_errorLog = NULL;

typedef struct{
    float weight, size;
}clientPakcage;

int inputClientChoice(void);
void fillInfoPackage(clientPakcage* ptr, int num);
float checkPriceByWeight(clientPakcage* num);
float checkPriceBySize(clientPakcage* num);
clientPakcage* allocMem(int num);
float calculateSeparatePrices(clientPakcage*ptr, int num);
float calculateTogetherPrices(clientPakcage*ptr, int num);
float* allocMemFloat(int num);

int main(void){
    fp_errorLog = fopen("log.txt", "w");
    if (fp_errorLog == NULL) {
        fprintf(stderr, "Error log failed to open.");
    }

    float separateTotal = 0;
    float togetherTotal = 0;
    int num = inputClientChoice(); /*takes number of packages from the user*/
    
    clientPakcage *p_package = allocMem(num); /*allocates memory for clients packages*/

    fillInfoPackage(p_package, num); /*fills the info for packages from the user*/

    separateTotal = calculateSeparatePrices(p_package, num);

    togetherTotal = calculateTogetherPrices(p_package, num);

    printf("In this case, it is better to send them %s.\n", (separateTotal < togetherTotal) ? "separately" : "together" );

    free(p_package); /*free the allocated memory*/

    return 0;
}

int inputClientChoice(void){
    int num = 0;

    printf("\n**************** Wellcome to post menu ****************\n");
    do{
        
        printf("Please enter for how many packages you want to check for price information.\n");
        scanf("%d",&num);

        if(num <= 0){
            printf("Invalid number! Please try agayn!\n");
            if (fp_errorLog != NULL) {
                fprintf(fp_errorLog, "%s(): User entered invalid number. Non-critical.\n", __func__);
            }
        }
    } while (num <= 0);

    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success, returned %d.\n", __func__, num);
    }

    return num;
}

float checkPriceByWeight(clientPakcage* ptr){
    float price = 0;
    if(ptr->weight <= 20){
        price = 0.46;
    }else if((ptr->weight >= 21) && (ptr->weight <= 50)){
        price = 0.69;
    }else if((ptr->weight >= 51) && (ptr->weight <= 100)){
        price = 1.02;
    }else if((ptr->weight >= 101) && (ptr->weight <= 200)){
        price = 1.75;
    }else if((ptr->weight >= 201) && (ptr->weight <= 350)){
        price = 2.13;
    }else if((ptr->weight >= 351) && (ptr->weight <= 500)){
        price = 2.44;
    }else if((ptr->weight >= 501) && (ptr->weight <= 1000)){
        price = 3.20;
    }else if((ptr->weight >= 1001) && (ptr->weight <= 2000)){
        price = 4.27;
    }else{
        price = 5.03;
    }
    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success, returned %f.\n", __func__, price);
    }
    return price;
}

float checkPriceBySize(clientPakcage* ptr){
    float price = 0;
    if(ptr->size <= 10){
        price = 0.01;
    }else if((ptr->size> 10) && (ptr->size <= 50)){
        price = 0.11;
    }else if((ptr->size > 50) && (ptr->size <= 100)){
        price = 0.22;
    }else if((ptr->size > 100) && (ptr->size <= 150)){
        price = 0.33;
    }else if((ptr->size > 150) && (ptr->size <= 250)){
        price = 0.56;
    }else if((ptr->size > 250) && (ptr->size <= 400)){
        price = 1.50;
    }else if((ptr->size > 400) && (ptr->size <= 500)){
        price = 3.11;
    }else if((ptr->size > 500) && (ptr->size <= 600)){
        price = 4.89;
    }else {
        price = 5.79;
    }
    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success, returned %f.\n", __func__, price);
    }
    return price;
}
clientPakcage* allocMem(int num){
    clientPakcage *ptr = NULL;
    ptr = (clientPakcage*)malloc(num * sizeof(clientPakcage));
    
    if(NULL == ptr){ /*chek is it allocated successfully*/
        printf("Fatal error!\n");
        if (fp_errorLog != NULL) {
            fprintf(fp_errorLog, "%s() failed to allocate memmory. Fatal error.\n", __func__);
        }
        exit(-1);
    }

    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success. Returned pointer to heap.\n", __func__);
    }

    return ptr; 
}
void fillInfoPackage(clientPakcage* ptr, int num){
    for (int i = 0; i < num; i++){
        do {
            printf("\nEnter size (in cm) for package %d\n", i + 1);
            scanf("%f", &(ptr + i)->size);
            if ((ptr + i)->size <= 0) {
                if (fp_errorLog != NULL) {
                    fprintf(fp_errorLog, "%s(): User entered invalid size %d. Non-critical.\n", __func__, (ptr + i)->size);
                }
            }
        } while ((ptr + i)->size <= 0);
        do {
            printf("Enter weight (in grams) for package %d\n", i + 1);
            scanf("%f", &(ptr + i)->weight);
            if ((ptr + i)->weight > 3000 || (ptr + i)->weight <= 0) {
                if (fp_errorLog != NULL) {
                    fprintf(fp_errorLog, "%s(): User entered invalid weight %f. Non-critical.\n", __func__, (ptr+i)->weight);
                }
            }
        } while ((ptr + i)->weight > 3000 || (ptr + i)->weight <= 0);
    }
    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success. Filled out %d packages.\n", __func__, num);
    }
}

float calculateSeparatePrices(clientPakcage*ptr, int num){
    int i;
    float *p_pricesForSize = allocMemFloat(num);
    float *p_pricesForWeight = allocMemFloat(num);

    float totalPriceSeparate = 0;

    for (i = 0; i < num; i++, ptr++){
        *(p_pricesForSize + i) = checkPriceBySize(ptr);
        *(p_pricesForWeight+i) = checkPriceByWeight(ptr);

        printf("For package %d: weight price is = %.2f\t size price is = %.2f\n",i, *(p_pricesForWeight+i), *(p_pricesForSize+i));
        
        totalPriceSeparate += *(p_pricesForSize + i) + *(p_pricesForWeight+i);
    }
    printf("Total price of separate packages: %.2f\n", totalPriceSeparate);

    free(p_pricesForSize);
    free(p_pricesForWeight);

    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success. Returned %f.\n", __func__, totalPriceSeparate);
    }

    return totalPriceSeparate;
}

float calculateTogetherPrices(clientPakcage*ptr, int num) {
    float priceForSize, priceForWeight, totalPriceTogether = 0;
    clientPakcage packagesTogether = { 0.0, 0.0 };

    for(int i=0; i<num; i++, ptr++){
        packagesTogether.size += ptr->size;
        packagesTogether.weight += ptr->weight;
    }
    priceForSize = checkPriceBySize(&packagesTogether);
    priceForWeight = checkPriceByWeight(&packagesTogether);
    printf("If combined, the weight price is = %.2f and the size price is = %.2f\n", priceForWeight, priceForSize);

    totalPriceTogether = priceForSize + priceForWeight;
    printf("Total price of the packages sent as one: %.2f\n", totalPriceTogether);

    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success. Returned %f.\n", __func__, totalPriceTogether);
    }

    return totalPriceTogether;
}

float* allocMemFloat(int num){
    float *ptr = NULL;
    ptr = (float *)malloc(num * sizeof(float)); /*allocated memory num*4 bytes */
    
    if(NULL == ptr){ /*chek is it allocated successfully*/
        printf("Fatal error!\n");
        if (fp_errorLog != NULL) {
            fprintf(fp_errorLog, "%s() failed to allocate memmory. Fatal error.\n", __func__);
        }
        exit(-1);
    }

    if (fp_errorLog != NULL) {
        fprintf(fp_errorLog, "%s() success. Returned pointer to heap.\n", __func__);
    }

    return ptr; 
}