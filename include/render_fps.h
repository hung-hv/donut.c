#ifndef RENDER_FPS_H
#define RENDER_FPS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "cursor.h"
#include <stdbool.h>

typedef struct Vector_2D_t Vector_2D_t;
#include "torus.h"
#include "common.h"


// Input data structure
typedef struct {
    Vector_2D_t* points;       // Array of 2D screen coordinates
    int point_count;        // Number of points to render
    uint8_t* intensity;     // Optional: brightness per point (0-255)
    bool use_intensity;     // Whether to use intensity values
} RenderInput_t;

// Output buffer structure
typedef struct {
    char* buffer;           // Character array ready for printf
    uint8_t* pixel_buffer;  // Internal pixel array [x][y] flattened
    int width, height;      // Screen dimensions
    bool dirty;             // Whether buffer needs redraw
    int buffer_size;        // Total buffer size
} ScreenBuffer_t;

//API function
void render_points_to_buffer(ScreenBuffer_t* screen, RenderInput_t input);

// Core rendering functions
ScreenBuffer_t* create_screen_buffer(int width, int height);
void clear_screen_buffer(ScreenBuffer_t* screen);
void finalize_buffer(ScreenBuffer_t* screen);
void free_screen_buffer(ScreenBuffer_t* screen);

// Utility functions
void set_pixel_safe(ScreenBuffer_t* screen, int x, int y, uint8_t value);
uint8_t get_pixel_safe(ScreenBuffer_t* screen, int x, int y);
char intensity_to_char(uint8_t intensity);

#ifdef __cplusplus
}
#endif

#endif // RENDER_FPS_H