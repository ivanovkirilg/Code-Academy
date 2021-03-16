/*  Задача 2. Напишете функцията за добавяне на елемент в дървото рекурсивно 
    с двоен пойнтер подаван като параметър: void insertKey(int x, struct tree **T) */

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left, *right;
} t_node;

t_node *root = NULL;

// int initializeTree(int data) {
//     if (root != NULL) {
//         printf("Tree already initialized.\n");
//         return -1;
//     }
//     root = (t_node *) malloc(sizeof(t_node));
//     if (root == NULL) {
//         printf("Tree failed to initialize.\n");
//         return -1;
//     }
//     root->data = data;
//     root->left = root->right = NULL;
//     return 0;
// }

t_node **addNode(t_node **from, int data) {
    if (*from == NULL) {
        *from = (t_node *) malloc(sizeof(t_node));
        if (*from == NULL) {
            printf("Failed to allocate memory.\n");
            exit(-1);
        }
        (*from)->data = data;
        (*from)->left = (*from)->right = NULL;
        return from;
    } else if (data < (*from)->data) {
        return addNode(&(*from)->left, data);
    } else {
        return addNode(&(*from)->right, data);
    }
}

int main() {
    addNode(&root, 5);
    addNode(&root, 3);
    addNode(&root, 8);
    addNode(&root, 6);
    
    /*     5     */
    /*    / \    */
    /*   3   8   */
    /*      /    */
    /*     6     */

    return 0;
}

