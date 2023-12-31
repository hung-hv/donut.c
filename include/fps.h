#ifndef FPS_H
#define FPS_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "cursor.h"

#define X_SIZE 60
#define Y_SIZE 20

extern const float PI;


// extern uint8_t pixel[X_SIZE][Y_SIZE];

typedef struct PointCordinate {
    uint16_t x;
    uint16_t y;
    uint16_t z;
} point_t;

typedef struct Object {
    point_t* point;
    uint32_t num_point;
} obj_t;

extern obj_t* torus;

uint8_t random(uint8_t lower, uint8_t upper);
void random_pixel();

void render_2d_array();

void render_screen();

void calc_cordinate_as_torus();

void calc_pixel();

#endif