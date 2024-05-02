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

// void dummyData (Circle_t *circle) {
//     for (int i = 0; i < circle->numberOfVector ; i++) {
//         circle->vector[i].x_cord = (float)i;
//         circle->vector[i].y_cord = (float)i;
//     }
//     printf("Dummy done!\n");
// }

// void printData (Circle_t *circle) {
//     for (int i = 0; i < circle->numberOfVector ; i++) {
//         printf("\nx_cord:");
//         printf("\n%f", circle->vector[i].x_cord);
//         printf("\ny_cord:");
//         printf("\n%f", circle->vector[i].y_cord);
//     }
//     printf("Print done!\n");
// }

void Circle_CordinateCalc(Circle_t *circle) {
    // const float radius = 7;
    // const uint16_t circle_split = 60; /* split circle into x parts */
    int circle_factor = circle->numberOfVector;  /* split circle into x parts */
    const float theta_step = (2*PI)/((float)circle_factor); /* a circle = 2*PI */
    for(int i = 0; i < circle_factor; i++) {
        circle->vector3D[i].x_cord =(circle->centerPoint.x_cord) + cos(theta_step*i)*(circle->circleRadius);
        circle->vector3D[i].y_cord =(circle->centerPoint.y_cord) + sin(theta_step*i)*(circle->circleRadius);
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

void initTorus(Torus_t *torus, int numberOfCircle) {
    if (numberOfCircle != 0) {
        torus->numberOfCircle = numberOfCircle;
        torus->circle = (Circle_t*)malloc(numberOfCircle*sizeof(Circle_t));
    }
}

void Torus_CordinateCalc(Torus_t *torus, Circle_t *circle) {
    // ScreenCord_t output_point;
    // if (numberOfCircle != 0) {
    //     torus->numberOfCircle = numberOfCircle;
    //     torus->circle = (Circle_t*)malloc(numberOfCircle*sizeof(Circle_t));
    // }
    
    // const float radius = 7;
    // const uint16_t circle_split = 60; /* split circle into x parts */
    // int theta_factor = torus->numberOfCircle;  /* split torus into x parts */
    int numberOfCircle = torus->numberOfCircle;
    const float delta_torus = (2*PI)/((float)numberOfCircle); /* a circle = 2*PI */
    
    int numberOfVector = circle->numberOfVector;
    const float delta_circle = (2*PI)/((float)numberOfVector);
    // printf("check5");
    // int numberOfVector = circle->numberOfVector;
    // printf("\nNumber of circles:  %d, ", numberOfCircle);
    for(int i = 0; i < numberOfCircle; i++) {
        float torus_angle = delta_torus *i;
        torus->circle[i].vector3D = (Vector3D_t*)malloc(numberOfVector*sizeof(Vector3D_t));
        torus->circle->numberOfVector = numberOfVector;
        // printf("\nCircle %d, ", i);
        // printf("\nNumber of vector:  %d, ", numberOfVector);
        for (int j = 0; j < numberOfVector; j++) {
            // float circle_angle = delta_circle *j;
            float sub_expression = torus->torusRadius + circle->vector3D[j].x_cord;
            torus->circle[i].vector3D[j].x_cord = (sub_expression) * cos(torus_angle);
            // printf("\n x = %f, ", torus->circle[i].vector3D[j].x_cord);
            torus->circle[i].vector3D[j].y_cord = circle->vector3D[j].y_cord;
            // printf("y = %f, ", torus->circle[i].vector3D[j].y_cord);
            torus->circle[i].vector3D[j].z_cord = -(sub_expression) * sin(torus_angle);
            // printf("z = %f", torus->circle[i].vector3D[j].z_cord);
        }
    }
}

/* Export [x,y] in screen cordinate */
struct Buffer2D_t * convert_xyz_2_xy(Vector3D_t *vector3D, int total_vectors, float fieldOfView, float z_distance) {
    struct Buffer2D_t *output_buffer = (struct Buffer2D_t*)malloc(total_vectors * sizeof(struct Buffer2D_t));
    // printf("check41");
    // printf("\nNumber of vector:  %d, ", total_vectors);
    for (int i =0; i < total_vectors; i++) {
        output_buffer[i].x_cord = (int)( (vector3D[i].x_cord * fieldOfView) / (z_distance - vector3D[i].z_cord) );
        // printf("\nx_cord = %d, ", output_buffer[i].x_cord);
        output_buffer[i].y_cord = (int)( (vector3D[i].y_cord * fieldOfView) / (z_distance - vector3D[i].z_cord) );
        // printf("y_cord = %d, ", output_buffer[i].y_cord);   
    }   
    // printf("check42");
    return output_buffer;
}

void shifting(Circle_t *circle, float x_shift, float y_shift, float z_shift) {
    circle->centerPoint.x_cord = x_shift;
    circle->centerPoint.y_cord = y_shift;
    circle->centerPoint.z_cord = z_shift;
}

// ScreenCord_t ** convertTorus_2_xyScreen(Torus_t *torus)

// void centerDummy (Vector_t *center) {

// }