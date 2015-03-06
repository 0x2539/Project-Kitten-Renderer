#ifndef BASICWINDOW_H_INCLUDED
#define BASICWINDOW_H_INCLUDED

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

class BasicWindow
{
//Screen dimension constants
static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;

public:
    static void initWindow();
};

#endif // BASICWINDOW_H_INCLUDED
