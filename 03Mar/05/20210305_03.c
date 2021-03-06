/*Задача 3. С увеличаване на надморската височина температурата намалява с
около 0,5ºC на всеки 100м. Нека приемем, че атмосферното налягане е нормално.
Ако се знае температурата (ХºC) на хижа Вихрен (1950 метра над морското
равнище), да се изчисли каква е температурата на връх Вихрен (2918 метра над
морското равнище). Ако се знае температурата (УºC) на връх Вихрен, да се изчисли
каква е температурата на хижа Вихрен.
Изход 1:
Ако атмосферното налягане е нормално и температурата на хижа Вихрен (1950м
н.м.р.) е ... ºC , то температурата на връх Вихрен (2918м н.м.р.) е ... ºC.
Изход 2:
Ако атмосферното налягане е нормално и температурата на връх Вихрен (2918м
н.м.р.) е ... ºC , то температурата на хижа Вихрен (1950м н.м.р.) е ... ºC.*/

#include <stdio.h>
#define TEMPERATURE_DIFFERENCE ( ((float)(2918-1950)/100) * 0.5)
int input(float *startingTemp);
float calcTempreture(float startingTemp, int choice);

int main(void){
    float startingTemp = 0;

    int choice = input(&startingTemp);  

    if(choice == 1){
        printf("If the atmospheric pressure is normal and the temperature of Vihren hut is %.2f\n\
        then the temperature of Vihren peak is %.2f ºC\n", startingTemp, calcTempreture(startingTemp, choice));
    } else{
        printf("If the atmospheric pressure is normal and the temperature of Vihren peak is %.2f\n\
        then the temperature of Vihren hut is %.2f ºC\n", startingTemp, calcTempreture(startingTemp, choice));
    }
   
    return 0;
}
int input(float *startingTemp){ 
    int choice = 0;

    /*asks the user for wich one he want to the tempreture */
    do{
        printf("\nEnter for wich one you want to chek the tempreture:\n");
        printf("\tPress 1 for peak Vihren\n");
        printf("\tPress 2 for Vihren hut\n");
        scanf("%d", &choice);

        if(choice < 1 || choice > 2 ){
            printf("Invalid startingTemp! Please try again.\n");
        }
    } while(choice < 1 || choice > 2 );

    /*asks the user about the temperature in the hut if he wants the temperature at the top and the opposite*/
    (choice == 1) ? printf("Enter the tempreture in hut Vihren.\n") : printf("Enter the tempreture in peak Vihren.\n");
    scanf("%f", startingTemp);

    return choice;
}
float calcTempreture(float startingTemp, int choice){
    float tempreture = 0.0;

    switch(choice){
        case 1: tempreture = startingTemp - TEMPERATURE_DIFFERENCE;
            break;
        case 2: tempreture = startingTemp + TEMPERATURE_DIFFERENCE;
            break;
    }

    return tempreture;
}