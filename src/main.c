#include <stdio.h>
#include <stdint.h>
#include "cursor.h"
#include "fps.h"
#include "torus.h"

Circle_t circle1;

int main () {
    int a = 0;
    initCircle(&circle1, 50);
    Circle_CordinateCalc(&circle1, 7);
    printf("size: %d\n", circle1.pointsSize);
    while(1) {
        // render_2d_array();
        transferCord2Pixels(circle1.vector, circle1.pointsSize );
        render_screen();
    }
    

    
    // dummyData(&circle1);
    // printData(&circle1);

    
    // getch();
}