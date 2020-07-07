/*
 * LCD_4BIT_SIMP.cpp
 *
 * Created: 13/03/2020 10:20:14 AM
 *  Author: Muhammad Mansoor
 */ 

#define F_CPU 8000000UL
#include "LCD_MY_SERIAL.h"
#include <util/delay.h>

void put_nibble_RS_ON_LCD(byte data, byte nibble,byte rs_value)
{

//the lower nibble will be sent always
if(nibble==HIGH_NIBBLE)
	SWAP_NIBBLES(data);
	
//shift data left by 1
data <<=1;
 
 //set LSB equal to RS value
 if(rs_value)
	SET_BIT(data,0);
	
//now simply send out data to serial DATA port
for(byte i=0;i<5;i++)
{
	if(IS_SET(data,i))
		SET_BIT(PORT_DATA,PIN_DATA);
	else
		CLR_BIT(PORT_DATA,PIN_DATA);
	//setup time
	_delay_us(1);
	//clock pulse
	CLR_BIT(PORT_CLK,PIN_CLK);
	_delay_us(1);
	SET_BIT(PORT_CLK,PIN_CLK);
	//hold time
	_delay_us(1);
}

}

void LCD_command(byte command)
{
	put_nibble_RS_ON_LCD(command,HIGH_NIBBLE,0);
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	put_nibble_RS_ON_LCD(command,LOW_NIBBLE,0);
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	
}

void LCD_char(byte data)
{
	put_nibble_RS_ON_LCD(data,HIGH_NIBBLE,1);
	
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	put_nibble_RS_ON_LCD(data,LOW_NIBBLE,1);
	
	SET_BIT(PORT_EN,PIN_EN);
	_delay_us(1);
	CLR_BIT(PORT_EN,PIN_EN);
	_delay_us(100);
	
	
}

void LCD_init()
{
	SET_BIT(DDR_DATA,PIN_DATA);
	SET_BIT(DDR_CLK,PIN_CLK);
	SET_BIT(DDR_EN,PIN_EN);
	SET_BIT(PORT_CLK,PIN_CLK);
	
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

