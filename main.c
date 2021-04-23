#include <stdio.h>
#include "board.h"
#include "Utility.h"
#include "game.h"


typedef enum {BLACK_TURN = 0, WHITE_TURN = 1, END = 2} GameStatus;

typedef struct {


    char rowLabels[8];
    char columnLabels[8];
    char Board[8][8];

} board;

typedef struct {

    int score;
    char colour;
    char playerName[9];

} Player;

int main()
{

    board gameBoard = {
                        {'1','2','3','4','5','6','7','8'},
                        {'a','b','c','d','e','f','g','h'},
                      };
    Player player1 = {2,'B'};
    Player player2 = {2,'W'};
    char action[3];
    GameStatus gameStatus = BLACK_TURN;


    initialiseBoard(gameBoard.Board);


    printf("Enter your name player 1 (Black): ");
    fgets(player1.playerName,9,stdin);
    removeNewline(player1.playerName);

    printf("Enter your name player 2 (White): ");
    fgets(player2.playerName,9,stdin);
    removeNewline(player2.playerName);


    printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
    printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

    char clearBuffer[256];
    printf("\n\nWhat would you like to do %s?\n", player1.playerName);
    fgets(action,3,stdin);
    fgets(clearBuffer,256,stdin);

    /* Valid Move Function Testing */
    while (action[0] != 'p') {

        if (validMove(action, gameBoard.Board, player1.colour)) {
            printf("Valid Move!!!");
        } else {
            printf("Not Valid Move!!!");
        }

        printf("\n\nWhat would you like to do %s?\n", player1.playerName);
        fgets(action,3,stdin);
        fgets(clearBuffer,256,stdin);

    }


/*
    while (gameStatus != END) {

        if (gameStatus == BLACK_TURN) {

            printf("What would you like to do %s?\n", player1.playerName);
            fgets(action,3,stdin);

            if (action[0] == 'p')
                gameStatus = WHITE_TURN;

            else {

                playGame(BLACK_TURN, &player1.score, &player2.score, action);
                gameStatus = WHITE_TURN;

            }


        }

        else {

            printf("What would you like to do %s?\n", player2.playerName);
            fgets(action,3,stdin);

            if (action[0] == 'p')
                gameStatus = BLACK_TURN;

            else {

                playGame(WHITE_TURN, &player2.score, &player1.score, action);
                gameStatus = BLACK_TURN;

            }

        }

        printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
        printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);


    }*/


    return 0;
}

