//
// Created by ayoso on 01/05/2021.
//

#ifndef SOFTWARE_PROJECT_2_20338061_MOVECHECKING_H
#define SOFTWARE_PROJECT_2_20338061_MOVECHECKING_H

#include <stddef.h>
int validMove(char action[], char board[][8], char colour);
int anyValidMove(char board[][8], char colour);
int directionValid(size_t row, size_t col, size_t direction[], char board[][8], char colour);

#endif //SOFTWARE_PROJECT_2_20338061_MOVECHECKING_H
