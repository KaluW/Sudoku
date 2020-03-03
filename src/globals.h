#ifndef GLOBALS_H
#define GLOBALS_H

#include <tice.h>

#define BLACK 0
#define BLUE 24 //INSET numbers - numbers you can't change
#define GRAY 222 //Pause menu background?
#define RED 224
#define WHITE 255

#define SUDOKUDRAWX 20 //Draw Position of Sudoku Grid.
#define SUDOKUDRAWY 46

#define UNASSIGNED 0 //Unassigned locations will be labeled as a 0
#define GRID_WIDTH 9 //Width (and height) of the Sudoku Puzzle grid
#define BOX_WIDTH 3 //Size of each "box" in the grid

#define LEVEL 45

extern uint8_t playGrid[GRID_WIDTH][GRID_WIDTH];
extern uint8_t solvedGrid[GRID_WIDTH][GRID_WIDTH];
extern uint8_t seq[GRID_WIDTH];

#endif