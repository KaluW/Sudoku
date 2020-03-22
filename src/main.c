#include <stdbool.h>
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
#include "gameplay.h"

void menu(void);

uint16_t level = 30;

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
	play(); //gameplay.c
	gfx_End();
}