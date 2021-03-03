/*  Задача 11. тайпдефната структура node, съдържаща един член от тип инт и един пойнтер 
    към тип самата структура. Заделете динамично памет за тази структура с malloc. */

/*  Всеки node сочи към следващия, освен последния - той сочи към първия (получаваме кръг).
    API-то включва 1)функция за създаване на кръг от колкото искаме nodes, като можем да подадем
    наша функция, с която да запълним стойностите на всеки node. 2) Функция за унищожаване
    на кръг от nodes, която на теория трябва да работи от кой-да-е node. 3) Фунцкия за придвижване
    напред по кръга с колкото искаме стъпки. */

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int content;
    struct tagNode *p;
} t_node;

t_node *generateNodes(int n, int (*fillFunction)(int nodeIndex));
void destroyNodes(t_node *firstNode);
t_node *moveAlongNodes(t_node *node, unsigned int movement);

/* Example fillFunction() */
int fillWithIndexAsData(int nodeIndex) {
    return nodeIndex + 1; /* Start from 1, rather than 0 */
}

int main() {
    t_node *fiveNodes = NULL; /* this will be our starting node */
    t_node *myNode = NULL; /* current node (will move) */
    
    /* pointer to whatever function we want to fill the contents with */
    int (*fillFunction)(int node) = fillWithIndexAsData;
    
    fiveNodes = generateNodes(5, fillFunction);
    myNode = fiveNodes; /* initialize moveable node */

    printf("Current node: %d\n", myNode->content);
    myNode = moveAlongNodes(myNode, 3);
    printf("3 nodes ahead: %d\n", myNode->content);
    myNode = moveAlongNodes(myNode, 3);
    printf("Another 3 nodes ahead: %d\n(Looped because they are only five.)\n", myNode->content);

    destroyNodes(fiveNodes);

    return 0;
}

t_node *generateNodes(int n, int (*fillFunction)(int nodeIndex)) {
    t_node *firstNode = NULL;
    firstNode = (t_node*) malloc(sizeof(t_node) * n);
    if (firstNode == NULL) {
        printf("Allocation error.\n");
        return NULL;
    }
    for (int i = 0; i < (n - 1); i++) {
        (firstNode + i)->p = firstNode + i + 1;
        (firstNode + i)->content = fillFunction(i);
    }
    (firstNode + n - 1)->p = firstNode;
    (firstNode + n - 1)->content = fillFunction(n-1);

    return firstNode;
}

void destroyNodes(t_node *firstNode) {
    int i = 0;
    while ((firstNode + i)->p != firstNode) {
        free(firstNode + i);
        i++;
    }
    free(firstNode + i);
}

t_node *moveAlongNodes(t_node *node, unsigned int movement) {
    while (movement) {
        node = node->p; /* next node */
        movement--;
    }
    return node;
}