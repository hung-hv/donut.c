#include "torus.h"


// const float PI = 3.14;
// Vector_t vector1;

void initCircle (Circle_t *circle, int size) {
    // circle = (Circle_t*)malloc(size*sizeof(Circle_t));
    circle->numberOfVector = size;
    printf("size: %d\n", circle->numberOfVector);
    // int init_size = circle->rad_step;
    // for (int i = 0; i < init_size; i++) {
        circle->vector3D= (Vector3D_t*)malloc(size*sizeof(Vector3D_t));
    // }
    printf("Init done!\n");
}

void dummyData (Circle_t *circle) {
    for (int i = 0; i < circle->numberOfVector ; i++) {
        circle->vector[i].x_cord = (float)i;
        circle->vector[i].y_cord = (float)i;
    }
    printf("Dummy done!\n");
}

void printData (Circle_t *circle) {
    for (int i = 0; i < circle->numberOfVector ; i++) {
        printf("\nx_cord:");
        printf("\n%f", circle->vector[i].x_cord);
        printf("\ny_cord:");
        printf("\n%f", circle->vector[i].y_cord);
    }
    printf("Print done!\n");
}

void Circle_CordinateCalc(Circle_t *circle, Vector3D_t centerPoint) {
    // const float radius = 7;
    // const uint16_t circle_split = 60; /* split circle into x parts */
    int circle_factor = circle->numberOfVector;  /* split circle into x parts */
    const float theta_step = (2*PI)/((float)circle_factor); /* a circle = 2*PI */
    for(int i = 0; i < circle_factor; i++) {
        circle->vector3D[i].x_cord =(centerPoint.x_cord) + cos(theta_step*i)*(circle->circleRadius);
        circle->vector3D[i].y_cord =(centerPoint.y_cord) + sin(theta_step*i)*(circle->circleRadius);
    }
}

// void Circle_3D_cordinateCalc(Circle_t *circle, float radius, Vector_t center) {
//     // const float radius = 7;
//     // const uint16_t circle_split = 60; /* split circle into x parts */
//     int circle_split = circle->numberOfVector;  /* split circle into x parts */
//     const float theta_step = (2*PI)/((float)circle_split); /* a circle = 2*PI */
//     for(int i = 0; i < circle_split; i++) {
//         circle->vector[i].x_cord =(center.x_cord) + cos(theta_step*i)*radius;
//         circle->vector[i].y_cord =(center.y_cord) + sin(theta_step*i)*radius;
//     }
// }

void Torus_CordinateCalc(Torus_t *torus, Circle_t *circle, int numberOfCircle) {
    ScreenCord_t output_point;
    if (numberOfCircle != 0) {
        torus->numberOfCircle = numberOfCircle;
        torus->circle = (Circle_t*)malloc(numberOfCircle*sizeof(Circle_t));
    }
    
    // const float radius = 7;
    // const uint16_t circle_split = 60; /* split circle into x parts */
    // int theta_factor = torus->numberOfCircle;  /* split torus into x parts */
    const float delta_torus = (2*PI)/((float)numberOfCircle); /* a circle = 2*PI */
    
    int numberOfVector = circle->numberOfVector;
    const float delta_circle = (2*PI)/((float)numberOfVector);
    // int numberOfVector = circle->numberOfVector;
    for(int i = 0; i < numberOfCircle; i++) {
        float torus_angle = delta_torus *i;
        torus->circle->vector3D = (Vector3D_t*)malloc(numberOfVector*sizeof(Vector3D_t));
        for (int j = 0; i < numberOfVector; j ++) {
            float circle_angle = delta_circle *j;
            torus->circle->vector3D->x_cord = 
        }
        circle->vector[i].x_cord =(center.x_cord) + cos(theta_step*i)*radius;
        circle->vector[i].y_cord =(center.y_cord) + sin(theta_step*i)*radius;
    }
}

// void centerDummy (Vector_t *center) {

// }