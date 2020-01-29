#include "gameplay.h"

uint8_t SudokuDrawX = 20, SudokuDrawY = 46; //move the sudoku grid around - prevents hardcoded values (20,44)

uint8_t grid[GRID_WIDTH][GRID_WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
	}; 
uint8_t solution[GRID_WIDTH][GRID_WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
	}; 
	
void play(void) {
	SolveSudoku(solution); 
	generateSudoku(solution, grid);
	playSudoku(grid);
}

void displayGrid(uint8_t grid[GRID_WIDTH][GRID_WIDTH]) {
	uint8_t row, col, timer;
	uint8_t i, j;
	//7x12(?) bottom left
	int xoff = 6, yoff = -4; // pixel difference between top left corner of box and top left corner of number
	
	gfx_SetDrawBuffer();
	
	//Make every other box gray
	gfx_SetColor(GRAY);
	gfx_FillRectangle_NoClip(SudokuDrawX - xoff+60, SudokuDrawY, 60, 60);
	gfx_FillRectangle_NoClip(SudokuDrawX - xoff, SudokuDrawY+60, 60, 60);
	gfx_FillRectangle_NoClip(SudokuDrawX - xoff+120, SudokuDrawY+60, 60, 60);
	gfx_FillRectangle_NoClip(SudokuDrawX - xoff+60, SudokuDrawY+120, 60, 60);
		
	for (row = 0; row < GRID_WIDTH; row ++) {
		for (col = 0; col < GRID_WIDTH; col ++) {
			//if box is white, make text background white; if gray background - gray text background
			fontlib_SetColors(BLACK, WHITE); 
			if ((row / 3 + 1 == 2 && (col/3 + 1 == 1 || col/3 + 1 == 3)) ||
			    (col / 3 + 1 == 2 && (row/3 + 1 == 1 || row/3 + 1 == 3)))
				 fontlib_SetBackgroundColor(GRAY);
				 
			if (grid[row][col] != UNASSIGNED) {
				fontlib_SetCursorPosition(col*20+SudokuDrawX, row*20+SudokuDrawY);
				fontlib_DrawUInt(grid[row][col], 1);
			}
		}
	}
	//(20,44) Draw
	//Draw the grid lines
	gfx_SetColor(BLACK);
	for(i = 1; i <= 10; i ++) {
		gfx_Line_NoClip(20*i - xoff + SudokuDrawX - 20, 20 + 20 - yoff + SudokuDrawY - 44, 20*i - xoff + SudokuDrawX - 20, 20 + 180 + 20 - yoff + SudokuDrawY - 44);
	}
	for(j = 1; j <= 10; j ++) {
		gfx_Line_NoClip(20 - xoff + SudokuDrawX - 20, 20*j + 20 - yoff + SudokuDrawY - 44, 20 + 180 - xoff + SudokuDrawX - 20, 20*j + 20 - yoff + SudokuDrawY - 44);
	}
	
	gfx_SwapDraw();
}

void generateSudoku(uint8_t solution[GRID_WIDTH][GRID_WIDTH], uint8_t grid[GRID_WIDTH][GRID_WIDTH]) {
	uint8_t i, row, col;
	for(i = 0; i <= LEVEL; i ++) {
		row = randInt(0,8);
		col = randInt(0,8);
		
		// This makes sure the puzzle follows the same setup as regular Sudoku: rotational symmetry
		grid[row][col] = solution[row][col];
		grid[8-row][8-col] = solution[8-row][8-col];
	}
}

void playSudoku(uint8_t grid[GRID_WIDTH][GRID_WIDTH]) {
	gfx_FillScreen (WHITE);
	fontlib_SetCursorPosition(1,1);
	fontlib_DrawString("Sudoku");

	displayGrid(grid);
	
	while (!(kb_Data[1] & kb_2nd))
		kb_Scan();
}