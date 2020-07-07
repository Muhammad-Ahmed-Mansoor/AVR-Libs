/*
 * LCD_4BIT_SIMP.h
 *
 * Created: 13/03/2020 10:19:19 AM
 *  Author: Muhammad Mansoor
 */ 


#ifndef LCD_MY_SERIAL_
#define LCD_MY_SERIAL_
#include <avr/io.h>
#include "common_usage.h"

//Definitions for commands(use with LCD_command function)
#define INIT_2_LINE_5x7_4BIT 0x28
#define INIT_1_LINE_5x7_4BIT 0x21
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define CLEAR_LCD 0x01
#define RETURN_HOME 0x02
#define CURSOR_RIGHT_SHIFT 0x06
#define CURSOR_LEFT_SHIFT 0x04
#define INIT_4BIT_1 0x33
#define INIT_4BIT_2 0x32
#define SHIFT_LEFT 0x18

//Serial PINS
//DATA
#define PORT_DATA PORTA
#define DDR_DATA DDRA
#define PIN_DATA 0
//----------------------------------
//CLK
#define PORT_CLK PORTA
#define DDR_CLK DDRA
#define PIN_CLK 1
//----------------------------------
//EN
#define PORT_EN PORTA
#define DDR_EN DDRA
#define PIN_EN 2
//----------------------------------

//LCD SIZE
#define LCD_NUM_LINES 2
#define LCD_LEN 16






void put_nibble_RS_ON_LCD(byte data, byte nibble,byte rs_value);
void LCD_command(byte command);
void LCD_char(byte data);
void LCD_init();
void LCD_set_position(byte line, byte position);
void LCD_string(char* string, byte length);




#endif /*LCD_MY_SERIAL_ */