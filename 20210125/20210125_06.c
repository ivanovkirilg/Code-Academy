/*  Задача 6. Използвайте функцията getchar(), с която въвеждате 
    текст от клавиатурата, докато не подадете ЕОF(Ctrl+D). Текстът има букви и цифри. 
    Пребройте колко са въведените букви и колко са въведените цифри. 
    Определeте броя на цифрите в стринга, като използвате оператор continue. */

#include <stdio.h>

int main() {
    char c;
    int letterCount = 0, digitCount = 0;

    while ( (c=getchar()) != EOF ) {
        if ( c>='0' && c<='9') {
            digitCount++;
            continue; /* Пропускаме проверката на 17 ред. */
        }
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letterCount++;
        }
    }
    printf("letters: %d, digits: %d", letterCount, digitCount);
    
    return 0;
}
