#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include "cursor.h"
#include "fps.h"
#include "torus.h"

Circle_t circle1;
Vector_2D_t center1;

int main() {
    // Initialize circle
    initCircle(&circle1, 30);  // 30 points for smoother circle
    
    // Animation parameters
    float time = 0.0f;
    float radius = 6.0f;
    int frame_count = 0;
    
    printf("Starting simple circle animation...\n");
    printf("Watch the circle move in a figure-8 pattern!\n\n");
    
    while(frame_count < 100) {  // Run for 100 frames
        // Calculate moving center (figure-8 motion)
        center1.x_cord = 30 + sin(time) * 20;      // Horizontal motion
        center1.y_cord = 10 + sin(time * 2) * 7;   // Vertical figure-8
        
        // Generate circle coordinates
        Circle_CordinateCalc(&circle1, radius, center1);
        
        // Transfer to pixel buffer (your existing function)
        transferCord2Pixels(circle1.vector, circle1.pointsSize);
        
        // Clear and render (your existing system)
        clear();
        printf("Frame: %d | Center: (%.1f, %.1f)\n", 
               frame_count, center1.x_cord, center1.y_cord);
        render_2d_array();
        
        // Update animation
        time += 0.2f;
        frame_count++;
        
        // Delay between frames
        #ifdef _WIN32
            Sleep(150);  // Windows
        #else
            struct timespec ts = {0, 150000000}; // 150ms
            nanosleep(&ts, NULL);  // Unix/Linux
        #endif
    }
    
    printf("\nAnimation complete!\n");
    
    // Cleanup
    if (circle1.vector) {
        free(circle1.vector);
    }
    
    return 0;
}
