typedef enum {BLACK_TURN, WHITE_TURN, END} GameStatus;

typedef struct {


    char rowLabels[8];
    char columnLabels[8];
    char Board[8][8];

} board;

typedef struct {

    int score;
    char colour;
    char name[15];

} Player;
#define PLAYER_STRUCT

#include <stdio.h>
#include "board.h"
#include "Utility.h"
#include "results.h"
#include "game.h"
#include "moveChecking.h"


int main() {

    board gameBoard =   {
                            {'1', '2', '3', '4', '5', '6', '7', '8'},
                            {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
                        };
    Player player1 = {2, 'B'};
    Player player2 = {2, 'W'};
    GameStatus gameStatus = BLACK_TURN;


    initialiseBoard(gameBoard.Board);


    printf("Enter your name(Max: 15 characters) player 1 (Black): ");
    fgets(player1.name, 9, stdin);
    removeNewline(player1.name);

    printf("Enter your name(Max: 15 characters) player 2 (White): ");
    fgets(player2.name, 9, stdin);
    removeNewline(player2.name);


    printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.name, player1.score, player2.name, player2.score);
    printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);


    while (gameStatus != END) {

        if (gameStatus == BLACK_TURN) {

            gameStatus = playGame(&player1, &player2.score, &gameBoard);

            printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.name, player1.score, player2.name, player2.score);
            printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

        }

        if (!anyValidMove(gameBoard.Board, player1.colour) && !anyValidMove(gameBoard.Board, player2.colour))
            gameStatus = END;



        else if (gameStatus == WHITE_TURN) {

            gameStatus = playGame(&player2, &player1.score, &gameBoard);

            printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.name, player1.score, player2.name, player2.score);
            printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

        }

        if (!anyValidMove(gameBoard.Board, player1.colour) && !anyValidMove(gameBoard.Board, player2.colour))
            gameStatus = END;

    }


    printResult(player1.score, player2.score, player1.name, player2.name);

    FILE *resultPtr;

    if (( resultPtr = fopen("othello-results.txt", "a")) == NULL ) {
        printf("Unable to open file to append results to.");
        return 0;
    }

    else
        appendResult(resultPtr, player1.score, player2.score, player1.name, player2.name);

    printf("\nResult of game appended to file succesfully!");



    return 0;
}

