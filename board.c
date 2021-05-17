/*
 * Date: 18/5/21
 *
 * Description: Functions related to game board
 */

#include <stdio.h>
#include "board.h"
#define EMPTY(x) ((x) == '.')


// Sets up board according to othello instructions //
void initialiseBoard(char board[][8]) {

    for (size_t i = 0; i < 8; i++) {

        for (size_t j = 0; j < 8; j++)
            board[i][j] = '.'; // Represents empty position

    }

    // Discs placed according to othello rules //
    board[3][3] = 'W';
    board[3][4] = 'B';
    board[4][3] = 'B';
    board[4][4] = 'W';

}


void printBoard(char rowLabels[], char columnLabels[], char board[][8]) {

    size_t i;

    for (i = 0; i < 8; i++) {

        printf("%c", rowLabels[i]);

        for (size_t j = 0; j < 8; j++) {
            printf("\t%c", board[i][j]);
        }

        printf("\n\n");

    }

    for (i = 0; i < 8; i++)
        printf("\t%c", columnLabels[i]);

}


int boardFull (char board[][8]) {

    for (size_t i = 0; i < 8; i++) {

        for (size_t j = 0; j < 8; j++) {

            if (EMPTY(board[i][j]))
                return 0;

        }

    }


    return 1;

}
