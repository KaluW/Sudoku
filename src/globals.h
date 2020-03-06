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

#define LEVEL 0

/* 
grid[...][...][0] is the number in the current grid position
if grid[...][...][1] == 0: means that current grid position CAN be edited
if grid[...][...][1] == 1: means that current grid position is embedded into the puzzle and CANNOT be edited
if grid[...][...][1] == 2: means that the number in the current grid position is not valid.

Note that in grid[][][1], the array value is set to 1 by default. That way, when generating the sudoku grid (from 'generateGrid()'),
	random positions will be selected to become unassigned and will likewise have grid[][][1] changed to 0.
	
 */
extern uint8_t grid[GRID_WIDTH][GRID_WIDTH][2];
extern uint8_t seq[GRID_WIDTH];

#endif