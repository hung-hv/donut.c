#include "render_fps.h"

// #define X_SIZE 60
// #define Y_SIZE 60

// uint8_t pixel[X_SIZE][Y_SIZE] = {0};  // 60x20 pixel buffer
// char render_buff[X_SIZE*Y_SIZE] = {0}; // Character output buffer

// Character mapping for different intensities
static const char INTENSITY_CHARS[] = {
    ' ',    // 0: Empty
    '.',    // 1: Very dim
    ':',    // 2: Dim
    '-',    // 3: Medium-dim
    '=',    // 4: Medium
    '+',    // 5: Medium-bright
    '*',    // 6: Bright
    '#',    // 7: Very bright
    '@',    // 8: Full intensity
    '█'     // 9: Maximum
};

#define NUM_INTENSITY_LEVELS (sizeof(INTENSITY_CHARS) - 1)

ScreenBuffer_t* create_screen_buffer(int width, int height) {
    ScreenBuffer_t* screen = (ScreenBuffer_t*)malloc(sizeof(ScreenBuffer_t));
    if (!screen) {
        return NULL; // Memory allocation failed
    }

    screen->width = width;
    screen->height = height;
    screen->buffer_size = width * height + height; // +height for newlines
    screen->buffer = (char*)malloc(screen->buffer_size);
    screen->pixel_buffer = (uint8_t*)calloc(width * height, sizeof(uint8_t));
    screen->dirty = true;

    if (!screen->buffer || !screen->pixel_buffer) {
        free(screen->buffer);
        free(screen->pixel_buffer);
        free(screen);
        return NULL; // Memory allocation failed
    }

    memset(screen->buffer, ' ', screen->buffer_size - 1);
    for (int y = 0; y < height; y++) {
        screen->buffer[(y + 1) * (width + 1) - 1] = '\n'; // Newline at end of each row
    }
    screen->buffer[screen->buffer_size - 1] = '\0'; // Null-terminate

    return screen;
}

void clear_screen_buffer(ScreenBuffer_t* screen) {
    if (!screen) return;
    // Clear pixel buffer
    memset(screen->pixel_buffer, 0, screen->width * screen->height);
    // Clear character buffer
    memset(screen->buffer, INTENSITY_CHARS[0], screen->buffer_size);
    screen->dirty = true;
}

// Set pixel with automatic bounds checking
void set_pixel_safe(ScreenBuffer_t* screen, int x, int y, uint8_t intensity) {
    if (!screen) return;
    if (x < 0 || x >= screen->width || y < 0 || y >= screen->height) return;
    
    int index = x + (y * screen->width);
    screen->pixel_buffer[index] = intensity;
    screen->dirty = true;
}

// Get pixel with bounds checking
uint8_t get_pixel_safe(ScreenBuffer_t* screen, int x, int y) {
    if (!screen) return 0;
    if (x < 0 || x >= screen->width || y < 0 || y >= screen->height) return 0;
    
    int index = y * screen->width + x;
    return screen->pixel_buffer[index];
}

// Convert intensity value to display character
char intensity_to_char(uint8_t intensity) {
    if (intensity == 0) return ' ';
    
    // Map 0-255 to character array indices
    int char_index = (intensity * NUM_INTENSITY_LEVELS) / 255;
    if (char_index >= NUM_INTENSITY_LEVELS) {
        char_index = NUM_INTENSITY_LEVELS - 1;
    }
    
    return INTENSITY_CHARS[char_index + 1]; // +1 to skip space character
}

void render_points_to_buffer(ScreenBuffer_t* screen, RenderInput_t input) {
    // Clear previous frame
    clear_screen_buffer(screen);
    // Render each point
    for (int i = 0; i < input.point_count; i++) {
        int x = (int)input.points[i].x_cord;
        int y = (int)input.points[i].y_cord;
        
        // Get intensity value
        uint8_t intensity = 255; // Default full intensity
        if (input.use_intensity && input.intensity) {
            intensity = input.intensity[i];
        }
        
        // Set pixel with bounds checking
        set_pixel_safe(screen, x, y, intensity);
    }

    // Convert pixel buffer to character buffer
    finalize_buffer(screen);
}

// Convert pixel buffer to character buffer
void finalize_buffer(ScreenBuffer_t* screen) {
    if (!screen || !screen->dirty) return;

    int buffer_index = 0;
    
    for (int y = 0; y < screen->height; y++) {
        for (int x = 0; x < screen->width; x++) {
            uint8_t pixel_value = get_pixel_safe(screen, x, y);
            screen->buffer[buffer_index++] = intensity_to_char(pixel_value);
        }
        
        // Add newline at end of each row
        screen->buffer[buffer_index++] = '\n';
        }
    
    // Null terminate
    screen->buffer[buffer_index] = '\0';
    screen->dirty = false;
}

// Clean up memory
void free_screen_buffer(ScreenBuffer_t* screen) {
    if (!screen) return;
    
    if (screen->buffer) free(screen->buffer);
    if (screen->pixel_buffer) free(screen->pixel_buffer);
    free(screen);
}