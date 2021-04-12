//
// Created by ayoso on 09/04/2021.
//
#include <stdio.h>
#include "board.h"

void initialiseBoard(char board[][8]) {


    for (size_t i = 0; i < 8; i++) {

        for (size_t j = 0; j < 8; j++)
            board[i][j] = '.';

    }

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

