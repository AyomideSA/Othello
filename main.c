#include <stdio.h>
#include "library.h"


typedef enum PlayerColour {BLACK = 0, WHITE = 1 } playerColour;

typedef struct {


    char rowLabels[8];
    char columnLabels[8];
    char Board[8][8];

} board;

typedef struct {

    playerColour colour;
    char playerName[9];

} Player;

int main()
{

    board gameBoard = {
                        {'1','2','3','4','5','6','7','8'},
                        {'a','b','c','d','e','f','g','h'},
                      };
    Player player1;
    Player player2;


    initialiseBoard(gameBoard.Board);
    printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);




    return 0;
}

