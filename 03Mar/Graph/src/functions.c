#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


struct tagGraph {
    int vertexCount;
    char *vertices;
    char *adjecencyMatrix;
    short *priorities;
};

/* USER MENU AND INTERFACE */

#define EXTENSION ".txt"
#define DEFAULT_FILENAME "g0.txt"
#define DEFAULT_PATH "data/"
#define FILENAME_SIZE 32
#define PATH_SIZE 38
FILE *chooseFile(void) {
    char fileName[FILENAME_SIZE] = DEFAULT_FILENAME;
    char path[PATH_SIZE] = DEFAULT_PATH;
    printf("Press [enter] to load default file.\n" "Enter filename to load a custom file from %s", path);
    fflush(stdin);
    if (ungetc(getchar(), stdin) != '\n') {
        scanf("%s", fileName);
        if (strend(fileName, EXTENSION) != 0) {
            strcat(fileName, EXTENSION);
        }
    }
    strcat(path, fileName);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Failed to open file %s.\n", path);
        return chooseFile();
    } else {
        #ifdef DEBUG
        printf("Reading from %s\n", path);
        #endif
        return fp;
    }
}
#undef EXTENSION
#undef DEFAULT_FILENAME
#undef DEFAULT_PATH
#undef FILENAME_SIZE
#undef PATH_SIZE

#define VERTICES_PER_LINE 8
void printWalk(const char *walk) {
    int counter = -1;
    do {
        if (counter % VERTICES_PER_LINE == VERTICES_PER_LINE - 1) {
            printf("\n  -> ");
            counter++;
        }
        printf("%c -> ", *walk);
        counter++;
    } while ( *(++walk + 1) != '\0');
    printf("%c\n", *walk);
    return;
}
#undef VERTICES_PER_LINE

int strend(const char *string, const char *ending) {
    string = strrchr(string, *ending);
    if (string == NULL) {
        return -1;
    }
    return strcmp(string, ending);
}

/* GRAPH GENERATION */

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
    checkAllocationError(new->adjecencyMatrix, "adjacency matrix", 
        free(new->vertices); free(new); return NULL);

    for (int i = 0; i < new->vertexCount; i++) {
        fgets(line, lineLen, from);
        if (fillMatrixFromString(new, i * new->vertexCount, line) == -1) {
            free(new->vertices), free(new->adjecencyMatrix), free(new);
            return NULL;
        }
    }

    if (calculateVertexPriorities(new) == -1) {
        free(new->vertices), free(new->adjecencyMatrix), free(new);
        return NULL;
    }

    #ifdef DEBUG
    printf("      %.*s\n", new->vertexCount, new->vertices);
    for (int i = 0; i < new->vertexCount; i++) {
        printf("%c,%2d: %.*s\n", new->vertices[i], new->priorities[i], new->vertexCount, new->adjecencyMatrix + i * new->vertexCount);
    }
    #endif

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
    }

    return 0;
}

void destroyGraph(graph_t *graph) {
    free(graph->priorities);
    free(graph->adjecencyMatrix);
    free(graph->vertices);
    free(graph);
    return;
}

/* FIND PATHS IN A GRAPH */

char *findWalkFromVertex(graph_t *graph, int vertex) {
    if (vertex >= graph->vertexCount) {
        printf("Invalid vertex.\n");
        return NULL;
    }

    size_t walkLength = graph->vertexCount;
    char *walk = (char *) malloc(walkLength);
    char *visitedArray = (char *) calloc(graph->vertexCount, sizeof(char));
    int steps = 0, visitedCount = 1;
    
    checkAllocationError(walk, "a new walk", 
        return NULL);
    checkAllocationError(visitedArray, "a new walk", 
        free(walk); return NULL);

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
    int bestVertex = -1, bestPriority = 0, backupVertex = -1, lowestPriority = graph->vertexCount;

    for (int i = 0; i < graph->vertexCount; i++) {
        if (graph->adjecencyMatrix[vertex * graph->vertexCount + i] == '1') {
            if ((graph->priorities[i] > bestPriority) && (visited[i] == 0)) {
                bestVertex = i;
                bestPriority = graph->priorities[bestVertex];
            } else if (graph->priorities[i] < lowestPriority) {
                backupVertex = i;
                lowestPriority = graph->priorities[backupVertex];
            }
        }
    }
    #ifdef DEBUG
    printf("best: % d(%d), backup: % d(%d)\n", bestVertex, bestPriority, backupVertex, lowestPriority);
    #endif

    if (bestVertex == -1) {
        return backupVertex;
    } else {
        return bestVertex;
    }
}
