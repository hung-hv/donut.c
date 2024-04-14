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
typedef struct Vector_t Vector_t;
#include "torus.h"
#include "common.h"

#define X_SIZE 60
#define Y_SIZE 20

// extern const float PI;

// typedef struct Vector_t Vector_t;


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

void clearScreenBuffer();

void clearPixels();

void render_screen();

// void calc_pixel();

void transferCord2Pixels(Vector_t *p_vector, int max_size);

#endif