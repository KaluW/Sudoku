#ifndef GLOBALS_H
#define GLOBALS_H

#include <tice.h>
#include <keypadc.h>
#include <graphx.h>

#define BLACK 0
#define BLUE 24 //Embedded numbers - numbers you can't change
#define GRAY 222 //Pause menu background?
#define RED 224 //Invalid numbers -- applies to the font color
#define ORANGE 226
#define WHITE 255

#define SUDOKUDRAWX 20 //Draw Position of Sudoku Grid.
#define SUDOKUDRAWY 46

#define UNASSIGNED 0 //Unassigned locations will be labeled as a 0
#define GRID_WIDTH 9 //Width (and height) of the Sudoku Puzzle grid
#define BOX_WIDTH 3 //Size of each "box" in the grid

typedef struct {
    gfx_sprite_t *spr;
	uint8_t xoff;
	uint8_t yoff;
} numbers_t;
extern numbers_t numbers[];

/* 
grid[...][...][0] is the number in the current grid position
if grid[...][...][1] == 0: means that current grid position CAN be edited
if grid[...][...][1] == 1: means that current grid position is embedded into the puzzle and CANNOT be edited
if grid[...][...][1] == 2: means that the number in the current grid position is not valid.

Note that in grid[][][1], the value at that grid position is set to 1 by default. That way, when generating the sudoku grid (from 'generateGrid()'),
	random positions will be selected to become unassigned and will likewise have grid[][][1] changed to 0.
	
 */
extern uint8_t grid[GRID_WIDTH][GRID_WIDTH][2];


//The guesses in each position in the grid. [10] corresponds to the numbers 1-9, and guess[...][...][0] toggles whether to show guesses or not
extern bool guess[GRID_WIDTH][GRID_WIDTH][10];

extern uint16_t level; //how many squares (times two) will be missing: level 10 means there will be 20 squares empty in the puzzle

#endif