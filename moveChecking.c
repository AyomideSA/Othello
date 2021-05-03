//
// Created by ayoso on 01/05/2021.
//

#include "moveChecking.h"
#include <stddef.h>
#include <ctype.h>
#define OUT_OF_BOUNDS(x) ((x) > 7 || (x) < 0)
#define EMPTY(x) ((x) == '.')

int validMove(char action[], char board[][8], char colour) {

    if ( (action[0] == 'p') && !anyValidMove(board,colour))
        return 1;

    if (!isalpha(action[0]) || !isdigit(action[1])) {
        return 0;
    }

    size_t row = (action[1] - '0')-1;
    size_t col = ((int)action[0]  - 97);

    int directions[8][2] = {
            {-1,0},
            {-1,1},
            {0,1},
            {1,1},
            {1,0},
            {1,-1},
            {0,-1},
            {-1,-1}
    };



    if (OUT_OF_BOUNDS(row) || OUT_OF_BOUNDS(col)) {
        return 0;
    }

    if ( !EMPTY(board[row][col]) ) {
        return 0;
    }


    size_t d_row;
    size_t d_col;


    for (size_t i = 0; i < 8; i++) {

        d_row = directions[i][0];
        d_col = directions[i][1];

        if (board[row+d_row][col+d_col] != colour) {

            if (directionValid(row,col,directions[i],board,colour))
                return 1;

        }

    }


    return 0;
}


int directionValid(int row, int col, int direction[], char board[][8], char colour) {

    int d_row = direction[0];
    int d_col = direction[1];
    int check;

    if (colour == 'W') {
        check = -21;
    } else
        check = 21;

    while (!OUT_OF_BOUNDS(row + (2*d_row)) && !OUT_OF_BOUNDS(col + (2*d_col))) {

        if (board[row + d_row][col + d_col] == '.')
            break;

        else if ((board[row + d_row][col + d_col] == (colour + check)) &&
                 (board[row + (2 * d_row)][col + (2 * d_col)] == colour)) {
            return 1;
        }

        row += d_row;
        col += d_col;

    }


    return 0;

}

int anyValidMove(char board[][8], char colour) {

    int directions[8][2] = {
            {-1,0},
            {-1,1},
            {0,1},
            {1,1},
            {1,0},
            {1,-1},
            {0,-1},
            {-1,-1}
    };

    size_t row;
    size_t col;
    size_t d_row;
    size_t d_col;
    size_t k;


    for (row = 0; row < 8; row++) {

        for (col = 0; col < 8; col++) {

            for (k = 0; k < 8; k++) {

                d_row = directions[k][0];
                d_col = directions[k][1];

                if (EMPTY(board[row][col]) && board[row+d_row][col+d_col] != colour) {
                    if (directionValid(row, col, directions[k], board, colour))
                        return 1;

                }

            }

        }

    }


    return 0;

}