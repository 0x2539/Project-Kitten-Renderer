#ifndef GLUTILS_H_INCLUDED
#define GLUTILS_H_INCLUDED

#include <iostream>
#include "BasicWindow.h"
#include "ShaderUtils.h"

using namespace std;

extern SDL_Window* _gWindow;

class GLUtils
{
private:

    static bool initGL(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    static bool loadGP();
    static bool loadMedia();

public:
    static bool initGraphics(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    static SDL_Window* getWindow();

    static void setWindow(SDL_Window *gWindow);
};


#endif // GLUTILS_H_INCLUDED
