//
// Created by ayoso on 12/04/2021.
//

#include "game.h"
#include <stdio.h>
#define OUT_OF_BOUNDS(x) ((x) > 7 || (x) < 0)

int validMove(char action[], char board[][8], char colour) {

    //if ( (action[0] == 'p') && !anyValidMove(board,colour))
      //  return 1;

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
                              {0,0}
                            };


    if (board[row][col] == 'W' || board[row][col] == 'B') {
        return 0;
    }

    if (OUT_OF_BOUNDS(row) || OUT_OF_BOUNDS(col)) {
        return 0;
    }

    size_t d_row;
    size_t d_col;


    for (size_t i = 0; i < 8; i++) {

        d_row = directions[i][0];
        d_col = directions[i][1];

        if (board[row+d_row][col+d_col] != colour) {

            if (directionValid(row,col,directions[i],board,colour) == 1)
                return 1;

        }

    }


    return 0;
}

int updateScore(char colour, char action[], char board[][8]) {

    size_t row = (action[1] - '0')-1;
    size_t col = ((int)action[0]  - 97);

    size_t d_row;
    size_t d_col;
    int score  = 0;

    int directions[8][2] = {
            {-1,0},
            {-1,1},
            {0,1},
            {1,1},
            {1,0},
            {1,-1},
            {0,-1},
            {0,0}
    };


    for (size_t i = 0; i < 8; i++) {

        d_row = directions[i][0];
        d_col = directions[i][1];

        if (board[row+d_row][col+d_col] != colour) {

            if (directionValid(row,col, directions[i],board,colour))
                score += changeDiscs(row,col,directions[i],board,colour);

        }

    }

    return score;

}

int directionValid(int row, int col, int direction[], char board[][8], char colour) {

    int d_row = direction[0];
    int d_col = direction[1];
    int check;

    if (colour == 'W') {
        check = -21;
    } else
        check = 21;

    while (!OUT_OF_BOUNDS(row + d_row) && !OUT_OF_BOUNDS(col + d_col)) {

        if (board[row + d_row][col + d_col] == '.')
            break;

        else if ((board[row + d_row][col + d_col] == (colour + check)) &&
                 (board[row + (2 * d_row)][col + (2 * d_col)] == colour)) {
            return 1;
        }

        d_row = d_row + d_row;
        d_col = d_col + d_col;

    }


    return 0;

}

int changeDiscs(int row, int col, int direction[], char board[][8], char colour) {

    int score = 0;

    board[row][col] = colour;
    score++;

    row += direction[0];
    col += direction[1];
    int check;


    if (colour == 'W') {
        check = -21;
    } else
        check = 21;

    while (board[row][col] != colour) {


        board[row][col] = colour;

        row += direction[0];
        col += direction[1];
        score++;

    }


    return score;

}
