#include "gameplay.h"
#include "globals.h"
#include "font/font.h"
#include "solve.h"
#include "gfx/sprites.h"

#include <graphx.h>
#include <keypadc.h>

numbers_t numbers[9];


bool guess[GRID_WIDTH][GRID_WIDTH][10] = {
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
	{{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,false,false}},
};

void play(void)
{
	init_numbers(); //create array of number sprites (1-9)
	SolveSudoku(); //solve.c
	GenerateSudoku(); //solve.c

	updateGrid();
}

void init_numbers()
{
	numbers[0].spr = n1;
	numbers[0].xoff = 5; // will display 5 pixels to the right of the left of the grid position
	numbers[0].yoff = 2; // will display 2 pixels down from the top of the grid position
	
	numbers[1].spr = n2;
	numbers[1].xoff = 9;
	numbers[1].yoff = 2;
	
	numbers[2].spr = n3;
	numbers[2].xoff = 13;
	numbers[2].yoff = 2;
	
	numbers[3].spr = n4;
	numbers[3].xoff = 5;
	numbers[3].yoff = 8;
	
	numbers[4].spr = n5;
	numbers[4].xoff = 9;
	numbers[4].yoff = 8;
	
	numbers[5].spr = n6;
	numbers[5].xoff = 13;
	numbers[5].yoff = 8;
	
	numbers[6].spr = n7;
	numbers[6].xoff = 5;
	numbers[6].yoff = 14;
	
	numbers[7].spr = n8;
	numbers[7].xoff = 9;
	numbers[7].yoff = 14;
	
	numbers[8].spr = n9;
	numbers[8].xoff = 13;
	numbers[8].yoff = 14;
}

void drawGrid(void)
{
	uint8_t row, col;
	uint8_t i, j;
	
	//title blah blah blah
	fontlib_SetCursorPosition(5,5);
	fontlib_SetColors(BLACK, WHITE);
	fontlib_DrawString("Sudoku!");
	
	//Make every other box gray
	gfx_SetColor(GRAY);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 60, SUDOKUDRAWY, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX, SUDOKUDRAWY + 60, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 120, SUDOKUDRAWY + 60, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 60, SUDOKUDRAWY + 120, 60, 60);
	
	for (row = 0; row < GRID_WIDTH; row ++) {
		for (col = 0; col < GRID_WIDTH; col ++) {
			if(grid[row][col][0] != UNASSIGNED) //dont show the values in the grid that are 0 -- leave them blank
			{
				//if box is white, make text background white. Default font color is black. Default text background is white.
				fontlib_SetColors(BLACK, WHITE); 
				
				 //if gray background -- gray text background
				if ((row / 3 + 1 == 2 && (col / 3 + 1 == 1 || col / 3 + 1 == 3)) ||
					(col / 3 + 1 == 2 && (row / 3 + 1 == 1 || row / 3 + 1 == 3))) fontlib_SetBackgroundColor(GRAY);
				
				if (grid[row][col][1] == 1) fontlib_SetForegroundColor(BLUE); //if number in grid position is embedded, change font color to blue
			
				fontlib_SetCursorPosition(col*20+SUDOKUDRAWX + 7, row*20+SUDOKUDRAWY);
				fontlib_DrawUInt(grid[row][col][0], 1);
				//curNum = numbers[1].spr;
				gfx_Sprite(numbers[1].spr, 1, 1);
			}
		}
	}
	
    //Draw the grid lines -- font overlaps grid lines, so must be redrawn each time
	gfx_SetColor(BLACK);
	for(i = 1; i <= 10; i ++) {
		gfx_Line_NoClip(20*i + SUDOKUDRAWX - 20, SUDOKUDRAWY, 20*i + SUDOKUDRAWX - 20, SUDOKUDRAWY + 180);
	}
	for(j = 1; j <= 10; j ++) {
		gfx_Line_NoClip(SUDOKUDRAWX, 20*j + SUDOKUDRAWY - 20, SUDOKUDRAWX + 180, 20*j + SUDOKUDRAWY - 20);
	}
}

void updateGrid(void)
{
	uint8_t curPosX = 0, curPosY = 0;
	
	do
	{
		gfx_FillScreen(WHITE);
		gfx_SetDrawBuffer();
		
		drawGrid();
		
		gfx_SetColor(RED);
		gfx_Rectangle_NoClip(20 * curPosX + SUDOKUDRAWX, 20 * curPosY + SUDOKUDRAWY,20,20);
		
		gfx_SwapDraw();
		
		while (!kb_AnyKey())
		{
			kb_Scan();
		}
			
		if (kb_Data[6] & kb_Enter) //check win
		{
			fontlib_SetCursorPosition(100, 5);
			fontlib_SetColors(BLACK, WHITE);
			
			if(isWin()) return;
		}

		if (kb_Data[7] & kb_Up && curPosY > 0) curPosY --;
		if (kb_Data[7] & kb_Down && curPosY < 8) curPosY ++;
		if (kb_Data[7] & kb_Left && curPosX > 0) curPosX --;
		if (kb_Data[7] & kb_Right && curPosX < 8) curPosX ++;
				
		if (grid[curPosY][curPosX][1] == 0 && !(kb_Data[2] & kb_Alpha)) //if the current number is not embedded into the puzzle, allow to edit
		{
			if (kb_Data[1] & kb_Del) grid[curPosY][curPosX][0] = 0;
			if (kb_Data[3] & kb_1) grid[curPosY][curPosX][0] = 1;
			if (kb_Data[3] & kb_4) grid[curPosY][curPosX][0] = 4;
			if (kb_Data[3] & kb_7) grid[curPosY][curPosX][0] = 7;
			if (kb_Data[4] & kb_2) grid[curPosY][curPosX][0] = 2;
			if (kb_Data[4] & kb_5) grid[curPosY][curPosX][0] = 5;
			if (kb_Data[4] & kb_8) grid[curPosY][curPosX][0] = 8;
			if (kb_Data[5] & kb_3) grid[curPosY][curPosX][0] = 3;
			if (kb_Data[5] & kb_6) grid[curPosY][curPosX][0] = 6;
			if (kb_Data[5] & kb_9) grid[curPosY][curPosX][0] = 9;
		}
		
	} while(!(kb_Data[6] & kb_Clear));
}