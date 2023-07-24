#include "fps.h"

uint8_t pixel[X_SIZE][Y_SIZE] = {0};

uint8_t random(uint8_t lower, uint8_t upper) {
    uint8_t num = (uint8_t)((rand() % (upper - lower + 1)) + lower);
    return num;
}

void random_pixel() {
    for(int x = 0; x < X_SIZE; x++) {
        for(int y = 0; y < X_SIZE; y++) {
            pixel[x][y] = random(0, 1);
        }
    }
}
void render_array() {
    clear();
    random_pixel();
    for(int y = 0; y < X_SIZE; y++) {
        for(int x = 0; x < X_SIZE; x++) {
            gotoxy(x, y);
            printf("%d", pixel[x][y]);
            // putchar(pixel[x][y]);
        }
    }
}