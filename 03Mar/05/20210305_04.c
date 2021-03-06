/*зад.4  Да се състави програма, с помощта на която 2
(3, 1) играчи могат да играят (с право на връщане на
ходовете) следната игра ЛАБИРИНТ: Трябва да се достигне
до финала, отбелязан с F. Числото във всяка клетка
показва броя стъпки по права линия, които могат да са
направят при следващия ход. Като се започне от горния
ляв ъгъл, са възможни само два хода
3324312
2423243
4232421
4412234
3233422
3242321
113342F*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ROWS 7
#define COLS 7
#define LEFT_PL_SYMBOL_ORIGINAL '@'
#define RIGHT_PL_SYMBOL_ORIGINAL '&'

typedef struct {
    int row;
    int col;
} t_coords;

typedef struct {
    char symbol;
    t_coords coords;
    t_coords *firstMove;
    int nMoves;
} t_player;
t_player LeftPlayer = { LEFT_PL_SYMBOL_ORIGINAL, { 0, 0 }, NULL, 1 };
t_player RightPlayer = { RIGHT_PL_SYMBOL_ORIGINAL, { 0, 0 }, NULL, 1 };

void drawArray2D(char *array, t_coords playGroundSize);
char inputMove(t_player Player);
int movePlayer(t_player *Player, char input, char *playGround, t_coords playGroundSize);
void finalMessage(int state);
t_coords *allocMoveMem(void);

int main(void){
    /* Setup */
    char playGround[ROWS][COLS] = {
        {3,3,2,4,3,1,2},
        {2,4,2,3,2,4,3},
        {4,2,3,2,4,2,1},
        {4,4,1,2,2,3,4},
        {3,2,3,3,4,2,2},
        {3,2,4,2,3,2,1},
        {1,1,3,3,4,2,'F'}
    };
    t_coords playGroundSize = { ROWS, COLS };
    LeftPlayer.firstMove = allocMoveMem();
    RightPlayer.firstMove = allocMoveMem();
    
    /* Gameplay */
    int state = 0;
    while (state == 0) {
        drawArray2D((char *) playGround, playGroundSize);
        state += 1 * movePlayer(&LeftPlayer, inputMove(LeftPlayer), (char*) playGround, playGroundSize);
        state += 3 * movePlayer(&RightPlayer, inputMove(RightPlayer), (char*) playGround, playGroundSize);
    }
    /* End */
    drawArray2D((char *) playGround, playGroundSize);
    finalMessage(state);

    free(LeftPlayer.firstMove);
    free(RightPlayer.firstMove);
    
    return 0;
}

void drawLine(unsigned columns) {
    for (int i = 0; i < columns; i++) {
        printf("----");
    }
    printf("-\n");
}

void drawArray2D(char *array, t_coords playGroundSize) {
    char leftChar, rightChar;
    
    drawLine(playGroundSize.col);

    for (int i = 0; i < playGroundSize.row; i++) {
        for (int j = 0; j < playGroundSize.col; j++) {
            leftChar = (LeftPlayer.coords.row == i && LeftPlayer.coords.col == j) ? LeftPlayer.symbol : ' ';
            rightChar = (RightPlayer.coords.row == i && RightPlayer.coords.col == j) ? RightPlayer.symbol : ' ';
            if (array[i * playGroundSize.col + j] == 'F') {
                printf("|%c%c%c", leftChar, array[i * playGroundSize.col + j], rightChar);
            } else {
                printf("|%c%d%c", leftChar, array[i * playGroundSize.col + j], rightChar);
            }
        }
        printf("|\n");
        
        drawLine(playGroundSize.col);
    }
}

char inputMove(t_player Player){
    char direction;
    do {
        printf("Insert direction for %c:\n", Player.symbol);
        printf("L for left\t" "R for right\t" "U for up\t" "D for down\tZ to undo\n");
        fflush(stdin);
        scanf("%c", &direction);
        direction = toupper(direction);
        if (direction == 'Z' && Player.nMoves == 1) {
            printf("No moves to undo.\n");
            direction = 0;
        }
    } while (direction != 'L' && direction != 'R' && direction != 'U' && direction != 'D' && direction != 'Z');
    
    return direction;
}

