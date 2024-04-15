#include <stdio.h>
#include <stdint.h>
#include "cursor.h"
#include "fps.h"
#include "torus.h"

Circle_t circle1;
Vector_t center1;


int main () {
    int n = 4;
    center1.x_cord = n;
    center1.y_cord = n;
    int a = 0;
    initCircle(&circle1, 50);
    
    center1.x_cord = n++;
    center1.y_cord = n++;
    Circle_CordinateCalc(&circle1, 4, center1);
    printf("size: %d\n", circle1.numberOfVector);
    while(1) {
        // render_2d_array();
        center1.x_cord = n++;
        center1.y_cord = n++;
        Circle_CordinateCalc(&circle1, 4, center1);
        transferCord2Pixels(circle1.vector, circle1.numberOfVector );
        render_screen();
    }
    

    
    // dummyData(&circle1);
    // printData(&circle1);

    
    // getch();
}