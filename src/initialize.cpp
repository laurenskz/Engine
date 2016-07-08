//
// Created by Laurens on 6-7-2016.
//

#include <SDL.h>
#include <iostream>
#include <glew.h>
#include "initialize.h"
using std::cerr;
using std::endl;

bool init(const  std::string &name,int width, int height,SDL_Window *&window){
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
                cerr << "Unable to initialize SDL:  " << SDL_GetError();

        return false;
    }

    window = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(window);
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        cerr << "Error: " << glewGetErrorString(err) << endl;
        return false;
    }
    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << endl;
    return true;
}