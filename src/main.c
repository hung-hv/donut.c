#include <stdio.h>
#include <stdint.h>
#include "cursor.h"
#include "fps.h"

int main () {
    int a = 0;
    while(1) {
        if(a == 10000) {
            render_array();
            a=0;
        }
        a++;
    }
    
    getch();
}