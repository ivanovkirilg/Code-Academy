#include <stdio.h>
#include <ctype.h> /* for toupper() */
#include <stdlib.h> /* for system("cls") */

#define LEVEL_X 32
#define LEVEL_Y 16
/* SPRITES */
#define PLAYER 'T'
#define BORDER '#'
/* INPUTS */
#define inUP 'W'
#define inDOWN 'S'
#define inLEFT 'A'
#define inRIGHT 'D'

char g_levelContents[LEVEL_X*LEVEL_Y];
void setUpBlankLevel(void);
void draw(void);

unsigned short g_playerPosition;
char g_input;
void movePlayer(void);

int main() {
    setUpBlankLevel();
    g_levelContents[g_playerPosition = 70] = PLAYER;
    
    draw();
    
    while (1){
        movePlayer();
        draw();
    }
    

    return 0;
}

void setUpBlankLevel(void) {
    int i;
    for (i = 0; i < sizeof(g_levelContents); i++) {
        if ( i<LEVEL_X-1 || !(i%LEVEL_X) || !( (i+2)%LEVEL_X ) || i>LEVEL_X*(LEVEL_Y-1) ) g_levelContents[i]=BORDER;
        else if (!( (i+1)%LEVEL_X )) g_levelContents[i]='\n';
        else g_levelContents[i] = ' ';
    }
    g_levelContents[LEVEL_X*LEVEL_Y-1] = '\0';
}

void draw(void) {
    system("cls");
    int i;
    for (i = 0; i < sizeof(g_levelContents); i++) {
        putchar(' ');
        putchar(g_levelContents[i]);
    }
    putchar('\n');
}

void movePlayer(void) {
    fflush(stdin);
    g_input = toupper(getchar());
    g_levelContents[g_playerPosition] = ' ';
    switch (g_input) {
        case inUP:
            if (g_levelContents[g_playerPosition-LEVEL_X]==' ')
                g_playerPosition -= LEVEL_X; 
            break;
        case inDOWN: 
            if (g_levelContents[g_playerPosition+LEVEL_X]==' ')
                g_playerPosition += LEVEL_X; 
            break;
        case inLEFT: 
            if (g_levelContents[g_playerPosition-1]==' ')
                g_playerPosition--; 
            break;
        case inRIGHT: 
            if (g_levelContents[g_playerPosition+1]==' ')
                g_playerPosition++; 
            break;
    }
    g_levelContents[g_playerPosition] = PLAYER;
}
