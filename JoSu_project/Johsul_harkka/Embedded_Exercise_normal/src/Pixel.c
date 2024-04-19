/*
 * Pixel.c
 *
 *  Created on: -----
 *      Author: -----
 */

#include "Pixel.h"



//Table for pixel dots.
//				 dots[X][Y][COLOR]
volatile uint8_t dots[8][8][3]={0};

uint8_t *channel = 0x41220000;
uint8_t *control = 0x41220008;


// Here the setup operations for the LED matrix will be performed
void setup(){

	*channel = 0;
	*control = 0;
	// Resetting the screen at start is a MUST to operation (Set RSTn to 1).

	usleep(500);

	*control |= 0b00001;

	usleep(500);

	*control |= 0b00000;

	// changing the SDA-bit to 1 to send serial data

	*control |= 0b10000;


	//Write code that sets 6-bit values in register of DM163 chip. Recommended that every bit in that register is set to 1. 6-bits and 24 "bytes", so some kind of loop structure could be nice.
	//24*6 bits needs to be transmitted

	for(int i = 0; i<= 144; i++){
		*control |= 0b10000;
		*control |= 0b01000;
		*control &= 0b10111;
	}




	//Final thing in this function is to set SB-bit to 1 to enable transmission to 8-bit register.

	*control |= 0b00100;

}

//Change value of one pixel at led matrix. This function is only used for changing values of dots array
void SetPixel(uint8_t x,uint8_t y, uint8_t r, uint8_t g, uint8_t b){

	//Hint: you can invert Y-axis quite easily with 7-y
	dots[x][y][0]=b;

	//Write rest of two lines of code required to make this function work properly (green and red colors to array).
	dots[x][y][1]=g;
	dots[x][y][2]=r;

}


//Put new data to led matrix. Hint: This function is supposed to send 24-bytes and parameter x is for channel x-coordinate.
void run(uint8_t x){



	//Write code that writes data to led matrix driver (8-bit data). Use values from dots array

	*control |= 0b00000;
	//Hint: use nested loops (loops inside loops)
	//Hint2: loop iterations are 8,3,8 (pixels,color,8-bitdata)

	for(uint8_t y=0; y<8;y++){
		for(uint8_t color=0; color<3; color++){
			uint8_t current_led = dots[x][y][color];
			for(uint8_t byte_count=0; byte_count<8;byte_count++){
				if(current_led & 0b10000000){
					*control |= 0b10000;
				}
				else{
					*control &= 0b01111;
				}
				current_led << 1;
				*control |= 0b01000;
				*control &= 0b10111;
			}
		}
	}

	latch();

}

//Latch signal. See colorsshield.pdf or DM163.pdf in project folder on how latching works
void latch(){
	*control |= 0b00010;

	*control &= 0b11101;

}


//Set one line (channel) as active, one at a time.
void open_line(uint8_t x){
	switch(x){
	case 0: *channel = 0b00000001; break;
	case 1: *channel = 0b00000010; break;
	case 2: *channel = 0b00000100; break;
	case 3: *channel = 0b00001000; break;
	case 4: *channel = 0b00010000; break;
	case 5: *channel = 0b00100000; break;
	case 6: *channel = 0b01000000; break;
	case 7: *channel = 0b10000000; break;

	default: *channel = 0;
	}

}



