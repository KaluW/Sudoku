#include "gameplay.h"
#include "globals.h"
#include "font/font.h"
#include "solve.h"
#include "gfx/sprites.h"

#include <graphx.h>
#include <keypadc.h>

numbers_t numbers[9];
bool guess_mode = false;


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
	gfx_SetTransparentColor(WHITE);
	fontlib_SetTransparency(true);
	init_numbers(); //create array of number sprites (1-9)
	SolveSudoku(); //solve.c
	GenerateSudoku(); //solve.c

	updateGrid();
}

void init_numbers()
{
	numbers[0].spr = n1;
	numbers[0].xoff = 4; // will display 5 pixels to the right of the left boundary of the grid position
	numbers[0].yoff = 2; // will display 2 pixels down from the top boundary of the grid position
	
	numbers[1].spr = n2;
	numbers[1].xoff = 9;
	numbers[1].yoff = 2;
	
	numbers[2].spr = n3;
	numbers[2].xoff = 14;
	numbers[2].yoff = 2;
	
	numbers[3].spr = n4;
	numbers[3].xoff = 4;
	numbers[3].yoff = 8;
	
	numbers[4].spr = n5;
	numbers[4].xoff = 9;
	numbers[4].yoff = 8;
	
	numbers[5].spr = n6;
	numbers[5].xoff = 14;
	numbers[5].yoff = 8;
	
	numbers[6].spr = n7;
	numbers[6].xoff = 4;
	numbers[6].yoff = 14;
	
	numbers[7].spr = n8;
	numbers[7].xoff = 9;
	numbers[7].yoff = 14;
	
	numbers[8].spr = n9;
	numbers[8].xoff = 14;
	numbers[8].yoff = 14;
}

void drawGrid(void)
{
	uint8_t row, col, num;
	uint8_t i, j, x_offset, y_offset;
	
	//GUI, blah blah blah
	fontlib_SetCursorPosition(5,5);
	fontlib_SetColors(BLACK, WHITE);
	fontlib_DrawString("Sudoku!");
	
	gfx_SetColor(GRAY);
	if(guess_mode)
	{
		gfx_FillRectangle_NoClip(200 + SUDOKUDRAWX, 60 + SUDOKUDRAWY, 20, 20);
	} else {
		gfx_FillRectangle_NoClip(200 + SUDOKUDRAWX, 20 + SUDOKUDRAWY, 20, 20);
	}

	fontlib_SetCursorPosition(200 + SUDOKUDRAWX + 7, 20 + SUDOKUDRAWY);
	fontlib_DrawString("5");
	gfx_TransparentSprite_NoClip(numbers[4].spr, 200 + SUDOKUDRAWX + 9, 60 + SUDOKUDRAWY + 8);
	
	gfx_SetColor(BLACK);
	gfx_Rectangle_NoClip(200 + SUDOKUDRAWX, 20 + SUDOKUDRAWY, 20, 20);
	gfx_Rectangle_NoClip(200 + SUDOKUDRAWX, 60 + SUDOKUDRAWY, 20, 20);
	
	//Make every other box gray
	gfx_SetColor(GRAY);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 60, SUDOKUDRAWY, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX, SUDOKUDRAWY + 60, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 120, SUDOKUDRAWY + 60, 60, 60);
	gfx_FillRectangle_NoClip(SUDOKUDRAWX + 60, SUDOKUDRAWY + 120, 60, 60);


	
	for (row = 0; row < GRID_WIDTH; row ++)
	{
		for (col = 0; col < GRID_WIDTH; col ++)
		{
			 //dont show the values in the grid that are 0 -- leave them blank (unless in guessing mode)
			if(grid[row][col][0] != UNASSIGNED || guess[row][col][0])
			{
				//if box is white, make text background white. Default font color is black. Default text background is white.
				fontlib_SetColors(BLACK, WHITE); 
				
				 //if gray background -- gray text background
				if ((row / 3 + 1 == 2 && (col / 3 + 1 == 1 || col / 3 + 1 == 3)) ||
					(col / 3 + 1 == 2 && (row / 3 + 1 == 1 || row / 3 + 1 == 3))) fontlib_SetBackgroundColor(GRAY);
				
				if (grid[row][col][1] == 1) fontlib_SetForegroundColor(BLUE); //if number in grid position is embedded, change font color to blue
				
				if(!guess[row][col][0]) //If toggling guess numbers is off
				{
					fontlib_SetCursorPosition(col*20+SUDOKUDRAWX + 7, row*20+SUDOKUDRAWY);
					fontlib_DrawUInt(grid[row][col][0], 1);
				} else
				{
					for(num = 1; num < 10; num ++) // Check the box for guesses
					{
						x_offset = 20*col + SUDOKUDRAWX + numbers[num-1].xoff; //[num-1] since sprite for 1 starts at offset 0 (2 starts at offset 1, etc.)
						y_offset = 20*row + SUDOKUDRAWY + numbers[num-1].yoff;
						//If number is being used as a guess, then display the number sprite in correct offset position inside box
						if(guess[row][col][num]) gfx_TransparentSprite_NoClip(numbers[num-1].spr, x_offset, y_offset);
					}
				}
			}
		}
	}
	
	gfx_SetColor(BLACK);
	for(i = 0; i < 10; i ++) {
		gfx_Line_NoClip(20*i + SUDOKUDRAWX, SUDOKUDRAWY, 20*i + SUDOKUDRAWX, SUDOKUDRAWY + 180);
	}
	for(j = 0; j < 10; j ++) {
		gfx_Line_NoClip(SUDOKUDRAWX, 20*j + SUDOKUDRAWY, SUDOKUDRAWX + 180, 20*j + SUDOKUDRAWY);
	}
}

