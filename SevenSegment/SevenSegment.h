/* 
* SevenSegment.h
*
* Created: 08/03/2020 11:11:41 AM
* Author: Muhammad Mansoor
* This is the interface for the SevenSegment class.
*/


#ifndef __SEVENSEGMENT_H__
#define __SEVENSEGMENT_H__

//importing necessary files/libraries
#include "common_usage.h"
#include <avr/io.h>

//defining constants
#define COMMON_CATHODE 1
#define COMMON_ANODE 0
#define DP_ON 1		//DP=decimal point
#define DP_OFF 0


class SevenSegment
{
//variables

private:
	static byte num_displays;	//static var to keep track of number of displays initialized
	sfr* dev_port;		//the port to which the display is connected
	sfr* dev_ddr;		//the corresponding DDR to the port.
	byte mode;			//common cathode or common anode
	
//functions
public:
	//constructor
	SevenSegment(sfr *given_ddr=&DDRA, sfr *given_port=&PORTA, byte given_mode=COMMON_ANODE);
	//function to write to display
	void write(byte to_write,byte dp=DP_OFF);
	//destructor
	~SevenSegment();
private:
	//gives the seven segment code to write() function
	byte get_code(byte);

}; //SevenSegment

#endif //__SEVENSEGMENT_H__
