/*  Задача 17. Кое е по добре да купите: А броя дини от сорт мелон с диаметър Х см и дебелина на кората D см 
    или В броя дини с диаметър У см и (същата) дебелина на кората D2? Създайте структура диня с два елемента: 
    диаметър и дебелина на кората. Заделете динамично с malloc() за масив от А на брой дини от сорт мелон и 
    попълнете данните за диаметър между 15 и 140 см с функцията rand(), за всяка една диня в масива, и 
    дебелина на кората между 0.5 и 3.5 см. (Създайте структура диня с два елемента: диаметър и дебелина на кората 
    заделете динамично с malloc() за масив от В на брой дини от) сорт пъмпкин и попълнете данните за диаметър 
    между 35 и 95 см с функцията rand(), за всяка една диня в масива и дебелина на кората между 0.3 и 0.9 см. 
    Намерете средната големина на динята и средната дебелина на кората и ги съпоставете с тези от втория масив. 
    Изведете на екрана купчината от кой сорт е по-добре да се купи. Изход:
        По-добре е да се купят ... дини с диаметър ... сантиметра и кора с дебелина ... см 
        вместо ... дини с диаметър ... см и дебелина на кората ... см. */

/*  Тези дини са ОГРОМНИ. Доста време се чудих какво греша в математиката, но не... по 500л са. 
    Изходът не е точно този, който се иска, защото прецених, че това е по-интересна сметка и по-полезна информация. */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

typedef struct tagMelon {
    int diameter;
    double rind;
} t_mel;

void randomiseMelons(t_mel *melons, size_t numOfMelons, int minDiam, int maxDiam, double minRind, double maxRind) {
    for (int i = 0; i < numOfMelons; i++) {
        melons[i].diameter = minDiam + rand() % (maxDiam - minDiam);
        melons[i].rind = (double) rand() / ((double) RAND_MAX / (maxRind - minRind)) + minRind;
    }
}

double melonsAverage(t_mel *melons, size_t numOfMelons) {
    double averageEdibleLiters;
    for (int i = 0; i < numOfMelons; i++) {
        double edibleRadius = (double) melons[i].diameter/2 - melons[i].rind;
        double edibleVolume = edibleRadius * edibleRadius * edibleRadius * 4.0/3.0 * PI;
        averageEdibleLiters += edibleVolume / 1000;
    }
    return averageEdibleLiters / numOfMelons;
}

int main() {
    t_mel *waterMelons = NULL;
    t_mel *pumpkins = NULL;
    size_t numOfWaterMelons = 0;
    size_t numOfPumpkins = 0;
    double waterMelonsEdibleAverage = 0;
    double pumpkinsEdibleAverage = 0;

    printf("Enter number of watermelons: ");
    scanf("%d", &numOfWaterMelons);
    printf("Enter number of pumpkins: ");
    scanf("%d", &numOfPumpkins);

    waterMelons = (t_mel *) malloc(numOfWaterMelons * sizeof(t_mel));
    pumpkins = (t_mel *) malloc(numOfPumpkins * sizeof(t_mel));
    if (waterMelons == NULL || pumpkins == NULL) {
        printf("Allocation error.\n");
        exit(1);
    }

    randomiseMelons(waterMelons, numOfWaterMelons, 15, 140, 0.5, 3.5);
    randomiseMelons(pumpkins, numOfPumpkins, 35, 95, 0.3, 0.9);
    waterMelonsEdibleAverage = melonsAverage(waterMelons, numOfWaterMelons);
    pumpkinsEdibleAverage = melonsAverage(pumpkins, numOfPumpkins);

    printf("The average edible volume is:\n"
           "Watermelons %.1f l\n" "Pumpkins %.1f l", waterMelonsEdibleAverage, pumpkinsEdibleAverage);

    return 0;
}
