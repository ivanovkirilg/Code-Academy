#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int content;
    struct tagNode *p;
} t_node;

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