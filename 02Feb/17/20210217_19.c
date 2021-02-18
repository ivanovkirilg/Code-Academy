/*  Задача 19. Напишете програма, която да създаде стек (LIFO) от 16 елемента, 
    който има следното API: int pop() void push() int top() int isFull() */

/* You may statically modify the size here */
#define SIZE 16
/* The array and position are static because they */
/* are not intended to be accessed outside this file */
static int stack[SIZE] = { 0 };
static int pos = 0;

#define PUSH_ERR 1
#define POP_ERR 2
#define TOP_ERR 3
/* Check this flag for error values defined above */
char g_stackError = 0;

int isFull(void) {
    return (pos < SIZE) ? 0 : 1;
}

/* Pushes value to the top */
/* On error, only sets error flag */
void push(int value) {
    if (pos < SIZE)
        stack[pos++] = value;
    else
        g_stackError = PUSH_ERR;
}

/* Returns top value and removes it from stack */
/* Returns garbage value if stack is empty */
int pop(void) {
    if (pos > 0) 
        return stack[--pos];
    else {
        g_stackError = POP_ERR;
        return stack[pos];
    }
}

/* Returns current top value */
/* Returns garbage value if stack is empty */
int top(void) {
    if (pos > 0)
        return stack[pos-1];
    else {
        g_stackError = TOP_ERR;
        return stack[pos];
    }
}

#undef SIZE
/* You may remove the "undef"s below and use the macros to check for specific error flags */
#undef PUSH_ERR
#undef POP_ERR
#undef TOP_ERR
