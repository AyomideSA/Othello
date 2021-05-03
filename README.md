# Software Engineering Project 1 Assignment 2 #


# Board
Structure containing a 1x8 array for the column(a-h) labels, another 1x8 array for the row(1-8) labels and an 8x8 array for the actual board.
Each player's piece on the board is represented by 'B'(black) or 'W'(white).
When a location on the board is empty '.' is used to represent this.

# Players
A structure consisting of a string of 15 elements, an int to hold a player's score and a char to represent their colour ( 'B'/'W').

# Status of Game
An enumeration with the values BLACK_TURN, WHITE_TURN and END was used to keep track of the current state of the game

# Valid Move Checking 
An 8x2 array with each row representing a certain direction was used to to check a certain move (e.g. {1,1} would represent South East and {0,0} would represent Nourth West).

Checking in a direction ends when either a blank space on the board is found, the checking has gone out of bounds or when a disk of the opponent's colour is found.

# Passing
When a player enters 'p' a function is called that checks all directions around every location on the board. If even one valid move is found the player's request to pass is rejected

# Reaching the game's end
A game ends in one of two ways:
1. When the board is full
2. When both players can't make a move

After every valid move a player makes two things happen.
1. The state if the board is checked. If even one space on the board is empty ('.') the game continues, otherwise the game ends.
2. Similarly to when checking if a player is allowed to pass, the whole board is checked for any valid moves but this time for both players instead of just the current player. If both players are unable to make a move then the game is forced to end early




