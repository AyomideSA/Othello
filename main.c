#include <stdio.h>
#include "board.h"
#include "Utility.h"
#define PLAYER_STRUCT
#include "game.h"


typedef enum {BLACK_TURN, WHITE_TURN, END} GameStatus;


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

int main() {

    board gameBoard =   {
                        {'1', '2', '3', '4', '5', '6', '7', '8'},
                        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
                        };
    Player player1 = {2, 'B'};
    Player player2 = {2, 'W'};
    char action[3];
    int scoreUpdate;
    int passCount = 0;
    GameStatus gameStatus = BLACK_TURN;


    initialiseBoard(gameBoard.Board);

    /* TEST
    for (size_t i = 0; i < 8; i++) {

        for (size_t j = 0; j < 8; j++)
            gameBoard.Board[i][j] = 'W';

    }

    gameBoard.Board[0][0] = '.';
    gameBoard.Board[0][1] = '.';
    gameBoard.Board[0][7] = 'B';
    END TEST */

    printf("Enter your name player 1 (Black): ");
    fgets(player1.playerName,9,stdin);
    removeNewline(player1.playerName);

    printf("Enter your name player 2 (White): ");
    fgets(player2.playerName,9,stdin);
    removeNewline(player2.playerName);


    printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
    printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);


    while (gameStatus != END) {

        if (gameStatus == BLACK_TURN) {

            printf("\nWhat would you like to do %s?\n", player1.playerName);

            while ( fgets(action,3,stdin) && !validMove(action,gameBoard.Board,player1.colour) ) {
                printf("Move not valid. Enter different move: ");
                fflush(stdin);
            }
            fflush(stdin);



            if (action[0] == 'p') {
                gameStatus = WHITE_TURN;
                passCount++;
            }


            else {

                passCount = 0;
                scoreUpdate = updateScore(player1.colour, action, gameBoard.Board);
                player1.score += scoreUpdate;
                player2.score -= scoreUpdate;
                player2.score++;

                if (boardFull(gameBoard.Board))
                    gameStatus = END;

                else
                    gameStatus = WHITE_TURN;


            }


            printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
            printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

        }

        if (!anyValidMove(gameBoard.Board, player1.colour) && !anyValidMove(gameBoard.Board, player2.colour))
            gameStatus = END;



        else if (gameStatus == WHITE_TURN) {

            printf("\n\nWhat would you like to do %s?\n", player2.playerName);
            while ( fgets(action,3,stdin) && !validMove(action,gameBoard.Board,player2.colour) ) {
                printf("Move not valid. Enter different move: ");
                fflush(stdin);
            }
            fflush(stdin);

            if (action[0] == 'p') {
                gameStatus = BLACK_TURN;
                passCount++;
            }



            else {

                passCount = 0;
                scoreUpdate = updateScore(player2.colour, action, gameBoard.Board);
                player2.score += scoreUpdate;
                player1.score -= scoreUpdate;
                player1.score++;
                if (boardFull(gameBoard.Board))
                    gameStatus = END;

                else
                    gameStatus = BLACK_TURN;

            }

            printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
            printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

        }

        if (!anyValidMove(gameBoard.Board, player1.colour) && !anyValidMove(gameBoard.Board, player2.colour))
            gameStatus = END;


    }


    printResult(player1.score, player2.score);

    FILE *resultPtr;

    if (( resultPtr = fopen("othello-results.txt", "a")) == NULL ) {
        printf("Unable to open file to append results to.");
        return 0;
    }

    else
        appendResult(resultPtr, player1.score,player2.score,player1.playerName,player2.playerName);

    printf("\nResult of game appended to file succesfully!");




    return 0;
}

/* Valid Move Function Testing */


/*while (action[0] != 'p') {
 *
 *
 *     char clearBuffer[256];
printf("\n\nWhat would you like to do %s?\n", player1.playerName);
fgets(action,3,stdin);
fgets(clearBuffer,256,stdin);

    if (validMove(action, gameBoard.Board, player1.colour)) {
        printf("Valid Move!!!");
    } else {
        printf("Not Valid Move!!!");
    }

    printf("\n\nWhat would you like to do %s?\n", player1.playerName);
    fgets(action,3,stdin);
    fgets(clearBuffer,256,stdin);

}*/

/* Other Valid move test */
/*
    for (size_t i = 0; i < 8; i++) {

        for (size_t j = 0; j < 8; j++) {

            gameBoard.Board[i][j] = 'B';

        }

    }
    gameBoard.Board[0][0] = '.';


printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);

printf("\n\nWhat would you like to do %s?\n", player2.playerName);
while ( fgets(action,3,stdin) && !validMove(action,gameBoard.Board,player2.colour) ) {
    printf("Move not valid. Enter different move: ");
    fgets(clearBuffer,256,stdin);
}
scoreUpdate = updateScore(player2.colour, action, gameBoard.Board);
printf("\n\n\t\t%s (Black): %d || %s (White): %d\n", player1.playerName, player1.score, player2.playerName, player2.score);
printBoard(gameBoard.rowLabels, gameBoard.columnLabels, gameBoard.Board);*/