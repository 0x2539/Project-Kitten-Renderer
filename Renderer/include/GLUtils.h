#ifndef GLUTILS_H_INCLUDED
#define GLUTILS_H_INCLUDED

#include <iostream>
#define GLEW_STATIC
#include <glew.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class GLUtils
{
public:
    static bool initGL(int SCREEN_WIDTH, int SCREEN_HEIGHT);
};


#endif // GLUTILS_H_INCLUDED
