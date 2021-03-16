#include <stdio.h>
#include <stdlib.h>

struct tagNode {
    int data;
    struct tagNode *next;
};

typedef struct tagNode lnode;

struct tagList {
    unsigned length;
    lnode *first;
    lnode *last;
};

typedef struct tagList * list;

list lcreate(void) {
    list new = (list) malloc(sizeof(struct tagList));
    if (new == NULL) {
        fprintf(stderr, "Failed to allocate memory for new list.\n");
        return NULL;
    }
    new->first = new->last = NULL;
    new->length = 0;
    return new;
}

int ldestroy(list l) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to destroy empty list.\n");
        return -1;
    }
    lnode *cur = l->first, *prev;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    l->first = l->last = NULL;
    free(l);
    return 0;
}

int ladd(list l, int data) {
    lnode *new = (lnode*) malloc(sizeof(lnode));
    if (new == NULL) {
        fprintf(stderr, "Failed to allocate memory for element %d.\n", data);
        return -1;
    }
    new->data = data;
    new->next = l->first;
    l->first = new;
    if (l->last == NULL) {
        l->last = new;
    }
    l->length++;
    return 0;
}

int lappend(list l, int data) {
    lnode *new = (lnode*) malloc(sizeof(lnode));
    if (new == NULL) {
        fprintf(stderr, "Failed to allocate memory for element %d.\n", data);
        return -1;
    }
    new->data = data;
    new->next = NULL;
    if (l->last != NULL) {
        l->last->next = new;
    } else {
        l->first = new;
    }
    l->last = new;
    l->length++;
    return 0;
}

int linsindex(list l, int data, unsigned ind) {
    if (ind > l->length) {
        fprintf(stderr, "Index %d is outside of list with length %d.\n", ind, l->length);
        return -1;
    }
    if (ind == l->length) {
        lappend(l, data);
        return 0;
    } else if (ind == 0) {
        ladd(l, data);
        return 0;
    }

    lnode *new = (lnode*) malloc(sizeof(lnode));
    if (new == NULL) {
        fprintf(stderr, "Failed to allocate memory for element %d.\n", data);
        return -1;
    }
    new->data = data;

    lnode *cur = l->first, *prev;
    while (ind--) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = new;
    new->next = cur;
    l->length++;
    return 0;
}

int linsafter(list l, int data, int after) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to insert after %d in empty list.\n", after);
        return -1;
    }
    lnode *cur = l->first;
    while (cur->data != after) {
        cur = cur->next;
        if (cur == NULL) {
            fprintf(stderr, "Tried to insert after missing element %d.\n", after);
            return -1;
        }
    }
    lnode *new = (lnode*) malloc(sizeof(lnode));
    if (new == NULL) {
        fprintf(stderr, "Failed to allocate memory for element %d.\n", data);
        return -1;
    }
    new->data = data;
    if (cur->next == NULL) {
        cur->next = new;
        l->last = new;
        new->next = NULL;
    } else {
        lnode *prev = cur;
        cur = cur->next;
        prev->next = new;
        new->next = cur;
    }
    l->length++;
    return 0;
}

int linsbefore(list l, int data, int before) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to insert before %d in empty list.\n", before);
        return -1;
    }
    if (l->first->data == before) {
        return ladd(l, data);
    }
    lnode *cur = l->first, *prev;
    while (cur->data != before) {
        prev = cur;
        cur = cur->next;
        if (cur == NULL) {
            fprintf(stderr, "Tried to insert before missing element %d.\n", before);
            return -1;
        }
    }
    lnode *new = (lnode*) malloc(sizeof(lnode));
    if (new == NULL) {
        fprintf(stderr, "Failed to allocate memory for element %d.\n", data);
        return -1;
    }
    new->data = data;
    prev->next = new;
    new->next = cur;
    l->length++;
    return 0;
}

int lremvalue(list l, int data) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to remove %d from empty list.\n", data);
        return -1;
    }
    lnode *cur = l->first, *prev;
    if (l->first->data == data) {
        l->first = l->first->next;
        free(cur);
        l->length--;
        return 0;
    }
    do {
        prev = cur;
        cur = cur->next;
        if (cur->data == data) {
            prev->next = cur->next;
            free(cur);
            l->length--;
            return 0;
        }
    } while (cur->next != NULL);

    // fprintf(stderr, "Tried to delete missing element %d from list.\n", data);
    return -1;
}

int lremindex(list l, unsigned ind) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to remove element with index %d from empty list.\n", ind);
        return -1;
    }
    if (ind >= l->length) {
        fprintf(stderr, "Cannot remove element with index %d from list with length %d.\n", ind, l->length);
        return -1;
    }
    lnode *cur = l->first, *prev;
    if (ind == 0) {
        l->first = l->first->next;
        free(cur);
        return 0;
    }
    while (ind--) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
    l->length--;
    return 0;
}

int lgetlen(list l) {
    return l->length;
}

int lfindindex(list l, int data) {
    unsigned ind = 0;
    lnode *cur = l->first;
    do {
        if (cur->data == data) {
            return ind;
        }
        ind++;
    } while ( (cur = cur->next) != NULL );

    // fprintf(stderr, "Element %d not found in list.\n", data);
    return -1;
}

int lreadindex(list l, unsigned index) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to read empty list.\n");
        return -1;
    }
    if (index >= l->length) {
        fprintf(stderr, "Index %d is outside of list with length %d.\n", index, l->length);
        return -1;
    } else if (index == l->length - 1) {
        return l->last->data;
    }
    lnode *cur = l->first;
    while (index--) {
        cur = cur->next;
    }
    return cur->data;
}

int lreadlast(list l) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to read empty list.\n");
        return -1;
    }
    return l->last->data;
}

int lprint(list l) {
    if (l->first == NULL) {
        fprintf(stderr, "Tried to print empty list.\n");
        return -1;
    }
    lnode *cur = l->first;
    do {
        printf("%d ", cur->data);
    } while ((cur = cur->next) != NULL);

    return 0;
}
