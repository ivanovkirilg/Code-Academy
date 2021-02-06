/* Задача 3. Какво е грешното на този код?

void my_strcpy(char *t, char *s) {
    for(; *t; t++, s++)
        *s = *t;
}

Проверяваме стойността на символа от оригиналния низ, 
преди да я присвоим на копието. По този начин няма да присвоим '\0'
Има още един проблем: параметрите нямат достатъчно ясни имена.

Стига да добавим на съответното място терминираща нула, работи:

void my_strcpy(char *t, char *s) {
    for(; *t; t++, s++)
        *s = *t;
    *(s+1) = '\0';
}
*/

/* (Задача 6.) Функцията strcpy(s, t), която копира низа t в низа s. */

#include <stdio.h>

void my_strcpy(char *s, char *t) {
    while (*t) {
        *s = *t;
        s++, t++;
    }
}

int main() {
    char originalString[] = "A whole new world!";
    char copyString[32] = "";

    my_strcpy(copyString, originalString);

    printf("%s", copyString);
    
    return 0;
}
