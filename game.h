//
// Created by ayoso on 12/04/2021.
//

#ifndef GAME_STRUCT
#define GAME_STRUCT

typedef struct {


    char rowLabels[8];
    char columnLabels[8];
    char Board[8][8];

} board;

typedef struct {

    int score;
    char colour;
    char name[15];

} Player;

typedef enum {BLACK_TURN, WHITE_TURN, END} GameStatus;

#endif

#ifndef SOFTWARE_PROJECT_2_20338061_GAME_H
#define SOFTWARE_PROJECT_2_20338061_GAME_H

#include <stddef.h>
void printIntroduction(void);
GameStatus playGame(Player * currPlayer, int *nextPlayerScore, board * gameBoard);
int updateScore(char colour, char action[], char board[][8]);
int changeDiscs(size_t row, size_t col, size_t direction[], char board[][8], char colour);

#endif //SOFTWARE_PROJECT_2_20338061_GAME_H


