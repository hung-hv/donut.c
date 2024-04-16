#include "fps.h"
#include "torus.h"

uint8_t pixel[X_SIZE][Y_SIZE] = {0};
char render_buff[X_SIZE*Y_SIZE] = {0};
obj_t* torus;

uint16_t x_cor[50] = {0};
uint16_t y_cor[50] = {0};
// const float PI = 3.14;

void init_object() {
    const uint32_t obj_size = 100;
    torus = (obj_t*)malloc(sizeof(obj_t));
    /*init obj_size */
    torus->point = (point_t*)malloc(sizeof(point_t)*obj_size);
    torus->num_point = obj_size;
}

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
    const int delay = 500; //ms
    uint8_t breakCondition = 0;
    
    while (breakCondition == 0) {
        if (cur_time == 0) {
            cur_time = clock() * 1000 / CLOCKS_PER_SEC;
            post_time = cur_time;
        }
        if ((cur_time - post_time) >= delay) {
            // clear();
            // clearScreenBuffer();
            render_2d_array();
            // post_time = cur_time;
            breakCondition=1;
        }
        cur_time = clock() * 1000 / CLOCKS_PER_SEC;
        // post_time = clock() * 1000 / CLOCKS_PER_SEC;
    }

}


void render_2d_array() {
    // char* render_buff = (char*)malloc(sizeof(char)*((X_SIZE*Y_SIZE)));
    uint64_t index = 0;
    // random_pixel();
    // calc_pixel();
    /* Clear buffer array */ 
    // for(int y = 0; y < Y_SIZE; y++) {
    //     for(int x = 0; x < (X_SIZE-1); x++) {
    //         render_buff[index] = '0';
    //         index++;
    //     }
    //     render_buff[index] = '\n';
    //     index++;
    // }
    /* Calculate Array */
    for(int y = 0; y < Y_SIZE; y++) {
        for(int x = 0; x < (X_SIZE-1); x++) {
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
    clearPixels();
}

void clearScreenBuffer() {
    uint64_t index = 0;
    for(int y = 0; y < Y_SIZE; y++) {
        for(int x = 0; x < (X_SIZE-1); x++) {
            render_buff[index] = '0';
            index++;
        }
        render_buff[index] = '\n';
        index++;
    }
    clear();
    printf("%s", render_buff);
}

void clearPixels() {
    for(int y = 0; y < Y_SIZE; y++) {
        for(int x = 0; x < (X_SIZE-1); x++) {
            pixel[x][y] = 0;
        }
    }
}

// void calc_pixel(Vector_t *p_vector) {
//     calc_cordinate_as_torus();
//     for(int i = 0; i < 50; i++) {
//         pixel[x_cor[i]][y_cor[i]] = 1;
//     }
// }

void transferCord2Pixels(Vector3D_t *p_vector3D, int max_size) {
    for(int i = 0; i < max_size; i++) {
        pixel[(int)(p_vector3D[i].x_cord)][(int)(p_vector3D[i].y_cord)] = 1;
    }   
}

