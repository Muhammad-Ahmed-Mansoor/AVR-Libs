/*
 * common_usage.h
 *
 * Created: 08/03/2020 11:37:11 AM
 *  Author: Muhammad Mansoor
 * This header file contains common definitions used
 * frequently with the AVR.
 */ 


#ifndef COMMON_USAGE_H_
#define COMMON_USAGE_H_

//for the uint8_t data type, import <stdint-gcc.h>
#include <stdint-gcc.h>

//defining macros for easier bit manipulation
#define SET_BIT(x,n) x|=(1<<n)
#define CLR_BIT(x,n) x&=~(1<<n)
#define TOGGLE_BIT(x,n) x^=(1<<n) 
#define IS_SET(x,n) x&(1<<n)
#define IS_CLR(x,n) ~IS_SET(x,n)
#define SWAP_NIBBLES(x) x=(x<<4)|(x>>4)
#define HIGH_NIBBLE 0xF0
#define LOW_NIBBLE 0x0F
#define SET_NIBBLE(x,n) x|=n//n=HIGH_NIBBLE or LOW_NIBBLE
#define CLR_NIBBLE(x,n) x&=~n


//giving short aliases to commonly used data types with long names
typedef unsigned char byte;
typedef volatile uint8_t sfr;


#endif /* COMMON_USAGE_H_ */