#ifndef TORUS_H
#define TORUS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "fps.h"

#define PI 3.14
// extern const float PI;

// typedef struct Vector_t Vector_t;

// struct Vector_t{
//     float x_cord;
//     float y_cord;
// };

struct Vector_t{
    float x_cord;
    float y_cord;
};

typedef struct {
    Vector_t *vector;
    int pointsSize;     /* number of points to draw a circle*/
} Circle_t;

void initCircle (Circle_t *circle, int size);

void dummyData (Circle_t *circle);

void printData (Circle_t *circle);

void Circle_CordinateCalc(Circle_t *circle, float radius, Vector_t center);
#endif