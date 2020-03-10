#include "solve.h"
#include "globals.h"
#include <stdbool.h>
#include <stdint.h>

uint8_t grid[GRID_WIDTH][GRID_WIDTH][2] = {
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}},
	{{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}}
};

bool SolveSudoku(void) {
	uint8_t row = 0, col = 0, num, sequence;
	uint8_t seq[9] = {1,2,3,4,5,6,7,8,9}; //array ("sequence" - seq) of numbers used to randomnize puzzle generation.

	if (!FindUnassignedLocation(&row, &col)) return true;  //No unassigned locations = solved
	
	randSeq(seq);		
	for (sequence = 0; sequence < 9; sequence ++)
	{
		
		num = seq[sequence];
		
		if (isSafe(row, col, num))
		{
			grid[row][col][0] = num;
			
			if (SolveSudoku()) return true; //woohoo! We solved it!

			grid[row][col][0] = UNASSIGNED; //failure, unmake & try again
		}
	}
	return false; // this triggers backtrackiing
}

bool FindUnassignedLocation(uint8_t *rowp, uint8_t *colp) { //row pointer; column pointer
	uint8_t row, col;
	for (row = 0; row < GRID_WIDTH; row ++)
		for (col = 0; col < GRID_WIDTH; col ++)
			if (grid[row][col][0] == UNASSIGNED) {
				*rowp = row;
				*colp = col; 
				return true;
			}
	return false;
}

void randSeq(uint8_t *seq) {
	uint8_t a, b, i, rand;
	for(i = 0; i <= 8; i ++) {
		rand = randInt(0,8);
		a = seq[0];
		b = seq[rand];
		seq[0] = b;
		seq[rand] = a;
	}
}

bool isSafe(uint8_t row, uint8_t col, uint8_t num) {
	return !UsedInRow(row, num) &&
		   !UsedInCol(col, num) &&
		   !UsedInBox(row - row%BOX_WIDTH, col - col%BOX_WIDTH, num) &&
			grid[row][col][0] == UNASSIGNED;
}


bool UsedInBox(uint8_t boxStartRow, uint8_t boxStartCol, uint8_t num) {
	uint8_t row, col;
	for (row = 0; row < BOX_WIDTH; row ++)
		for (col = 0; col < BOX_WIDTH; col ++)
			if (grid[row + boxStartRow][col + boxStartCol][0] == num)
				return true;
	return false;
}

bool UsedInCol(uint8_t col, uint8_t num) {
	uint8_t row;
	for (row = 0; row < GRID_WIDTH; row ++)
		if (grid[row][col][0] == num)
			return true;
	return false;
}

bool UsedInRow(uint8_t row, uint8_t num) {
	uint8_t col;
	for (col = 0; col < GRID_WIDTH; col ++)
		if (grid[row][col][0] == num)
			return true;
	return false;
}


void GenerateSudoku(void) {
	uint8_t i, row, col;
	for(i = 0; i < level; i ++) {
		row = randInt(0,8);
		col = randInt(0,8);
		
		// This makes sure the puzzle follows the same setup as regular Sudoku: rotational symmetry
		// Sets grid[][][0] = 0 to establish the value of the grid position as '0'
		// Sets grid[][][1] = 0 to establish that these values can be edited
		grid[row][col][0] = UNASSIGNED;
		grid[8-row][8-col][0] = UNASSIGNED;
		grid[row][col][1] = 0;
		grid[8-row][8-col][1] = 0;
		
		
	}
}

bool isWin(void)
{
	uint8_t row, col, num;
	for(row = 0; row < GRID_WIDTH; row ++)
	{
		for(col = 0; col < GRID_WIDTH; col++)
		{
			//Have to set number in grid position to 0 in order to properly use the logic in isSafe()
			num = grid[row][col][0];
			grid[row][col][0] = UNASSIGNED;
			
			if(!isSafe(row, col, num))
			{
				grid[row][col][0] = num; //set it back to its original value
				return false; //no win
			}
			grid[row][col][0] = num; //set it back to its original value
		}
	}
	return true; //All values are safe - win!
}