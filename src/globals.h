#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>
#include <fontlibc.h>

//Colors!!!
#define BLACK 0
#define GRAY 222 //Pause menu background?
#define WHITE 255

#define UNASSIGNED 0 //Unassigned locations will be labeled as a 0
#define GRID_WIDTH 9 //Width (and height) of the Sudoku Puzzle grid
#define BOX_WIDTH 3 //Size of each "box" in the grid
#define N 9 //numbers possible: 1-9
#define LEVEL 40 //level * 2 represents the number of given numbers you will have at the beginning of the Sudoku (well, actually...)

extern uint8_t grid[GRID_WIDTH][GRID_WIDTH]; //the grid the player will work with
extern uint8_t solution[GRID_WIDTH][GRID_WIDTH]; //er... the solution