#include <stdio.h>
#include <stdint.h>
#include "cursor.h"
#include "fps.h"
#include "torus.h"

Circle_t circle1;
Vector3D_t center1;
Torus_t torus1;
struct Buffer2D_t *screen;

void main() {
    int n = 20;
    // center1.x_cord = n;
    // center1.y_cord = n;
    // int a = 0;
    circle1.centerPoint.x_cord = n;
    circle1.centerPoint.y_cord = n;
    circle1.centerPoint.z_cord = 0;
    circle1.circleRadius = 4;
    circle1.numberOfVector = 20;
    initCircle(&circle1, 20);
    Circle_CordinateCalc(&circle1);
    printf("size: %d\n", circle1.numberOfVector);

    torus1.torusRadius = 5;
    // torus1.numberOfCircle = 5;
    // Circle_CordinateCalc(&circle1);
    // printf("check2");
    initTorus(&torus1, 8);
    Torus_CordinateCalc(&torus1, &circle1);
    // printf("check3");
    // transferCord2Pixels(circle1.vector3D, circle1.numberOfVector );
    // screen = convert_xyz_2_xy(torus1.circle->vector3D, torus1.circle->numberOfVector, 5, 8);
    // printf("check4");
    int i = 0;
    while(1) {
        // render_2d_array();
        // circle1.centerPoint.x_cord = n++;
        // circle1.centerPoint.y_cord = 4;
        // printf("check1");
        // Circle_CordinateCalc(&circle1);
        // // printf("check2");
        // Torus_CordinateCalc(&torus1, &circle1, 10);
        // // printf("check3");
        // // transferCord2Pixels(circle1.vector3D, circle1.numberOfVector );
        Circle_CordinateCalc(&circle1);
        Torus_CordinateCalc(&torus1, &circle1);
        screen = convert_xyz_2_xy(torus1.circle[0].vector3D, torus1.circle->numberOfVector, 12.5, 5);
        // printf("check4");
        convert_bufer2D_2_Pixels(screen, 20);
        render_screen();
        // printf("check5");

        // n++;
        // circle1.centerPoint.x_cord = n;
        // circle1.centerPoint.y_cord = n;
        
        i++;
        if(i >= 7) i = 0;
    }
    

    
    // dummyData(&circle1);
    // printData(&circle1);

    
    // getch();
}