#ifndef GLUTILS_H_INCLUDED
#define GLUTILS_H_INCLUDED

#include "BasicWindow.h"
#include "Shaders/BasicTexturedPolygonShader.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <SOIL.h>
#include "Logger.h"

class GLUtils
{
private:

    static bool initGL(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    static bool loadGP();
    static bool loadMedia();
    static int _SCREEN_WIDTH, _SCREEN_HEIGHT;

public:
    static bool initGraphics(int SCREEN_WIDTH, int SCREEN_HEIGHT);
};

int GLUtils::_SCREEN_WIDTH;
int GLUtils::_SCREEN_HEIGHT;

bool GLUtils::initGraphics(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    if( BasicWindow::initWindow(SCREEN_WIDTH, SCREEN_HEIGHT) )
    {
        _SCREEN_WIDTH = SCREEN_WIDTH;
        _SCREEN_HEIGHT = SCREEN_HEIGHT;
        initGL(SCREEN_WIDTH, SCREEN_HEIGHT);
        loadGP();
        loadMedia();

        return true;
    }
    return false;
}

bool GLUtils::initGL(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    //Initialize GLEW
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK )
    {
        Logger::write("Error initializing GLEW!\n");
        Logger::write(gluErrorString( glewError ));
        return false;
    }

    //Make sure OpenGL 2.1 is supported
    if( !GLEW_VERSION_2_1 )
    {
        Logger::write("OpenGL 2.1 not supported!\n");
        return false;
    }

    //Set the viewport
    glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Enable texturing
    glEnable( GL_TEXTURE_2D );

    //Set blending
    glEnable( GL_BLEND );
    glDisable( GL_DEPTH_TEST );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        Logger::write("Error initializing OpenGL!\n");
        Logger::write(gluErrorString( error ));
        return false;
    }

    //Initialize DevIL and DevILU
//    ilInit();
//    iluInit();
//    ilClearColour( 255, 255, 255, 000 );
//
//    //Check for error
//    ILenum ilError = ilGetError();
//    if( ilError != IL_NO_ERROR )
//    {
//        printf( "Error initializing DevIL! %s\n", iluErrorString( ilError ) );
//        return false;
//    }

    return true;
}

bool GLUtils::loadGP()
{
    BasicTexturedPolygonShader *basicTexturedPolygonShader = BasicTexturedPolygonShader::getInstance();

	//Load basic shader program
	if( !basicTexturedPolygonShader->loadProgram() )
	{
	    Logger::write("Unable to load basic shader!\n");
		return false;
	}

	//Bind basic shader program
	basicTexturedPolygonShader->bind();

    ColorRGBA color(1.0, 1.0, 1.0, 1.0);

    basicTexturedPolygonShader->setTextureColor( color );

    //Initialize projection
    basicTexturedPolygonShader->setProjection( glm::ortho<GLfloat>( 0.0, BasicWindow::SCREEN_WIDTH, BasicWindow::SCREEN_HEIGHT, 0.0, 1.0, -1.0 ) );
    basicTexturedPolygonShader->updateProjection();

    //Initialize modelview
    basicTexturedPolygonShader->setModelView( glm::mat4() );
    basicTexturedPolygonShader->updateModelView();

    //Set texture unit
    basicTexturedPolygonShader->setTextureUnit( 0 );

    return true;
}

bool GLUtils::loadMedia()
{
    return true;
}

#endif // GLUTILS_H_INCLUDED
