#include "torus.h"


// const float PI = 3.14;
// Vector_t vector1;

void initCircle (Circle_t *circle, int size) {
    // circle = (Circle_t*)malloc(size*sizeof(Circle_t));
    circle->pointsSize = size;
    printf("size: %d\n", circle->pointsSize);
    // int init_size = circle->rad_step;
    // for (int i = 0; i < init_size; i++) {
        circle->vector= (Vector_t*)malloc(size*sizeof(Vector_t));
    // }
    printf("Init done!\n");
}

void dummyData (Circle_t *circle) {
    for (int i = 0; i < circle->pointsSize ; i++) {
        circle->vector[i].x_cord = (float)i;
        circle->vector[i].y_cord = (float)i;
    }
    printf("Dummy done!\n");
}

void printData (Circle_t *circle) {
    for (int i = 0; i < circle->pointsSize ; i++) {
        printf("\nx_cord:");
        printf("\n%f", circle->vector[i].x_cord);
        printf("\ny_cord:");
        printf("\n%f", circle->vector[i].y_cord);
    }
    printf("Print done!\n");
}

void Circle_CordinateCalc(Circle_t *circle, float radius, Vector_t center) {
    // const float radius = 7;
    // const uint16_t circle_split = 60; /* split circle into x parts */
    int circle_split = circle->pointsSize;  /* split circle into x parts */
    const float theta_step = (2*PI)/((float)circle_split); /* a circle = 2*PI */
    for(int i = 0; i < circle_split; i++) {
        circle->vector[i].x_cord =(center.x_cord) + cos(theta_step*i)*radius;
        circle->vector[i].y_cord =(center.y_cord) + sin(theta_step*i)*radius;
    }
}

// void centerDummy (Vector_t *center) {

// }