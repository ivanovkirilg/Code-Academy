//Създайте функция vzemiBitna. Функцията получава
//параметър число и индекс. Тя връща стойността на бита
//на съответния индекс.

#include <stdio.h>
#include <stdlib.h>

int vzemiBitna(int number, int index);

int main(int argc, char *argv[]) {
    if (argc == 3) {
        printf("%d\n", vzemiBitna(atoi(argv[1]), atoi(argv[2])));
    } 
    else {
        printf("Usage: %s [number] [bit index]\n", argv[0]);
    }
 
    return 0;
}

int vzemiBitna(int number, int index) {
    return (number >> index) & 1;
}
