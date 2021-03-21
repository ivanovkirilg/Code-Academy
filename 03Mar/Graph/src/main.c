#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    FILE *fp = chooseFile();

    graph_t *userGraph = generateGraphFromFile(fp);

    char *userWalk = findWalkFromVertex(userGraph, 0);

    printWalk(userWalk);

    destroyGraph(userGraph);
    free(userWalk);
    fclose(fp);

    return 0;
}
