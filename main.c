/*
 * Author: Ayomide Sola-Ayodele (ayomide.sola-ayodele@ucdconnect.ie)
 *
 * Date: 18/5/21
 *
 * Description: This program manages a game of othello between two human players.
 *
 * Parameters: 1. The names of both players (Max: 15 Characters each)
 *             2. Every turn a player is asked where they would like to place their disc. Input taken
 *                in the format 1d where '1' is a letter in the range a to h and 'd' a number from 1 to 8
 *
 * Returns: 1. Prints scores of both players and result of game.
 *          2. Appends the date, time and result of the game to a file called "othello-results.txt"
 *
 * Information about Othello can be found at https://en.wikipedia.org/wiki/Reversi#Othello
 *
*/


typedef enum {BLACK_TURN, WHITE_TURN, END} GameStatus; // datatype to represent current game state

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
#define PLAYER_STRUCT // Prevents the definitions of the above structs and enum to occur again in when game.h is included

#include <stdio.h>
#include "board.h"
#include "Utility.h"
#include "results.h"
#include "game.h"
#include "moveChecking.h"


int main() {

    // Column and row labels of board initialised //
    board gameBoard =   {
                            {'1', '2', '3', '4', '5', '6', '7', '8'},
                            {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
                        };
    // Score of players initialised and colours assigned //
    Player player1 = {2, 'B'};
    Player player2 = {2, 'W'};


    initialiseBoard(gameBoard.Board); // Board set to default state as described in othello rules


    printf("Enter your name(Max: 15 characters) player 1 (Black): ");
    fgets(player1.name, 15, stdin);
    removeNewline(player1.name);

    printf("Enter your name(Max: 15 characters) player 2 (White): ");
    fgets(player2.name, 15, stdin);
    removeNewline(player2.name);


    printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.name, player1.score, player2.name, player2.score);
    printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);



    GameStatus gameStatus = BLACK_TURN;
    while (gameStatus != END) {

        if (gameStatus == BLACK_TURN) {

            gameStatus = playGame(&player1, &player2.score, &gameBoard); // State of game returned after player one's (black's) turn is finished

            printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.name, player1.score, player2.name, player2.score);
            printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

        }

        // As stated in othello rules, game ends when both players cannot make a move //
        if (!anyValidMove(gameBoard.Board, player1.colour) && !anyValidMove(gameBoard.Board, player2.colour))
            gameStatus = END;



        else if (gameStatus == WHITE_TURN) {

            gameStatus = playGame(&player2, &player1.score, &gameBoard); // State of game returned after player two's (white's) turn is finished

            printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.name, player1.score, player2.name, player2.score);
            printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

        }

        if (!anyValidMove(gameBoard.Board, player1.colour) && !anyValidMove(gameBoard.Board, player2.colour))
            gameStatus = END;

    }



    printResult(player1.score, player2.score, player1.name, player2.name);

    FILE *resultPtr;

    // No point in continuing program if file can't be opened //
    if (( resultPtr = fopen("othello-results.txt", "a")) == NULL ) {
        printf("Unable to open file to append results to.");
        return -1;
    }

    else
        appendResult(resultPtr, player1.score, player2.score, player1.name, player2.name); // Result of game appended to opened file

    printf("\nResult of game appended to \"othello-results.txt\" file succesfully!");

    return 0;

}