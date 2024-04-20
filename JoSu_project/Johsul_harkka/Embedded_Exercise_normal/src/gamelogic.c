/*
 * gamelogic.c
 *
 *  Created on: 11 Apr 2024
 *      Author: mcish
 */

#include "gamelogic.h"

extern uint8_t ship_x;
extern uint8_t bullet_direction;
extern uint8_t bullet_y;

void make_alien(uint8_t x,uint8_t y,uint8_t direction){
	uint8_t i, j;

	uint8_t alien_width = 1;
	uint8_t alien_height = 1;

	for(i=0; i<alien_width; i++){
		for(j = 0; j<alien_height; j++){

			SetPixel(x+i,y+j,0,128,0);
		}
	}

	if(direction != 0){
		uint8_t prev_x = x - direction;

		if(prev_x >= 0 && prev_x < 8){
			for(i=0; i<alien_width;i++){
				for(j=0; j<alien_height;j++){
					SetPixel(prev_x+i,y+j,228,155,15);
				}
			}
		}
	}
}

void activate_board(){
	uint8_t i, j;

	for(i=0; i<8; i++){
		for(j=0;j<8;j++){
			SetPixel(i,j,228,155,15);
		}
	}
}

void make_ship(uint8_t ship_x){
	uint8_t i, j;

	for(i=3; i<6; i++){
		SetPixel(ship_x+i-3,6,0,0,255);
	}

	for(j=5; j<7; j++){
		SetPixel(ship_x+1,j,0,0,255);
	}
}

void move_ship_right(){


	for(uint8_t i = 3; i<6;i++){
		for(uint8_t j = 6; j<8;j++){
			SetPixel(ship_x+i-3,j,228,155,15);
		}
	}

	ship_x += 1;

	if(ship_x >= 6){
		ship_x -= 1;
	}



	make_ship(ship_x);





}

void move_ship_left(){
	for(uint8_t i = 3; i<6;i++){
			for(uint8_t j = 6; j<8;j++){
				SetPixel(ship_x+i-3,j,228,155,15);
			}
		}


		if(ship_x != 0){
			ship_x -= 1;;
		}


		make_ship(ship_x);
}

void make_bullet(uint8_t x,uint8_t y, uint8_t direction) {
    uint8_t i,j;

    uint8_t bullet_width = 1;
    uint8_t bullet_height = 1;

    for(i=0;i<bullet_width;i++){
    	for(j=0;j<bullet_height;j++){
    		SetPixel(x+i,y+j,255,0,0);
    	}
    }

    if(direction != 0){
    	uint8_t prev_y = y - direction;
    	if(prev_y >= 0 && prev_y < 8){
    		for(i=0;i<bullet_width;i++){
    			for(j=0;j<bullet_height;j++){
    				SetPixel(prev_y+i,y+j,228,155,15);
    			}
    		}
    	}
    }

}

void move_bullet() {
    // Clear the previous position of the bullet
    SetPixel(ship_x+1, bullet_y, 0, 0, 0);

    // Move the bullet upwards (assuming the bullet moves upward)
    bullet_y -= bullet_direction;

    // Draw the bullet at the new position
    SetPixel(ship_x+1, bullet_y, 0, 255, 0);
}
