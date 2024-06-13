#include "color.h"

void ghostFG(){
    printf("\x1b[38;5;161m");
}

void alienFG(){
    printf("\x1b[38;5;46m");
}

void squidFG(){
    printf("\x1b[38;5;14m");
}

void reset(){
    printf("\x1b[0m");
}
