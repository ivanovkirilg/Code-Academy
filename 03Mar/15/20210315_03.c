/*  Задача3. Да се построи наредено двоично дърво за търсене чрез 
    последователно добавяне на следните върхове:
        а) 7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13
        б) 12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65
        в) 4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81
        г) 81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4
        д) 28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14
    Да се сравнят получените дървета. Какви изводи могат да се направят? */

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left, *right;
} t_node;

t_node *root = NULL;

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

int givenValues[5][13] = {{ 7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13 },
                          { 12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65 },
                          { 4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81 },
                          { 81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4 },
                          { 28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14 }};

int main() {
    for (int i = 1; i < 5; i++) {
        initializeTree(givenValues[i][0]);

        for (int j = 1; j < 13; j++) {
            insertNode(givenValues[i][j]);
        }

        destroyTree(&root);
    }

    destroyTree(&root);

    return 0;
}