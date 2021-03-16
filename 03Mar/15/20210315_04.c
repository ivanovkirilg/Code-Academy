/* Задача 4. Да се изтрият в този ред върховете 1, 7, 12 и 14 от дървото на
*        6
*      5   10
*     3   8  13
*    1   7  11  14
*            12
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left, *right;
} t_node;

t_node *root = NULL;

int initializeTree(int data);
int destroyTree(t_node **start);
int insertNode(int data);

int deleteNode(int data) {
    t_node **current = &root;
    while (data != (*current)->data) {
        if (data < (*current)->data) {
            if ((*current)->left == NULL) {
                printf("%d not found in tree.\n", data);
                return -1;
            } else {
                current = &(*current)->left;
            }
        } else {
            if ((*current)->right == NULL) {
                printf("%d not found in tree.\n", data);
                return -1;
            } else {
                current = &(*current)->right;
            }
        }
    }
    return destroyTree(current);
}

int main() {
    initializeTree(6);
    insertNode(5);
    insertNode(10);
    insertNode(3);
    insertNode(8);
    insertNode(13);
    insertNode(1);
    insertNode(7);
    insertNode(11);
    insertNode(14);
    insertNode(12);

    deleteNode(1);
    deleteNode(7);
    deleteNode(12);
    deleteNode(14);

    destroyTree(&root);

    return 0;
}

int initializeTree(int data) {
    if (root != NULL) {
        printf("Tree already initialized.\n");
        return -1;
    }
    root = (t_node *) malloc(sizeof(t_node));
    if (root == NULL) {
        printf("Tree failed to initialize.\n");
        return -1;
    }
    root->data = data;
    root->left = root->right = NULL;
    return 0;
}

int destroyTree(t_node **start) {
    while (*start != NULL) {
        if ((*start)->left == NULL && (*start)->right == NULL) {
            free(*start);
            *start = NULL;
            return 0;
        } 
        if ((*start)->left) {
            destroyTree(&(*start)->left);
        }
        if ((*start)->right) {
            destroyTree(&(*start)->right);
        }
    }
}

t_node *createNode(int data) {
    t_node *new = (t_node *) malloc(sizeof(t_node));
    if (new == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

int insertNode(int data) {
    t_node *cur = root;
    while (1) {
        if (data < cur->data) {
            if (cur->left == NULL) {
                cur->left = createNode(data);
                return 0;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == NULL) {
                cur->right = createNode(data);
                return 0;
            } else {
                cur = cur->right;
            }
        }
    }
}
