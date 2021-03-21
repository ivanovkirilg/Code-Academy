#include <stdio.h>

#define checkAllocationError(ptr, object, action) \
            if ((ptr) == NULL) { \
                printf("Failed to allocate memory for " object ".\n"); \
                action; \
            }

typedef struct tagGraph graph_t;

FILE *chooseFile(void);
void printWalk(const char *walk);
int strend(const char *string, const char *ending);

graph_t *generateGraphFromFile(FILE *from);
int countVertices(const char *string);
int createVerticesFromString(graph_t *emptyGraph, const char *from);
int fillMatrixFromString(graph_t *graph, int pos, const char *string);
int calculateVertexPriorities(graph_t *graph);
void destroyGraph(graph_t *graph);

char *findWalkFromVertex(graph_t *graph, int vertex);
int findBestVertexFrom(graph_t *graph, int vertex, char *visited);
