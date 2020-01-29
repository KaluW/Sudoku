#include "globals.h"
#include "gameplay.h"

#include "font/font.h"



/* 
!!!TODO!!!

*/

//Function Prototypes
void menu(void);

//Globals


void main() {
	srand(rtc_Time()); 
	menu();
}

void menu(void) {
	
	gfx_Begin();
	fontlib_SetWindowFullScreen();
	fontlib_SetFont(font20, 0);
	play();
	gfx_End();
}

