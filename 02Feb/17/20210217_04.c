/* Задача 4. Стек с решение */

#include <stdio.h>

#define STACK_SIZE 16
int stack[STACK_SIZE];
int top = -1;

int isEmpty(void) {
    return (top == -1) ? 1 : 0;
}

int isFull(void) {
    /* the max index is the max size - 1! otherwise we go outside the array! */
    return (top == STACK_SIZE - 1) ? 1 : 0;
}

int peek(void) {
    /* without this check, we may read an address we have not been assigned! */
    return (!isEmpty()) ? stack[top] : __INT_MAX__;  
}

int push(int data) {
    if (!isFull()) {
        stack[++top] = data;
        return 0; /* indicate success */
    } else {
        printf("The stack is full! Data not pushed.\n");
        return (data) ? data : 1; /* return non-zero when failed */
    }
}

int pop(void) {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("The stack is empty! Nothing to pop.\n");
        return __INT_MAX__; /* int return type function without a return statement?? isn't this bad practice? */
    }
}

int main() {
    int i = 1;
    while (!isFull()) {
        push(i);
        i *= 2;
    }
    
    printf("Top element: %d\n", peek());
    push(1);
    printf("Top element: %d\n", peek());
    pop();
    printf("Next one down: %d\n", pop());

    while (!isEmpty()) {
        printf("%d\n", pop());
    }
    pop();

    return 0;
}
