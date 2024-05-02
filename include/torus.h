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

struct Buffer2D_t{
    int x_cord;
    int y_cord;
};

struct Vector3D_t{
    float x_cord;
    float y_cord;
    float z_cord;
};

typedef struct {
    float x_cord;
    float y_cord;
    float z_cord;
}Point3D_t;

typedef struct {
    float x_angle;
    float y_angle;
    float z_angle;
}SpinAngle_t;

typedef struct {
    Vector3D_t *vector3D;
    int numberOfVector;     /* number of points to draw a circle*/
    int circleRadius; /* Radius of Circle*/
    Point3D_t centerPoint;
} Circle_t;

typedef struct {
    // Vector3D_t *vector3D;
    Circle_t *circle;
    int numberOfCircle;     /* number of step to spining circle around axis to a torus*/
    int torusRadius; /* Torus of Circle*/
} Torus_t;

void initCircle (Circle_t *circle, int size);

// void dummyData (Circle_t *circle);

// void printData (Circle_t *circle);

void Circle_CordinateCalc(Circle_t *circle);

void initTorus(Torus_t *torus, int numberOfCircle);

void Torus_CordinateCalc(Torus_t *torus, Circle_t *circle);

struct Buffer2D_t * convert_xyz_2_xy(Vector3D_t *vector3D, int total_vectors, float fieldOfView, float z_distance);

void shifting(Circle_t *circle, float x_shift, float y_shift, float z_shift);
#endif