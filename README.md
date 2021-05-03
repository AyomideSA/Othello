# Software Engineering Project 1 Assignment 2 #


# Board
Structure containing a 1x8 array for the column(a-h) labels, another 1x8 array for the row(1-8) labels and an 8x8 array for the actual board.

# Players
A structure consisting of a string of 15 elements, an int to hold a player's score and a char to represent their colour ( 'B'/'W').

# Valid Move Checking 
An 8x2 array with each row representing a certain direction was used to to check a certain move (e.g. {1,1} would represent South East and {0,0} would represent Nourth West).

Checking in a direction ends when either a blank space on the board is found or if a piece of the opponent's colour is found.
