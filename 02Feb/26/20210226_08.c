/*  Задача 8. Напишете програма, която да създаде стек (LIFO) по подобие на този от лекция 18, 
    който обаче да бъде реализиран с динамично с динамично заделяне на памет съобразно 
    желанието на потребителя с функциите malloc(), и free(). Стека да има следните функции (следното API): 
        create(), destroy(), 
        push(), pop(), top(), 
        isFull(), isEmpty() */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    unsigned top;
    const size_t size;
    unsigned char pushErr:1;
    unsigned char popErr:1;
    unsigned char topErr:1;
    unsigned char allocErr:1;
} Stack;

Stack create(unsigned elements);
void destroy(Stack stack);
int isFull(Stack stack);
int isEmpty(Stack stack);
void push(int value, Stack *stack);
int pop(Stack *stack);
int top(Stack *stack);

int main() {
    Stack myStack = create(5);
    if (myStack.allocErr) exit(1); /* Error handling is left to the programmer */

    printf("Filling stack...\n");
    push(12, &myStack);
    push(10, &myStack);
    push(8, &myStack);
    push(6, &myStack);
    push(4, &myStack);
    printf("Top: %d\n", top(&myStack));
    printf("isFull: %d\n", isFull(myStack));
    printf("Push error: %d before pushing 6-th element\n", myStack.pushErr);
    push(2, &myStack);
    printf("Top: %d (unchanged)\n", top(&myStack));
    printf("Push error: %d after pushing 6-th element\n", myStack.pushErr);
    printf("Pop: %d\n", pop(&myStack));
    printf("Pop: %d\n", pop(&myStack));
    printf("Emptying...\n");
    pop(&myStack);
    pop(&myStack);
    printf("Pop: %d (bottom element)\n", pop(&myStack));
    printf("Pop error: %d before popping empty stack\n", myStack.popErr);
    printf("Pop: %d (empty stack)\n", pop(&myStack));
    printf("Pop error: %d after popping empty stack\n", myStack.popErr);

    return 0;
}

/* Defines a new Stack with requested size */
/* On error, sets error flag and returns empty stack with NULL pointer */
Stack create(unsigned elements) {
    Stack newStack = { NULL, 0, elements, 0, 0, 0, 0 };
    newStack.data = (int *) malloc(elements * sizeof(int));
    if (newStack.data == NULL) {
        printf("Could not allocate requested memory\n");
        newStack.allocErr = 1;
    }
    return newStack;
}

void destroy(Stack stack) {
    free(stack.data);
}

int isFull(Stack stack) {
    return (stack.top < stack.size) ? 0 : 1;
}

int isEmpty(Stack stack) {
    return (stack.top > 0) ? 0 : 1;
}

/* Pushes value to the top */
/* On error, only sets error flag */
void push(int value, Stack *stack) {
    if (!isFull(*stack))
        stack->data[stack->top++] = value;
    else
        stack->pushErr = 1;
}

/* Returns top value and removes it from stack */
/* Returns garbage value if stack is empty */
int pop(Stack *stack) {
    if (!isEmpty(*stack)) 
        return stack->data[--stack->top];
    else {
        stack->popErr = 1;
        return stack->data[stack->top];
    }
}

/* Returns current top value */
/* Returns garbage value if stack is empty */
int top(Stack *stack) {
    if (!isEmpty(*stack))
        return stack->data[stack->top-1];
    else {
        stack->topErr = 1;
        return stack->data[stack->top];
    }
}
