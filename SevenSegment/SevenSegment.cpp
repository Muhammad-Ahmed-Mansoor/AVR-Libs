/* 
* SevenSegment.cpp
*
* Created: 08/03/2020 11:11:41 AM
* Author: Muhammad Mansoor
* This file contains the implementation of the SevenSegment class
*/

//import the interface
#include "SevenSegment.h"

//initialize static variable
byte SevenSegment::num_displays=0;

// constructor
SevenSegment::SevenSegment(sfr *given_ddr ,sfr *given_port, byte given_mode)
{
	//constructor sets the variables and updates num_dislpays
	mode=given_mode;
	dev_port=given_port;
	dev_ddr=given_ddr;
	num_displays++;
} //SevenSegment



void SevenSegment::write(byte to_write,byte dp)
{
	//get seven segment code for the char to write
	to_write=get_code(to_write);
	//set DDR to output
	*dev_ddr=0xFF;
	//write the output to PORT
	*dev_port=to_write;
	
	//set the DP appropriately
	if(mode==COMMON_CATHODE)
		(dp==DP_ON)?SET_BIT(*dev_port,7):CLR_BIT(*dev_port,7);
	else
		(dp==DP_ON)?CLR_BIT(*dev_port,7):SET_BIT(*dev_port,7);
	return;
}

// default destructor
SevenSegment::~SevenSegment()
{
	//decrement count on object destruction
	num_displays--;
} //~SevenSegment

byte SevenSegment::get_code(byte given_char)
{
	//this function uses a switch case to locate the required seven segment code
	byte code;
	switch(given_char)
	{
		
		
		case	'0':case	0: code=0x7E; break;
		case	'1':case	1: code= 0x30;break;
		case	'2':case	2: code=0x6D;break;
		case	'3':case	3: code=0x79;break;
		case	'4':case	4: code=0x33;break;
		case	'5':case	5: code=0x5B;break;
		case	'6':case	6: code=0x5F;break;
		case	'7':case	7: code=0x70;break;
		case	'8':case	8: code=0x7F;break;
		case	'9':case	9:code= 0x7B;break;
		case	' ': code=0x00;break;
		case	'A':code= 0x77;break;
		case	'a':code= 0x7D;break;
		case	'B':code= 0x7F;break;
		case	'b':code= 0x1F;break;
		case	'C':code= 0x4E;break;
		case	'c':code= 0x0D;break;
		case	'D':code= 0x7E;break;
		case	'd':code= 0x3D;break;
		case	'E':code= 0x4F;break;
		case	'e':code= 0x6f;break;
		case	'F':code= 0x47;break;
		case	'f':code= 0x47;break;
		case	'G':code= 0x5E;break;
		case	'g':code= 0x7B;break;
		case	'H': code=0x37;break;
		case	'h':code= 0x17;break;
		case	'I':code= 0x30;break;
		case	'i':code= 0x10;break;
		case	'J':code= 0x3C;break;
		case	'j':code= 0x38;break;
		case	'K':code= 0x37;break;
		case	'k':code= 0x17;break;
		case	'L':code= 0x0E;break;
		case	'l':code= 0x06;break;
		case	'M':code= 0x55;break;
		case	'm':code= 0x55;break;
		case	'N': code=0x15;break;
		case	'n':code= 0x15;break;
		case	'O':code= 0x7E;break;
		case	'o':code= 0x1D;break;
		case	'P':code= 0x67;break;
		case	'p':code= 0x67;break;
		case	'Q': code=0x73;break;
		case	'q':code= 0x73;break;
		case	'R':code= 0x77;break;
		case	'r':code= 0x05;break;
		case	'S':code= 0x5B;break;
		case	's':code= 0x5B;break;
		case	'T':code= 0x46;break;
		case	't':code= 0x0F;break;
		case	'U':code= 0x3E;break;
		case	'u':code= 0x1C;break;
		case	'V':code= 0x27;break;
		case	'v':code= 0x23;break;
		case	'W':code= 0x3F;break;
		case	'w':code= 0x2B;break;
		case	'X':code= 0x25;break;
		case	'x':code= 0x25;break;
		case	'Y':code= 0x3B;break;
		case	'y':code= 0x33;break;
		case	'Z':code= 0x6D;break;
		case	'z':code= 0x6D;break;
		default: code=0x7F; break;
				
	}
	// as all the codes above are for common cathode, they must be complemented if 
	// we are using common anode
	return (mode==COMMON_CATHODE)?code:~code;
}//end get_code()
