#include <stdio.h>
#include <stdlib.h>

#define checkAllocationError(ptr, object, action) \
            if ((ptr) == NULL) { \
                printf("Failed to allocate memory for " object ".\n"); \
                action; \
            }

typedef struct tagGraph {
    int vertexCount;
    char *vertices;
    char *adjecencyMatrix;
} graph_t;

int countVertices(const char *string) {
    int n = 0;
    for (int i = 0; string[i] != '\n'; i++) {
        if (string[i] != ' ') {
            n++;
        }
    }
    return n;
}

int createVerticesFromString(graph_t *emptyGraph, const char *from) {
    emptyGraph->vertexCount = countVertices(from);
    if ( emptyGraph->vertexCount <= 1 ) {
        printf("Insufficient vertices specified in file.\n");
        return -1;
    }

    emptyGraph->vertices = (char *) malloc(emptyGraph->vertexCount);
    checkAllocationError(emptyGraph->vertices, "names of vertices", return -1);

    for (int i = 0, j = 0; i < emptyGraph->vertexCount; j++) {
        if (from[j] != ' ') {
            emptyGraph->vertices[i] = from[j];
            i++;
        }
    }

    return 0;
}

int fillMatrixFromString(graph_t *graph, int pos, const char *string) {
    for (int i = pos, j = 0; i < graph->vertexCount + pos; j++) {
        if (string[j] != ' ') {
            if (string[j] == '\0' || string[j] == '\n') {
                printf("Insufficient adjacency data in file or bad formatting.\n");
                return -1;
            }
            if (string[j] < '0' || string[j] > '9') {
                printf("Invalid symbol in adjacency matrix.\n");
                return -1;
            }
            graph->adjecencyMatrix[i] = string[j];
            i++;
        }
    }
    return 0;
}

graph_t *generateGraphFromFile(FILE *from) {
    graph_t *new = (graph_t *) malloc(sizeof(graph_t));
    checkAllocationError(new, "graph", return NULL);

    int lineLen = 2;
    while (fgetc(from) != '\n') {
        lineLen++;
    }
    fseek(from, 0L, SEEK_SET);

    char line[lineLen];
    fgets(line, lineLen, from);
    
    if (createVerticesFromString(new, line) == -1) {
        return NULL;
    }

    new->adjecencyMatrix = (char *) malloc(new->vertexCount * new->vertexCount);
    checkAllocationError(new->adjecencyMatrix, "adjacency matrix", return NULL);

    for (int i = 0; i < new->vertexCount; i++) {
        fgets(line, lineLen, from);
        if (fillMatrixFromString(new, i * new->vertexCount, line) == -1) {
            return NULL;
        }
    }

    printf("%s\n%s", new->vertices, new->adjecencyMatrix); /* Debug */
    
    return new;
}

int main() {
    FILE *fp = NULL;
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }

    free(generateGraphFromFile(fp));

    return 0;
}
