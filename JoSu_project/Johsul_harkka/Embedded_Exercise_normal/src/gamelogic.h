/*
 * gamelogic.h
 *
 *  Created on: 11 Apr 2024
 *      Author: mcish
 */

#ifndef SRC_GAMELOGIC_H_
#define SRC_GAMELOGIC_H_

#include "Pixel.h"


void make_alien(uint8_t x,uint8_t y,uint8_t direction);
void activate_board();
void make_ship(uint8_t ship_x);
void move_ship_left();
void move_ship_right();
void shoot_bullet();

#endif /* SRC_GAMELOGIC_H_ */
