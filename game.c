//
// Created by ayoso on 12/04/2021.
//

#include "game.h"
#include <ctype.h>
#include <stdio.h>
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
            {-1,-1}
    };



    for (size_t i = 0; i < 8; i++) {

        d_row = directions[i][0];
        d_col = directions[i][1];

        if (board[row+d_row][col+d_col] != colour) {

            if (directionValid(row,col, directions[i],board,colour))
                score += changeDiscs(row,col,directions[i],board,colour);

        }

    }

    board[row][col] = colour;
    score++;

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

int changeDiscs(int row, int col, int direction[], char board[][8], char colour) {

    int score = 0;


    row += direction[0];
    col += direction[1];

    while (board[row][col] != colour) {


        board[row][col] = colour;

        row += direction[0];
        col += direction[1];
        score++;

    }


    return score;

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
                    //printf("[%d][%d]\n", row,col);
                    if (directionValid(row, col, directions[k], board, colour))
                        return 1;

                }

            }

        }

    }


    return 0;

}

int boardFull (char board[][8]) {

    for (size_t i = 0; i < 8; i++) {

        for (size_t j = 0; j < 8; j++) {

            if (board[i][j] == '.')
                return 0;

        }

    }

    return 1;

}

void printResult(int scoreBlack, int scoreWhite) {

    puts("\n\n---------------------");
    puts("|     Final Score   |");
    puts("|-------------------|");
    puts("|  Black  | White   |");
    printf("   %d       %d      \n", scoreBlack, scoreWhite);
    puts("---------------------\n");

    if (scoreBlack == scoreWhite)
        puts("Game has ended in a draw!");

    else if (scoreBlack > scoreWhite)
        puts("Black has won, well done!");

    else
        puts("White has won, well done!");


}

#include <time.h>
void appendResult(FILE* resultPtr, int scoreBlack, int scoreWhite, char nameBlack[9], char nameWhite[9]) {

    time_t t;
    time(&t);

    if (scoreBlack == scoreWhite) {
        fprintf(resultPtr,"Game ended in a draw.\n"
                          "Black score: %d\n"
                          "White score: %d\n"
                          "Time game was finished: %s\n\n", scoreBlack, scoreWhite, ctime(&t));
    }

    if (scoreBlack > scoreWhite) {
        fprintf(resultPtr,"Black won the game.\n"
                          "Black(%s) score: %d\n"
                          "White(%s) score: %d\n"
                          "Time game was finished: %s\n\n", nameBlack, scoreBlack, nameWhite, scoreWhite, ctime(&t));
    }

    if (scoreBlack < scoreWhite) {
        fprintf(resultPtr,"White won the game.\n"
                          "Black score: %d\n"
                          "White score: %d\n"
                          "Time game was finished: %s\n\n", scoreBlack, scoreWhite, ctime(&t));
    }

}
