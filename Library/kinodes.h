#ifndef KINODES_GUARD
#define KINODES_GUARD

typedef struct tagNode {
    int content;
    struct tagNode *p;
} t_node;

t_node *generateNodes(int n, int (*fillFunction)(int nodeIndex));
void destroyNodes(t_node *firstNode);
t_node *moveAlongNodes(t_node *node, unsigned int movement);

#endif