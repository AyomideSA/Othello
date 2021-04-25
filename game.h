//
// Created by ayoso on 12/04/2021.
//


#ifndef SOFTWARE_PROJECT_2_20338061_GAME_H
#define SOFTWARE_PROJECT_2_20338061_GAME_H
#include <stdio.h>
int updateScore(char colour, char action[], char board[][8]);
int validMove(char action[], char board[][8], char colour);
int anyValidMove(char board[][8], char colour);
int directionValid(int row, int col, int d_row, int d_col, char board[][8]);
int changeDiscs(int row, int col, int d_row, int d_col, char board[][8]);


#endif //SOFTWARE_PROJECT_2_20338061_GAME_H
