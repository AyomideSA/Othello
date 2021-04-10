#include <stdio.h>
#include "library.h"
#include "Utility.h"


typedef enum PlayerColour {BLACK = 0, WHITE = 1 } playerColour;

typedef struct {


    char rowLabels[8];
    char columnLabels[8];
    char Board[8][8];

} board;

typedef struct {

    int score;
    playerColour colour;
    char playerName[9];

} Player;

int main()
{

    board gameBoard = {
                        {'1','2','3','4','5','6','7','8'},
                        {'a','b','c','d','e','f','g','h'},
                      };
    Player player1 = {2};
    Player player2 = {2};


    initialiseBoard(gameBoard.Board);

    printf("Enter your name player 1 (Black): ");
    fgets(player1.playerName,9,stdin);
    removeNewline(player1.playerName);

    printf("Enter your name player 2 (White): ");
    fgets(player2.playerName,9,stdin);
    removeNewline(player2.playerName);

    printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
    printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);


    return 0;
}

