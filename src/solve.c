#include "solve.h"

uint8_t seq[N] = {1,4,7,3,6,9,2,5,8}; //used for generating puzzles
	
bool FindUnassignedLocation(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t *rowp, uint8_t *colp) { //row pointer; column pointer
	uint8_t row, col;
	for (row = 0; row < GRID_WIDTH; row ++)
		for (col = 0; col < GRID_WIDTH; col ++)
			if (grid[row][col] == UNASSIGNED) {
				*rowp = row;
				*colp = col; 
				return true;
			}
	return false;
}

bool isSafe(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t row, uint8_t col, uint8_t num) {
	return !UsedInRow(grid, row, num) &&
		   !UsedInCol(grid, col, num) &&
		   !UsedInBox(grid, row - row%BOX_WIDTH, col - col%BOX_WIDTH, num) &&
			grid[row][col] == UNASSIGNED;
}

void randSeq(uint8_t seq[N]) {
	uint8_t a, b, i, rand;
	for(i = 0; i <= 8; i ++) {
		rand = randInt(0,8);
		a = seq[0];
		b = seq[rand];
		seq[0] = b;
		seq[rand] = a;
	}
}

bool SolveSudoku(uint8_t grid[GRID_WIDTH][GRID_WIDTH]) {
	uint8_t row = 0, col = 0, num, sequence;
	//displayGrid(grid);
	if (!FindUnassignedLocation(grid, &row, &col)) //No unassigned locations = solved
			return true;
	randSeq(seq);		
	for (sequence = 0; sequence <= N - 1; sequence ++) {
		
		num = seq[sequence];
		
		if (isSafe(grid, row, col, num)) {
			grid[row][col] = num;
			
			if (SolveSudoku(grid))
				return true; //woohoo! We solved it!

			grid[row][col] = UNASSIGNED; //failure, unmake & try again
		}
	}
	return false; // this triggers backtrackiing
}

bool UsedInBox(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t boxStartRow, uint8_t boxStartCol, uint8_t num) {
	uint8_t row, col;
	for (row = 0; row < BOX_WIDTH; row ++)
		for (col = 0; col < BOX_WIDTH; col ++)
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
	return false;
}

bool UsedInCol(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t col, uint8_t num) {
	uint8_t row;
	for (row = 0; row < GRID_WIDTH; row ++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool UsedInRow(uint8_t grid[GRID_WIDTH][GRID_WIDTH], uint8_t row, uint8_t num) {
	uint8_t col;
	for (col = 0; col < GRID_WIDTH; col ++)
		if (grid[row][col] == num)
			return true;
	return false;
}