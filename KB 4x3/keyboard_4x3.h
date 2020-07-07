/* 
* keyboard_4x3.h
*
* Created: 19/03/2020 7:25:02 PM
* Author: Muhammad Mansoor
*/


#ifndef __KEYBOARD_4X3_H__
#define __KEYBOARD_4X3_H__

#include "common_usage.h"
#include <avr/io.h>

//ROW1
#define KB43_ROW1_PORT PORTD
#define KB43_ROW1_DDR DDRD
#define KB43_ROW1_BIT 0
//----------------------------------
//ROW2
#define KB43_ROW2_PORT PORTD
#define KB43_ROW2_DDR DDRD
#define KB43_ROW2_BIT 1
//----------------------------------
//ROW3
#define KB43_ROW3_PORT PORTD
#define KB43_ROW3_DDR DDRD
#define KB43_ROW3_BIT 2
//----------------------------------
//ROW4
#define KB43_ROW4_PORT PORTD
#define KB43_ROW4_DDR DDRD
#define KB43_ROW4_BIT 3
//----------------------------------
//COL1
#define KB43_COL1_PIN PIND
#define KB43_COL1_PORT PORTD
#define KB43_COL1_DDR DDRD
#define KB43_COL1_BIT 4
//----------------------------------
//COL2
#define KB43_COL2_PIN PIND
#define KB43_COL2_PORT PORTD
#define KB43_COL2_DDR DDRD
#define KB43_COL2_BIT 5
//----------------------------------
//COL3
#define KB43_COL3_PIN PIND
#define KB43_COL3_PORT PORTD
#define KB43_COL3_DDR DDRD
#define KB43_COL3_BIT 6
//----------------------------------

#define DEBOUNCE_DELAY 15//ms
#define KB_RESPONSE_DELAY 10//us

void kb43_init();
void kb43_wait_for_clr();
byte kb43_get_char();


#endif //__KEYBOARD_4X3_H__
