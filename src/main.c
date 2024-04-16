#include <stdio.h>
#include <stdint.h>
#include "cursor.h"
#include "fps.h"
#include "torus.h"

Circle_t circle1;
Vector3D_t center1;
Torus_t torus1;
ScreenCord_t *screen;

void main() {
    int n = 4;
    center1.x_cord = n;
    center1.y_cord = n;
    int a = 0;
    circle1.centerPoint.x_cord = n;
    circle1.centerPoint.y_cord = n;
    circle1.centerPoint.z_cord = 0;
    circle1.circleRadius = 4;
    circle1.numberOfVector = 50;
    initCircle(&circle1, 50);
    Circle_CordinateCalc(&circle1);
    printf("size: %d\n", circle1.numberOfVector);

    torus1.torusRadius = 10;
    while(1) {
        // render_2d_array();
        // circle1.centerPoint.x_cord = n++;
        // circle1.centerPoint.y_cord = 4;
        Circle_CordinateCalc(&circle1);
        Torus_CordinateCalc(&torus1, &circle1, 10);
        // transferCord2Pixels(circle1.vector3D, circle1.numberOfVector );
        screen = convert_xyz_2_xy()
        render_screen();
    }
    

    
    // dummyData(&circle1);
    // printData(&circle1);

    
    // getch();
}