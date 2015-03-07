#ifndef BASICWINDOW_H_INCLUDED
#define BASICWINDOW_H_INCLUDED

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "GLUtils.h"

class BasicWindow
{

public:
    static bool initWindow();
    //Screen dimension constants
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;
    static const int SCREEN_FPS = 60;
};

#endif // BASICWINDOW_H_INCLUDED
