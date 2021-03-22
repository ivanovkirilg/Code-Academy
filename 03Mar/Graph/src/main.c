#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    FILE *fp = chooseFile();
    graph_t *userGraph = generateGraphFromFile(fp);
    int userVertex;
    char *userWalk;
    
    int state = STATE_CONT;
    LOOP: do {
        if (userGraph == NULL) {
            printf("Encountered a problem when loading this graph.\n");
            state = STATE_OPEN;
        }

        if (state == STATE_CONT) {
            userVertex = chooseVertex(userGraph);
            userWalk = findWalkFromVertex(userGraph, userVertex);
            if (userWalk == NULL) {
                printf("Encountered a problem when looking for a walk.\n");
                continue;
            }
            printWalk(userWalk);
            free(userWalk);
        }
        
        if (state == STATE_OPEN) {
            if (userGraph != NULL) {
                destroyGraph(userGraph);
            }
            fclose(fp);
            fp = chooseFile();
            userGraph = generateGraphFromFile(fp);
            state = STATE_CONT;
            goto LOOP;
        }
    } while ((state = promptNewWalk()) != STATE_QUIT);

    destroyGraph(userGraph);
    fclose(fp);

    return 0;
}
