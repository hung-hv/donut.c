#include "fps.h"

uint8_t pixel[X_SIZE][Y_SIZE] = {0};

uint8_t random(uint8_t lower, uint8_t upper) {
    uint8_t num = (uint8_t)((rand() % (upper - lower + 1)) + lower);
    return num;
}

void random_pixel() {
    for(int x = 0; x < X_SIZE; x++) {
        for(int y = 0; y < Y_SIZE; y++) {
            pixel[x][y] = random(0, 1);
        }
    }
}

void render_screen() {
    int cur_time = 0;
    int post_time = 0;
    const int delay = 200; //ms
    
    while (1) {
        if ((cur_time - post_time) >= delay) {
            // clear();
            render_2d_array();
            post_time = cur_time;
        }
        cur_time = clock() * 1000 / CLOCKS_PER_SEC;
        // post_time = clock() * 1000 / CLOCKS_PER_SEC;
    }

}


void render_2d_array() {
    char* render_buff = (char*)malloc(sizeof(char)*((X_SIZE*Y_SIZE) + Y_SIZE));
    uint64_t index = 0;
    random_pixel();
    for(int y = 0; y < Y_SIZE; y++) {
        for(int x = 0; x < X_SIZE; x++) {
            if (pixel[x][y] == 1) {
                render_buff[index] = '1';
            } 
            if (pixel[x][y] == 0) {
                render_buff[index] = '0';
            } 
            //  = pixel[x][y];
            index++;
            // putchar(pixel[x][y]);
        }
        render_buff[index] = '\n';
        index++;
    }
    clear();
    printf("%s", render_buff);

}

