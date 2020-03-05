#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>
#include <fontlibc.h>

#include "font/font.h"

#include "globals.h"
#include "solve.h"

void menu(void);
void play(void);
void displayGrid(void);
	
void main()
{
	srand(rtc_Time()); 
	menu();
}

void menu(void)
{
	gfx_Begin();
	fontlib_SetWindowFullScreen();
	fontlib_SetFont(font20, 0);
	play();
	gfx_End();
}

void play(void) {
	
	if(SolveSudoku(solvedGrid) == true);
		//GenerateSudoku();
		displayGrid();
	fontlib_SetCursorPosition(5, 5);
	fontlib_SetColors(BLACK, WHITE);
    if(isWin())
	{
		fontlib_DrawString("Win!");
	} else {
		fontlib_DrawString("Lose!");
	}
	while (!os_GetCSC());
}
	
void displayGrid(void) {
	
	uint8_t row, col;
	uint8_t i, j;
	
	//Make every other box gray
	gfx_SetColor(GRAY);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 60, SUDOKUDRAWY, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX, SUDOKUDRAWY + 60, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 120, SUDOKUDRAWY + 60, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 60, SUDOKUDRAWY + 120, 60, 60);
		
	for (row = 0; row < GRID_WIDTH; row ++) {
		for (col = 0; col < GRID_WIDTH; col ++) {
			
			//if box is white, make text background white; if gray background - gray text background
			fontlib_SetColors(BLACK, WHITE); 
			
			if ((row / 3 + 1 == 2 && (col / 3 + 1 == 1 || col / 3 + 1 == 3)) ||
			    (col / 3 + 1 == 2 && (row / 3 + 1 == 1 || row / 3 + 1 == 3)))
				fontlib_SetBackgroundColor(GRAY);
				
			if (playGrid[row][col] != UNASSIGNED) 
			{
				if (solvedGrid[row][col] != UNASSIGNED)
					fontlib_SetForegroundColor(BLUE);
				
				fontlib_SetCursorPosition(col*20+SUDOKUDRAWX + 7, row*20+SUDOKUDRAWY);
				fontlib_DrawUInt(solvedGrid[row][col], 1);
			}
		}
	}
	
	//Draw the grid lines
	gfx_SetColor(BLACK);
	for(i = 1; i <= 10; i ++) {
		gfx_Line_NoClip(20*i + SUDOKUDRAWX - 20, SUDOKUDRAWY, 20*i + SUDOKUDRAWX - 20, SUDOKUDRAWY + 180);
	}
	for(j = 1; j <= 10; j ++) {
		gfx_Line_NoClip(SUDOKUDRAWX, 20*j + SUDOKUDRAWY - 20, SUDOKUDRAWX + 180, 20*j + SUDOKUDRAWY - 20);
	}
}