//
// Created by ayoso on 12/04/2021.
//

#include "game.h"
#include "board.h"
#include "moveChecking.h"
#include <stdio.h>
#include <time.h>


int playGame(Player * currPlayer, int *nextPlayerScore, board * gameBoard) {

    char action[3];
    int scoreUpdate;
    GameStatus gameStatus;


    printf("\nWhat would you like to do %s?\n", currPlayer->name);

    while ( fgets(action,3,stdin) && !validMove(action, gameBoard->Board, currPlayer->colour) ) {
        printf("Move not valid. Enter different move: ");
        fflush(stdin);
    }
    fflush(stdin);

    if (action[0] == 'p') {

        if (currPlayer->colour == 'B')
            return WHITE_TURN;

        else
            return BLACK_TURN;

    }


    else {

        scoreUpdate = updateScore(currPlayer->colour, action, gameBoard->Board);
        currPlayer->score += scoreUpdate;
        *nextPlayerScore -= scoreUpdate;
        (*nextPlayerScore)++;

        if (boardFull(gameBoard->Board))
            return END;

        else if (currPlayer->colour == 'B')
            return WHITE_TURN;

        else
            return BLACK_TURN;

    }


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





