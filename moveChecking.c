/*
 * Date: 18/5/21
 *
 * Description: Functions used in checking whether a move is allowed to be made
 */

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


    // row and column characters converted to integers in the range of the board's 2d array (0-7) //
    size_t row = (action[1] - '0')-1;
    size_t col = ((int)action[0]  - 97);


    if (OUT_OF_BOUNDS(row) || OUT_OF_BOUNDS(col)) {
        return 0;
    }

    if ( !EMPTY(board[row][col]) ) {
        return 0;
    }

    // All possible directions to move in on the board //
    size_t directions[8][2] = {
            {-1,0},
            {-1,1},
            {0,1},
            {1,1},
            {1,0},
            {1,-1},
            {0,-1},
            {-1,-1}
    };

    // Current direction to be checked //
    size_t d_row;
    size_t d_col;


    for (size_t i = 0; i < 8; i++) {

        d_row = directions[i][0];
        d_col = directions[i][1];

        // If the next disc is not one of the same colour //
        if (board[row+d_row][col+d_col] != colour) {

            if (directionValid(row,col,directions[i],board,colour))
                return 1; // As long as at least one valid direction is found then move is valid

        }

    }


    return 0;

}



// Checks if changing colours of disc in a certain direction would be allowed //
int directionValid(size_t row, size_t col, size_t direction[], char board[][8], char colour) {

    size_t d_row = direction[0];
    size_t d_col = direction[1];
    int check;

    if (colour == 'W') {
        check = -21;
    } else
        check = 21;

    int opponentColour = colour + check;

    while (!OUT_OF_BOUNDS(row + (2*d_row)) && !OUT_OF_BOUNDS(col + (2*d_col))) {

        // Empty space means that direction is not valid //
        if (EMPTY(board[row + d_row][col + d_col]))
            break;

        // Next two discs checked to see if line of opponent's discs is ended by current player's piece //
        else if ((board[row + d_row][col + d_col] == (opponentColour)) &&
                 (board[row + (2 * d_row)][col + (2 * d_col)] == colour)) {
            return 1;
        }

        // Increments current position in board //
        row += d_row;
        col += d_col;

    }


    return 0;

}


// Checks if there are any possible moves for a player to take //
int anyValidMove(char board[][8], char colour) {

    size_t directions[8][2] = {
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

            // All directions checked for valid move //
            for (k = 0; k < 8; k++) {

                d_row = directions[k][0];
                d_col = directions[k][1];

                if (EMPTY(board[row][col]) && board[row+d_row][col+d_col] != colour) {

                    if (directionValid(row, col, directions[k], board, colour))
                        return 1; // As long as at least one valid direction is found then move is valid

                }

            }

        }

    }


    return 0;

}