#include "globals.h"
#include "solve.h"

void play(void);
void displayGrid(uint8_t grid[GRID_WIDTH][GRID_WIDTH]);
void generateSudoku(uint8_t solution[GRID_WIDTH][GRID_WIDTH], uint8_t grid[GRID_WIDTH][GRID_WIDTH]);
void playSudoku(uint8_t grid[GRID_WIDTH][GRID_WIDTH]);