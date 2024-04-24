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
void make_bullet(uint8_t x,uint8_t y, uint8_t direction);
void display_score(uint8_t score);
void display_victory();
void reset_scoreboard();

#endif /* SRC_GAMELOGIC_H_ */
