/*  Задача 7. Хванете дълъг стринг и пребройте колко пъти се среща 
    всяка буква от азбуката в него. Запишете резултата в масив за всяка буква.  */

#include <stdio.h>
#include <ctype.h>

int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
    "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
    "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
    "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
    "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
    "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia "
    "deserunt mollit anim id est laborum.";
    unsigned int alphabet[26] = { 0 };
    char *pChar = text;

    do {
        unsigned int letter = ( (unsigned) tolower(*pChar) ) - 'a';
        if (letter < sizeof(alphabet)) {
            alphabet[letter]++;
        }
    } while (*pChar++);

    for (int i = 0; i < sizeof(alphabet)/sizeof(unsigned int); i++) {
        printf("%c : %u\n", 'a' + i, alphabet[i]);
    }
    
/*  Може ли да оптимизирате тази задача и да не се налага да въртим два цикъла?
    Как бихте направили същото, използвайки case? */

/*  Ако се има предвид да избегнем цикъла, който да принтира резултата, не знам как.
    switch-case пък май е много по-тромаво? */

    return 0;
}