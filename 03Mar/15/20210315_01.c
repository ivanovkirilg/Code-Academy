/*  Задача 1. Използвайте динамична реализация на стек за въвеждане на поредица 
    от цели положителни числа и нейното извеждане върху екрана в обратен ред. 
    За край на поредицата от клавиатурата се въвежда 0 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int value;
    struct stackNode *next;
} snode_t;

snode_t *start = NULL;

int push(int value);
int pop(void);

int main() {
    int input = 0;
    do {
        scanf(" %d", &input);
        push(input);
    } while (input != 0);

    while (start != NULL) {
        printf("%d ", pop());
    }

    return 0;
}

int push(int value) {
    snode_t *new = (snode_t *) malloc(sizeof(snode_t));
    if (new == NULL) {
        return -1;
    }
    new->value = value;
    new->next = start;
    start = new;
    return 0;
}

int pop(void) {
    if (start == NULL) {
        return 0;
    }
    snode_t *temp = start;
    int value = start->value;
    start = start->next;
    free(temp);
    return value;
}
