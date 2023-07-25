#ifndef FPS_H
#define FPS_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "cursor.h"

#define X_SIZE 70
#define Y_SIZE 20

// extern uint8_t pixel[X_SIZE][Y_SIZE];

uint8_t random(uint8_t lower, uint8_t upper);
void random_pixel();

void render_2d_array();

void render_screen();

#endif