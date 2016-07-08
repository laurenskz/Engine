// A simple program that computes the square root of a number

#include <iostream>
#include <SDL_video.h>
#include "initialize.h"
using std::cout;
using std::endl;
int main(int argc, char **argv) {
    SDL_Window *window = NULL;
    init("op", 640, 480, window);

    return 0;
}