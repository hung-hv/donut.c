#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "cursor.h"
#include "fps.h"
#include "torus.h"
#include "render_fps.h"

// Windows-compatible sleep function
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

Circle_t circle1;
Vector_2D_t center1;

int x_max_test = 100;
int y_max_test = 40;

int main() {
    printf("Initializing animation...\n");
    
    // Initialize circle
    initCircle(&circle1, 30);
    
    // Check if initialization was successful
    if (circle1.vector == NULL) {
        printf("Error: Failed to initialize circle!\n");
        return 1;
    }
    
    // Create screen buffer with dynamic dimensions
    ScreenBuffer_t* screen = create_screen_buffer(x_max_test, y_max_test);
    if (screen == NULL) {
        printf("Error: Failed to create screen buffer!\n");
        free(circle1.vector);
        return 1;
    }
    
    // Animation parameters
    float time = 0.0f;
    float radius = 4.0f;
    int frame_count = 0;
    
    // Dynamic motion radius based on screen size
    float motion_radius_x = x_max_test * 0.25f;  // 25% of screen width
    float motion_radius_y = y_max_test * 0.25f;  // 25% of screen height
    
    printf("Starting circle animation... Press Ctrl+C to stop\n");
    printf("Screen: %dx%d, Motion radius: %.1fx%.1f\n", 
           x_max_test, y_max_test, motion_radius_x, motion_radius_y);
    
    // Wait a moment before starting
    SLEEP_MS(1000);
    
    while(1) {
        // Calculate moving center (circular motion)
        center1.x_cord = x_max_test/2 + cos(time) * motion_radius_x;  // Center X + circular motion
        center1.y_cord = y_max_test/2 + sin(time) * motion_radius_y;  // Center Y + circular motion
        
        // Generate circle coordinates
        Circle_CordinateCalc(&circle1, radius, center1);
        
        // Prepare render input
        RenderInput_t render_input = {
            .points = circle1.vector,
            .point_count = circle1.pointsSize,
            .intensity = NULL,
            .use_intensity = false
        };
        
        // Render to buffer
        render_points_to_buffer(screen, render_input);
        
        // Clear screen and display
        clear();
        printf("Frame: %d | Time: %.2f | Center: (%.1f, %.1f)\n", 
               frame_count, time, center1.x_cord, center1.y_cord);
        printf("%s", screen->buffer);
        
        // Update animation
        time += 0.1f;
        frame_count++;
        
        // Cross-platform delay (50ms)
        SLEEP_MS(50);
        
        // Optional: stop after some frames for testing
        // if (frame_count > 200) break;
    }
    
    // Cleanup
    free_screen_buffer(screen);
    free(circle1.vector);
    
    return 0;
}