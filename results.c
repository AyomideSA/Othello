/*
 * Date: 18/5/21
 *
 * Description: For summarising result of game
 *
 */

#include <stdio.h>
#include <time.h>


void printResult(int scoreBlack, int scoreWhite, char nameBlack[15], char nameWhite[15]) {

    puts("\n\n---------------------");
    puts("|     Final Score   |");
    puts("|-------------------|");
    puts("|  Black  | White   |");
    printf("   %d       %d      \n", scoreBlack, scoreWhite);
    puts("---------------------\n");

    if (scoreBlack == scoreWhite)
        puts("Game has ended in a draw!");

    else if (scoreBlack > scoreWhite)
        printf("Black has won, well done %s!", nameBlack);

    else
        printf("White has won, well done %s!", nameWhite);


}


void appendResult(FILE* resultPtr, int scoreBlack, int scoreWhite, char nameBlack[15], char nameWhite[15]) {

    time_t t;
    time(&t);

    if (scoreBlack == scoreWhite) {
        fprintf(resultPtr,"Game ended in a draw.\n"
                          "Black(%s) score: %d\n"
                          "White(%s) score: %d\n"
                          "Time game was finished: %s\n\n", nameBlack, scoreBlack, nameWhite, scoreWhite, ctime(&t));
    }

    if (scoreBlack > scoreWhite) {
        fprintf(resultPtr,"Black won the game.\n"
                          "Black(%s) score: %d\n"
                          "White(%s) score: %d\n"
                          "Time game was finished: %s\n\n", nameBlack, scoreBlack, nameWhite, scoreWhite, ctime(&t));
    }

    if (scoreBlack < scoreWhite) {
        fprintf(resultPtr,"White won the game.\n"
                          "Black(%s) score: %d\n"
                          "White(%s) score: %d\n"
                          "Time game was finished: %s\n\n", nameBlack, scoreBlack, nameWhite, scoreWhite, ctime(&t));
    }

}