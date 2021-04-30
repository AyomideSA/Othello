//
// Created by ayoso on 12/04/2021.
//
#ifndef PLAYER_STRUCT
#define PLAYER_STRUCT

typedef struct {


    char rowLabels[8];
    char columnLabels[8];
    char Board[8][8];

} board;

#endif

#ifndef SOFTWARE_PROJECT_2_20338061_GAME_H
#define SOFTWARE_PROJECT_2_20338061_GAME_H
#include <stdio.h>
int updateScore(char colour, char action[], char board[][8]);
int validMove(char action[], char board[][8], char colour);
int anyValidMove(char board[][8], char colour);
int directionValid(int row, int col, int direction[], char board[][8], char colour);
int changeDiscs(int row, int col, int direction[], char board[][8], char colour);
int boardFull (char board[][8]);
void printResult(int scoreBlack, int scoreWhite);
void appendResult(FILE* resultPtr, int scoreBlack, int scoreWhite, char nameBlack[9], char nameWhite[9]);

#endif //SOFTWARE_PROJECT_2_20338061_GAME_H


