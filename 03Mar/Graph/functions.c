#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_VISITS 4

struct tagGraph {
    int vertexCount;
    char *vertices;
    char *adjecencyMatrix;
    short *priorities;
};

/* USER MENU AND INTERFACE */

/* GENERATE A GRAPH STRUCT FROM A FILE */

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
        free(new);
        return NULL;
    }

    new->adjecencyMatrix = (char *) malloc(new->vertexCount * new->vertexCount);
    checkAllocationError(new->adjecencyMatrix, "adjacency matrix", return NULL);

    for (int i = 0; i < new->vertexCount; i++) {
        fgets(line, lineLen, from);
        if (fillMatrixFromString(new, i * new->vertexCount, line) == -1) {
            free(new->adjecencyMatrix), free(new);
            return NULL;
        }
    }

    #ifdef DEBUG
    printf("%.*s\n%.*s\n", new->vertexCount, new->vertices, new->vertexCount * new->vertexCount, new->adjecencyMatrix);
    #endif

    if (calculateVertexPriorities(new) == -1) {
        free(new);
        return NULL;
    }

    return new;
}

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
            if (string[j] != '0' && string[j] != '1') {
                printf("Invalid symbol in adjacency matrix.\n");
                return -1;
            }
            graph->adjecencyMatrix[i] = string[j];
            i++;
        }
    }
    return 0;
}

int calculateVertexPriorities(graph_t *graph) {
    graph->priorities = (short *) malloc(sizeof(short) * graph->vertexCount);
    checkAllocationError(graph->priorities, "vertex priority list", return -1);
    
    for (int i = 0; i < graph->vertexCount; i++) {
        graph->priorities[i] = graph->vertexCount;

        for (int j = 0; j < graph->vertexCount; j++) {
            if (graph->adjecencyMatrix[j * graph->vertexCount + i] == '1') {
                graph->priorities[i]--;
            }
        }
        if (graph->priorities[i] == graph->vertexCount) {
            printf("Found an isolated vertex in the graph.\n");
            free(graph->priorities);
            return -1;
        }
        #ifdef DEBUG
        printf("%c: %d\t", graph->vertices[i], graph->priorities[i]);
        #endif
    }
    return 0;
}

/* FIND PATHS IN A GRAPH */

char *findWalkFromVertex(graph_t *graph, int vertex) {
    size_t walkLength = graph->vertexCount;
    char *walk = (char *) malloc(walkLength);
    checkAllocationError(walk, "a new walk", return NULL);
    
    char *visitedArray = (char *) calloc(graph->vertexCount, sizeof(char));
    checkAllocationError(visitedArray, "a new walk", return NULL);

    int steps = 0, visitedCount = 1;
    walk[0] = graph->vertices[vertex];
    visitedArray[vertex] = 1;

    do {
        if (walkLength == steps + 2) {
            walk = (char *) realloc(walk, walkLength *= 1.5);
            checkAllocationError(walk, "a full walk", return NULL);
        }

        vertex = findBestVertexFrom(graph, vertex, visitedArray);
        #ifdef DEBUG
        if (vertex == -1) printf("IMPOSSIBLE\n");
        #endif

        steps++;
        walk[steps] = graph->vertices[vertex];
        if (visitedArray[vertex] == 0) {
            visitedCount++;
        }
        visitedArray[vertex]++;
        
    } while (visitedCount < graph->vertexCount);

    walk[steps + 1] = '\0';

    free(visitedArray);

    return walk;
}

int findBestVertexFrom(graph_t *graph, int vertex, char *visited) {
    int bestVertex = -1, bestPriority = 0;

    for (int v = 0; v < MAX_VISITS; v++) {
        for (int i = 0; i < graph->vertexCount; i++) {
            if (graph->adjecencyMatrix[vertex * graph->vertexCount + i] == '1') {
                if ((graph->priorities[i] > bestPriority) && (visited[i] <= v)) {
                    bestVertex = i;
                    bestPriority = graph->priorities[bestVertex];
                }
            }
        }
        if (bestVertex != -1) {
            break;
        }
    }

    return bestVertex;
}
