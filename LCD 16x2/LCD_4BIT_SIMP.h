/*
 * LCD_4BIT_SIMP.h
 *
 * Created: 13/03/2020 10:19:19 AM
 *  Author: Muhammad Mansoor
 */ 


#ifndef LCD_4BIT_SIMP_H_
#define LCD_4BIT_SIMP_H_
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

//LCD PINS
//D4
#define PORT_D4 PORTA
#define DDR_D4 DDRA
#define PIN_D4 0
//----------------------------------
//D5
#define PORT_D5 PORTA
#define DDR_D5 DDRA
#define PIN_D5 1
//----------------------------------
//D6
#define PORT_D6 PORTA
#define DDR_D6 DDRA
#define PIN_D6 2
//----------------------------------
//D7
#define PORT_D7 PORTA
#define DDR_D7 DDRA
#define PIN_D7 3
//----------------------------------
//RS
#define PORT_RS PORTA
#define DDR_RS DDRA
#define PIN_RS 4
//----------------------------------
//EN
#define PORT_EN PORTA
#define DDR_EN DDRA
#define PIN_EN 5
//----------------------------------

//LCD SIZE
#define LCD_NUM_LINES 2
#define LCD_LEN 16






void put_nibble_ON_LCD(byte data, byte nibble);
void LCD_command(byte command);
void LCD_char(byte data);
void LCD_init();
void LCD_set_position(byte line, byte position);
void LCD_string(char* string, byte length);




#endif /* LCD_4BIT_SIMP_H_ */