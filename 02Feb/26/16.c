/* _  _  _  _  _  _  _  _
   9 10 11 12 13 14 15 16
   1  2  3  4  5  6  7  8
   Да се състави програма, с помощта на която играч може да играе (с право на връщане на ходовете) 
   следната игра СОЛИТЕР: На игралното поле са поставени 16 номерирани пулове и три реда с по осем позиции. 
   Целта е да се извадят от игра всички пулове с изключение на номер 1. Може да се прескача през някой пул 
   на свободна клетка, но не се разрешава движение по диагонал. Например възможни са ходове 1-9; 2-10; 1-2 и т.н. 
   По тази схема 1 прескача 9 и 9х излиза от игра – отстранява се от полето, 
   след това 2 прескача 10 и 10 отпада от играта; по-нататък 1 прескача 2 и 2 излиза от игра. */

#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLUMNS 8
char board[ROWS][COLUMNS] = {
   { 0,  0,  0,  0,  0,  0,  0,  0 },
   { 9, 10, 11, 12, 13, 14, 15, 16 },
   { 1,  2,  3,  4,  5,  6,  7,  8 }
};
// char board[ROWS][COLUMNS] = {
//    { 0,  0,  0,  0,  0,  0,  0,  0},
//    { '@',  '@',  '@',  '@',  '@',  '@',  '@',  '@'},
//    { '@',  '@',  '@',  '@',  '@',  '@',  '@',  '@'}
// };

typedef struct coordinates {
   char x;
   char y;
} coords;
#define HERE(coords) board[coords.y-1][coords.x-1]
#define BELOW(coords) board[coords.y][coords.x-1]
#define TWOBELOW(coords) board[coords.y+1][coords.x-1]
#define ABOVE(coords) board[coords.y-2][coords.x-1]
#define TWOABOVE(coords) board[coords.y-3][coords.x-1]
#define LEFTOF(coords) board[coords.y-1][coords.x-2]
#define TWOLEFTOF(coords) board[coords.y-1][coords.x-3]
#define RIGHTOF(coords) board[coords.y-1][coords.x]
#define TWORIGHTOF(coords) board[coords.y-1][coords.x+1]

unsigned char validMoves = 0;
#define UPBIT 1
#define DOWNBIT 2
#define LEFTBIT 4
#define RIGHTBIT 8

void printBoard(void);
coords choosePiece(void);
void chooseMove(coords piece);

int main() {
	while(1) {
		printBoard();
		chooseMove(choosePiece());
	}
   
   return 0;
}

coords choosePiece(void) {
   coords chosen = { 0, 0 };
   while(1) {
      printf("Enter coordinates of a piece (x y), 0 0 to rewind or 9 9 to quit: ");
      fflush(stdin);
      scanf("%d %d", &(chosen.x), &(chosen.y));
/* MISSING */
      if (chosen.x == 0 && chosen.y == 0) {
         printf("NEED TO IMPLEMENT REWIND.\n");
      } else if (chosen.x == 9 && chosen.y == 9) {
         printf("NEED TO IMPLEMENT QUITTING.\n");
/* FEATURES */
      } else if (chosen.x > COLUMNS || chosen.y > ROWS || chosen.x < 1 || chosen.y < 1) {
         printf("Invalid coordinates.\n");
      } else if (board[chosen.y-1][chosen.x-1] == 0) {
         printf("No piece is present there.\n");
      } else {
			validMoves = 0;
			if (chosen.y > 2 && ABOVE(chosen) > 1 && TWOABOVE(chosen) == 0) {
				validMoves |= UPBIT;
			}
			if (chosen.y < ROWS - 1 && BELOW(chosen) > 1 && TWOBELOW(chosen) == 0) {
				validMoves |= DOWNBIT;
			}
			if (chosen.x > 2 && LEFTOF(chosen) > 1 && TWOLEFTOF(chosen) == 0) {
				validMoves |= LEFTBIT;
			}
			if (chosen.x < COLUMNS - 1 && RIGHTOF(chosen) > 1 && TWORIGHTOF(chosen) == 0) {
				validMoves |= RIGHTBIT;
			}
         if (validMoves) {
				break;
			} else {
				printf("There are no valid moves for this piece.\n");
			}
      }
   }
   return chosen;
}

char checkMove(unsigned char directionBit) {
	if (!(validMoves & directionBit)) {
		printf("Invalid move!\n");
		return 0;
	} else {
		return 1;
	}
}

void chooseMove(coords piece) {
   char input = 0;
   while (input == 0) {
      printf("Select the direction of your move:\n"
      "(u)p, (d)own, (l)eft, (r)ight, or (c)ancel\n");
      fflush(stdin);
      scanf("%c", &input);
		switch(input) {
			case 'u':
				if (input = checkMove(UPBIT)) {
					TWOABOVE(piece) = HERE(piece);
					HERE(piece) = 0;
					ABOVE(piece) = 0;
				}
				break;
			case 'd':
				if (input = checkMove(DOWNBIT)) {
					TWOBELOW(piece) = HERE(piece);
					HERE(piece) = 0;
					BELOW(piece) = 0;
				}
				break;
			case 'l':
				if (input = checkMove(LEFTBIT)) {
					TWOLEFTOF(piece) = HERE(piece);
					HERE(piece) = 0;
					LEFTOF(piece) = 0;
				}
				break;
			case 'r':
				if (input = checkMove(RIGHTBIT)) {
					TWORIGHTOF(piece) = HERE(piece);
					HERE(piece) = 0;
					RIGHTOF(piece) = 0;
				}
				break;
         case 'c':
            break;
			default:
				printf("Invalid move.\n");
				input = 0;
		}
   }
}

void printBoard(void) {
	printf("\n   ");
	for (int colNum = 1; colNum < COLUMNS + 1; colNum++) {
		printf("%2d:", colNum);
	}
	printf("\n");
   for (int i = 0; i < ROWS; i++) {
		printf("%d: ", i+1);
      for (int j = 0; j < COLUMNS; j++) {
         char pos = board[i][j];
			if (pos == 0) {
				printf(" - ");
			} else if (pos < 10) {
				printf(" %c ", pos + '0');
				// printf(" %c ", pos);
			} else {
				printf("1%c ", pos + '0' - 10);
				// printf(" %c ", pos);
			}
		}
      printf("\n");
   }
}