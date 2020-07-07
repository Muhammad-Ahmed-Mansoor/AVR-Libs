/* 
* keyboard_4x3.cpp
*
* Created: 19/03/2020 7:25:02 PM
* Author: Muhammad Mansoor
*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include "keyboard_4x3.h"

//key map defined here as compiler does not like var definitions in headers
byte kb43_keymap[4][3]={ {'1','2','3'},
				       	 {'4','5','6'},
						 {'7','8','9'},
						 {'*','0','#'}};

void kb43_init()
{
	SET_BIT(KB43_ROW1_DDR,KB43_ROW1_BIT);
	SET_BIT(KB43_ROW2_DDR,KB43_ROW2_BIT);
	SET_BIT(KB43_ROW3_DDR,KB43_ROW3_BIT);
	SET_BIT(KB43_ROW4_DDR,KB43_ROW4_BIT);
	
	CLR_BIT(KB43_COL1_DDR,KB43_COL1_BIT);
	CLR_BIT(KB43_COL2_DDR,KB43_COL2_BIT);
	CLR_BIT(KB43_COL3_DDR,KB43_COL3_BIT);
	
	//enabling pull-ups at columns
	SET_BIT(KB43_COL1_PORT,KB43_COL1_BIT);
	SET_BIT(KB43_COL2_PORT,KB43_COL2_BIT);
	SET_BIT(KB43_COL3_PORT,KB43_COL3_BIT);
	
}

void kb43_wait_for_clr()
{	
	
	//grounding all rows
	CLR_BIT(KB43_ROW1_PORT,KB43_ROW1_BIT);
	CLR_BIT(KB43_ROW2_PORT,KB43_ROW2_BIT);
	CLR_BIT(KB43_ROW3_PORT,KB43_ROW3_BIT);
	CLR_BIT(KB43_ROW4_PORT,KB43_ROW4_BIT);
	
	//polling for the columns to get clr
	while(IS_CLR(KB43_COL1_PIN,KB43_COL1_BIT)||
		  IS_CLR(KB43_COL2_PIN,KB43_COL2_BIT)||
		  IS_CLR(KB43_COL3_PIN,KB43_COL3_BIT));
		  
	//polling again for surety
	while(IS_CLR(KB43_COL1_PIN,KB43_COL1_BIT)||
		  IS_CLR(KB43_COL2_PIN,KB43_COL2_BIT)||
		  IS_CLR(KB43_COL3_PIN,KB43_COL3_BIT));
	
	return;
}

byte kb43_get_char()
{
	
	kb43_init();
	kb43_wait_for_clr();
	byte col=0;
	
	//grounding all rows
	CLR_BIT(KB43_ROW1_PORT,KB43_ROW1_BIT);
	CLR_BIT(KB43_ROW2_PORT,KB43_ROW2_BIT);
	CLR_BIT(KB43_ROW3_PORT,KB43_ROW3_BIT);
	CLR_BIT(KB43_ROW4_PORT,KB43_ROW4_BIT);
	
	
	/*Poll for a 0 among the columns. If found,
	wait to rule out bounce. Then check which 
	column has a zero. If a zero is present, we
	will get its column location and the loop
	will exit. If a zero is not present, var 
	'col' will remain zero causing the polling
	process to repeat.*/
	while(col==0)
	{
		//infinite loop as long as all 1s
		while(IS_SET(KB43_COL1_PIN,KB43_COL1_BIT)&&
		IS_SET(KB43_COL2_PIN,KB43_COL2_BIT)&&
		IS_SET(KB43_COL3_PIN,KB43_COL3_BIT));
		
		_delay_ms(DEBOUNCE_DELAY);
		
		//now to see which column is giving zero
		if(IS_CLR(KB43_COL1_PIN,KB43_COL1_BIT))
			col=1;
		else if(IS_CLR(KB43_COL2_PIN,KB43_COL2_BIT))
			col=2;
		else if(IS_CLR(KB43_COL3_PIN,KB43_COL3_BIT))
			col=3;
	}
	
	/*now set the rows 1, 1-by-1.(and wait for
	the PORT to mirror it). The row who's
	being 1 causes all 1s in columns is the desired row*/	
	SET_BIT(KB43_ROW1_PORT,KB43_ROW1_BIT);
	_delay_us(KB_RESPONSE_DELAY);
	if(IS_SET(KB43_COL1_PIN,KB43_COL1_BIT)&&	IS_SET(KB43_COL2_PIN,KB43_COL2_BIT)&&	IS_SET(KB43_COL3_PIN,KB43_COL3_BIT))
				return kb43_keymap[0][col-1];
			
				
	SET_BIT(KB43_ROW2_PORT,KB43_ROW2_BIT);
	_delay_us(KB_RESPONSE_DELAY);
	if(IS_SET(KB43_COL1_PIN,KB43_COL1_BIT)&&	IS_SET(KB43_COL2_PIN,KB43_COL2_BIT)&&	IS_SET(KB43_COL3_PIN,KB43_COL3_BIT))
				return kb43_keymap[1][col-1];
			
			
				
	SET_BIT(KB43_ROW3_PORT,KB43_ROW3_BIT);
	_delay_us(KB_RESPONSE_DELAY);
	if(IS_SET(KB43_COL1_PIN,KB43_COL1_BIT)&&	IS_SET(KB43_COL2_PIN,KB43_COL2_BIT)&&	IS_SET(KB43_COL3_PIN,KB43_COL3_BIT))
				return kb43_keymap[2][col-1];
			
					
				
	SET_BIT(KB43_ROW4_PORT,KB43_ROW4_BIT);
	_delay_us(KB_RESPONSE_DELAY);
	if(IS_SET(KB43_COL1_PIN,KB43_COL1_BIT)&&	IS_SET(KB43_COL2_PIN,KB43_COL2_BIT)&&	IS_SET(KB43_COL3_PIN,KB43_COL3_BIT))
				return kb43_keymap[3][col-1];
			
	//if somehow we are here, what is going on?	
	return '?';
}

