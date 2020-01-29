#include "globals.h"

bool FindUnassignedLocation(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t *rowp, uint8_t *colp);
bool isSafe(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t row, uint8_t col, uint8_t num);
void randSeq(uint8_t seq[N]);
bool SolveSudoku(uint8_t grid[GRID_WIDTH][GRID_WIDTH]);
bool UsedInBox(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t boxStartRow, uint8_t boxStartCol, uint8_t num);
bool UsedInCol(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t col, uint8_t num);
bool UsedInRow(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t row, uint8_t num);