void updateGrid(void)
{
	uint8_t curPosX = 0, curPosY = 0;
	sk_key_t key;
	
	do
	{
		key = os_GetCSC();
		
		gfx_FillScreen(WHITE);
		gfx_SetDrawBuffer();
		
		drawGrid();
		
		gfx_SetColor(RED);
		gfx_Rectangle_NoClip(20 * curPosX + SUDOKUDRAWX, 20 * curPosY + SUDOKUDRAWY,20,20);
		
		gfx_SwapDraw();
		
		switch (key)
        {
			case sk_Enter:
				fontlib_SetCursorPosition(100, 5);
				fontlib_SetColors(BLACK, WHITE);
				if(isWin()) return;
				break;

			case sk_Up:
				if(curPosY > 0) curPosY --;
				break;
				
			case sk_Down:
				if(curPosY < 8) curPosY ++;
				break;
				
			case sk_Left:
				if(curPosX > 0) curPosX --;
				break;
				
			case sk_Right:
				if(curPosX < 8) curPosX ++;
				break;
				
			case sk_2nd: //Toggle guessing mode off
				guess_mode = false;
				break;
				
			case sk_Alpha: //Toggle guessing mode on
				guess_mode = true;
				break;
			
			case sk_1:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 1) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 1;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][1])
						{
							guess[curPosY][curPosX][1] = false;
						} else
						{
							guess[curPosY][curPosX][1] = true;
						}
					}
				}
				break;
				
			case sk_2:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 2) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 2;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][2])
						{
							guess[curPosY][curPosX][2] = false;
						} else
						{
							guess[curPosY][curPosX][2] = true;
						}
					}
				}
				break;
				
			case sk_3:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 3) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 3;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][3])
						{
							guess[curPosY][curPosX][3] = false;
						} else
						{
							guess[curPosY][curPosX][3] = true;
						}
					}
				}
				break;
				
			case sk_4:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 4) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 4;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][4])
						{
							guess[curPosY][curPosX][4] = false;
						} else
						{
							guess[curPosY][curPosX][4] = true;
						}
					}
				}
				break;
				
			case sk_5:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 5) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 5;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][5])
						{
							guess[curPosY][curPosX][5] = false;
						} else
						{
							guess[curPosY][curPosX][5] = true;
						}
					}
				}
				break;
			
			case sk_6:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 6) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 6;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][6])
						{
							guess[curPosY][curPosX][6] = false;
						} else
						{
							guess[curPosY][curPosX][6] = true;
						}
					}
				}
				break;

			case sk_7:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 7) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 7;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][7])
						{
							guess[curPosY][curPosX][7] = false;
						} else
						{
							guess[curPosY][curPosX][7] = true;
						}
					}
				}
				break;

			case sk_8:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 8) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 8;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][8])
						{
							guess[curPosY][curPosX][8] = false;
						} else
						{
							guess[curPosY][curPosX][8] = true;
						}
					}
				}
				break;

			case sk_9:
				if(!grid[curPosY][curPosX][1]) //if not embedded into puzzle
				{
					if(!guess_mode) //if not in guessing mode
					{
						guess[curPosY][curPosX][0] = false;
						if(grid[curPosY][curPosX][0] == 9) //if its already there, delete it; otherwise, insert number
						{
							grid[curPosY][curPosX][0] = 0;
						} else
						{
							grid[curPosY][curPosX][0] = 9;
						}
					} else
					{
						guess[curPosY][curPosX][0] = true;
						if(guess[curPosY][curPosX][9])
						{
							guess[curPosY][curPosX][9] = false;
						} else
						{
							guess[curPosY][curPosX][9] = true;
						}
					}
				}
				break;
				
			default:
                break;
		}
		
		
	} while(key != sk_Clear);
}