/* Задача 2. Структура от обединение и описател */

#include <stdio.h>

enum tagType { INT, STR };
union tagValueHolder {
    int number;
    char string[64];
};

struct tagVariable {
    enum tagType type;
    union tagValueHolder value;
};

int printValue(struct tagVariable *pVar) {
    if (pVar->type == INT) {
        printf("Integer: %d\n", pVar->value.number);
    } else {
        printf("String: %s\n", pVar->value.string);
    }
    return pVar->type;
}

int main() {
    struct tagVariable var0 = { INT, .value.number = 555 };
    struct tagVariable var1 = { STR, .value.string = "555!" };

    /* Correct usage */
    printValue(&var0);
    printValue(&var1);

    /* What happens with wrong types */
    var0.type = STR;
    printValue(&var0);
    var1.type = INT;
    printValue(&var1);
    
    return 0;
}