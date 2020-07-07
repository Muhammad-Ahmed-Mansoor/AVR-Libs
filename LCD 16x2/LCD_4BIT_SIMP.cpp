/*
 * LCD_4BIT_SIMP.cpp
 *
 * Created: 13/03/2020 10:20:14 AM
 *  Author: Muhammad Mansoor
 */ 

#define F_CPU 8000000UL
#include "LCD_4BIT_SIMP.h"
#include <util/delay.h>

void put_nibble_ON_LCD(byte data, byte nibble)
{

if(nibble==LOW_NIBBLE)
	SWAP_NIBBLES(data);

if(IS_SET(data,4))
	SET_BIT(PORT_D4,PIN_D4);
else
	CLR_BIT(PORT_D4,PIN_D4);
	
if(IS_SET(data,5))
  SET_BIT(PORT_D5,PIN_D5);
else
  CLR_BIT(PORT_D5,PIN_D5);
 
if(IS_SET(data,6))
  SET_BIT(PORT_D6,PIN_D6);
else
   CLR_BIT(PORT_D6,PIN_D6);
   
if(IS_SET(data,7))
  SET_BIT(PORT_D7,PIN_D7);
else
  CLR_BIT(PORT_D7,PIN_D7);

}

void LCD_command(byte command)
{
	put_nibble_ON_LCD(command,HIGH_NIBBLE);
	CLR_BIT(PORT_RS,PIN_RS);
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	put_nibble_ON_LCD(command,LOW_NIBBLE);
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	
}

void LCD_char(byte data)
{
	put_nibble_ON_LCD(data,HIGH_NIBBLE);
	SET_BIT(PORT_RS,PIN_RS);
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	put_nibble_ON_LCD(data,LOW_NIBBLE);
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	
}

void LCD_init()
{
	SET_BIT(DDR_D4,PIN_D4);
	SET_BIT(DDR_D5,PIN_D5);
	SET_BIT(DDR_D6,PIN_D6);
	SET_BIT(DDR_D7,PIN_D7);
	SET_BIT(DDR_EN,PIN_EN);
	SET_BIT(DDR_RS,PIN_RS);
	
	CLR_BIT(PORT_EN,PIN_EN);
	
	LCD_command(INIT_4BIT_1);
	LCD_command(INIT_4BIT_2);
	LCD_command(INIT_2_LINE_5x7_4BIT);
	LCD_command(DISPLAY_ON_CURSOR_OFF);
	LCD_command(CLEAR_LCD);
	_delay_us(2000);
	LCD_command(CURSOR_RIGHT_SHIFT);
}

void LCD_set_position(byte line, byte position)
{
 byte first_addresses[]={0x80,0xC0,0x94,0xD4};
 LCD_command(first_addresses[line-1]+position-1);
}

void LCD_string(char* string, byte length)
{
 length>LCD_LEN?length=LCD_LEN:length=length;
 
 for(byte i=0; i<length ; i++)
	LCD_char(string[i]);
}

