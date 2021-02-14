/*  Задача 3. Напишете функции, с помощта на които да реализирате динамичен масив от елементи, 
    чиято големина може да се променя по време на изпълнение на програмата. */

/*  Честно казано, не разбрах тази задача напълно, затова просто експериментирах.
    Но научих, че може да има const pointer-и (<type> * const <name>), което е интересно.
    И срещнах причина (дали е добра не знам) да се ползва **void, което преди ме озадачаваше. */

#include <stdio.h>
#include <stdlib.h>

void handleDynamicArrayError(int errorCode) {
    switch (errorCode) {
        case 1:
            printf("Dynamic array creation error!");
            exit(1);
        case 2:
            printf("Dynamic array resizing error!");
            exit(1);
        case 3:
            printf("Dynamic array already deleted!");
            return;
        default:
            exit(1);
    }
}

void *createDynamicArray(void **pointer, size_t size) {
    *pointer = malloc(size);
    if (*pointer == NULL) {
        handleDynamicArrayError(1);
    }
    return *pointer;
}

void *resizeDynamicArray(void **pointer, size_t newSize) {
    *pointer = realloc(*pointer, newSize);
    if (*pointer == NULL) {
        handleDynamicArrayError(2);
    }
    return *pointer;
}

void deleteDynamicArray(void **pointer) {
    static const char deletedArray[] = "DLTDarray";
    static const void * const deleted = deletedArray;
    if (*pointer == deleted) {
        handleDynamicArrayError(3);
        return;
    }
    free(*pointer);
    *pointer = (void*) deleted;
    return;
}

int main() {
    int *pi = NULL;

    createDynamicArray((void**) &pi, 2*sizeof(int));
    pi[0] = 5;
    pi[1] = 4;
    printf("%d %d\n", pi[0], pi[1]);

    resizeDynamicArray((void**) &pi, 5*sizeof(int));
    
    for (int i = 0; i < 5; i++) {
        pi[i] = 5-i;
        printf("%d\n", pi[i]);
    }

    deleteDynamicArray((void **) &pi);

    printf("%d\n", pi[0]); /* garbage */

    deleteDynamicArray((void **) &pi); /* error message */
    
    return 0;
}
