/*
 * Date: 18/5/21
 *
 * Description: Core mechanics of the game.
 *
 */

#include "game.h"
#include "board.h"
#include "moveChecking.h"
#include <stdio.h>


// Manages current player's turn and returns state of game //
GameStatus playGame(Player * currPlayer, int *nextPlayerScore, board * gameBoard) {

    char action[3]; // contains a move in the format 1d where 1 is a letter and d is a digit
    int scoreUpdate; // Holds amount to be added to current player's score
    GameStatus gameStatus;


    printf("\nWhat would you like to do %s?\n", currPlayer->name);

    while ( fgets(action,3,stdin) && !validMove(action, gameBoard->Board, currPlayer->colour) ) {
        printf("Move not valid. Enter different move: ");
        fflush(stdin); // Removes leftover input to prevent fgets from reading it
    }
    fflush(stdin);

    if (action[0] == 'p') { // If a player wants to pass their turn

        if (currPlayer->colour == 'B')
            return WHITE_TURN;

        else
            return BLACK_TURN;

    }


    else {

        scoreUpdate = updateScore(currPlayer->colour, action, gameBoard->Board); // Amount that score should be increased by returned
        currPlayer->score += scoreUpdate;

        *nextPlayerScore -= scoreUpdate;  // Other player loses what current player gains due to the rules of othello
        (*nextPlayerScore)++; // scoreUpdate counts the new disc being placed so the next player's score is incremented by one to counter this

        if (boardFull(gameBoard->Board))
            return END;

        else if (currPlayer->colour == 'B')
            return WHITE_TURN;

        else
            return BLACK_TURN;

    }

}


// Calculates how much a player's score should be increased by depending on where their disc was placed //
int updateScore(char colour, char action[], char board[][8]) {

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

    // row and column characters converted to integers in the range of the board's 2d array (0-7) //
    size_t row = (action[1] - '0')-1;
    size_t col = ((int)action[0]  - 97);

    int score  = 0;


    // Goes through every direction from where player's disc has been placed //
    for (size_t i = 0; i < 8; i++) {

        d_row = directions[i][0];
        d_col = directions[i][1];

        // If the next piece is not one of the same colour //
        if (board[row+d_row][col+d_col] != colour) {

            if (directionValid(row,col, directions[i],board,colour))
                score += changeDiscs(row,col,directions[i],board,colour); // Number of discs changed returned

        }

    }


    board[row][col] = colour; // Updates place where player decided to place their piece
    score++;

    return score;

}


// Changes colours of discs in a certain direction on the board. Returns number of discs changed //
int changeDiscs(size_t row, size_t col, size_t direction[], char board[][8], char colour) {

    int score = 0;

    // Disc changing starts from first disc in selected direction //
    row += direction[0];
    col += direction[1];

    // While a disc of the opposing player's colour has not been reached //
    while (board[row][col] != colour) {

        board[row][col] = colour;

        // Increments current position in current direction on board //
        row += direction[0];
        col += direction[1];

        score++;

    }


    return score;

}