void storeMove(t_player *Player) {
    Player->firstMove[Player->nMoves - 1] = Player->coords;
    Player->nMoves++;
    Player->firstMove = (t_coords *) realloc(Player->firstMove, Player->nMoves * sizeof(t_coords));
    if (Player->firstMove == NULL) {
        printf("Couldn't store new move\n");
        exit(2);
    }
}

void undoMove(t_player *Player) {
    Player->nMoves--;
    Player->coords = Player->firstMove[Player->nMoves - 1];
    Player->firstMove = (t_coords *) realloc(Player->firstMove, Player->nMoves * sizeof(t_coords));
    if (Player->firstMove == NULL) {
        printf("Couldn't reallocate memory\n");
        exit(2);
    }
}

int movePlayer(t_player *Player, char input, char *playGround, t_coords playGroundSize){
    int steps = playGround[Player->coords.row * playGroundSize.col + Player->coords.col];
    switch (input) {
        case 'L':
            storeMove(Player);
            if (steps > Player->coords.col) {
                Player->symbol = ' ';
            } else {
                Player->coords.col -= steps;
            }
            break;
        case 'R':
            storeMove(Player);
            if ( (steps + Player->coords.col) >= playGroundSize.col) {
                Player->symbol = ' ';
            } else {
                Player->coords.col += steps;
            }
            break;
        case 'U':
            storeMove(Player);
            if (steps > Player->coords.row) {
                Player->symbol = ' ';
            } else {
                Player->coords.row -= steps;
            }
            break;
        case 'D':
            storeMove(Player);
            if ( (steps + Player->coords.row) >= playGroundSize.row) {
                Player->symbol = ' ';
            } else {
                Player->coords.row += steps;
            }
            break;
        case 'Z':
            undoMove(Player);
            return 0;
    }
    char position = playGround[Player->coords.row * playGroundSize.col + Player->coords.col];
    if (Player->symbol == ' ') {
        return -1;
    } else if (position == 'F') {
        return 1;
    } else {
        return 0;
    }
}

void finalMessage(int state) {
    switch (state) {
        case -4:
            /* both lose */
            printf("Both players have gone off the board! Draw!\n");
            break;
        case -3:
            /* right loses */
            printf("%c has gone off the board! %c wins!\n", RIGHT_PL_SYMBOL_ORIGINAL, LEFT_PL_SYMBOL_ORIGINAL);
            break;
        case -2:
            /* left wins, right loses */
            printf("%c has reached the finish! %c ran away.\n", LEFT_PL_SYMBOL_ORIGINAL, RIGHT_PL_SYMBOL_ORIGINAL);
            break;
        case -1:
            /* left loses */
            printf("%c has gone off the board! %c wins!\n", LEFT_PL_SYMBOL_ORIGINAL, RIGHT_PL_SYMBOL_ORIGINAL);
            break;
        case 1:
            /* left wins */
            printf("%c wins by finishing!", LEFT_PL_SYMBOL_ORIGINAL);
            break;
        case 2:
            /* right wins, left loses */
            printf("%c has reached the finish! %c ran away.\n", RIGHT_PL_SYMBOL_ORIGINAL, LEFT_PL_SYMBOL_ORIGINAL);
            break;
        case 3:
            /* right wins */
            printf("%c wins by finishing!\n", RIGHT_PL_SYMBOL_ORIGINAL);
            break;
        case 4:
            /* both win */
            printf("Both players have reached the finish! Draw!\n");
            break;
    }
}

t_coords *allocMoveMem(void){
    t_coords *p = NULL;
    p = (t_coords *)malloc(sizeof(t_coords));
    
    if(NULL == p){
        printf("Memory not allocated!\n");
        exit(1);
    }
    return p;
}