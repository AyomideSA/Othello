//
// Created by ayoso on 12/04/2021.
//


#ifndef SOFTWARE_PROJECT_2_20338061_GAME_H
#define SOFTWARE_PROJECT_2_20338061_GAME_H
#include <stdio.h>
void playGame(int currPlayerColour, int currPlayerScore, int prevPlayerScore, int playerAction);
int validMove(char action[], char board[][8], char colour);
int checkNorth(size_t row, size_t col, char board[][8], int colour);
int checkSouth(size_t row, size_t column, char board[][8]);
int checkWest(size_t row, size_t column, char board[][8]);
int checkEast(size_t row, size_t column, char board[][8]);
int checkNorthWest(size_t row, size_t column, char board[][8]);
int checkNorthEast(size_t row, size_t column, char board[][8]);
int checkSouthWest(size_t row, size_t column, char board[][8]);
int checkSouthEast(size_t row, size_t column, char board[][8]);

#endif //SOFTWARE_PROJECT_2_20338061_GAME_H
