#ifndef GLUTILS_H_INCLUDED
#define GLUTILS_H_INCLUDED

#include "BasicWindow.h"
#include "Shaders/ShaderUtils.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <SOIL.h>
#include "Logger.h"

extern ShaderUtils shaderUtils;

class GLUtils
{
private:

    static bool initGL(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    static bool loadGP();
    static bool loadMedia();
    static int _SCREEN_WIDTH, _SCREEN_HEIGHT;

public:
    static bool initGraphics(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    static GLuint loadTexture(string path);
    static GLuint texture;
};

ShaderUtils shaderUtils;
int GLUtils::_SCREEN_WIDTH;
int GLUtils::_SCREEN_HEIGHT;
GLuint GLUtils::texture;


bool GLUtils::initGraphics(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    if( BasicWindow::initWindow() )
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
    glClearColor( 0.f, 0.f, 1.f, 1.f );

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
	//Load basic shader program
	if( !shaderUtils.loadProgram() )
	{
	    Logger::write("Unable to load basic shader!\n");
		return false;
	}

	//Bind basic shader program
	shaderUtils.bind();

    ColorRGBA color;
    color.r = 1.0;
    color.g = 1.0;
    color.b = 1.0;
    color.a = 1.0;

    shaderUtils.setTextureColor( color );

    //Initialize projection
    shaderUtils.setProjection( glm::ortho<GLfloat>( 0.0, BasicWindow::SCREEN_WIDTH, BasicWindow::SCREEN_HEIGHT, 0.0, 1.0, -1.0 ) );
    shaderUtils.updateProjection();

    //Initialize modelview
    shaderUtils.setModelView( glm::mat4() );
    shaderUtils.updateModelView();

    //Set texture unit
    shaderUtils.setTextureUnit( 0 );

    return true;
}

bool GLUtils::loadMedia()
{
    return true;
}
/*
GLuint GLUtils::loadTexture(string path)
{
    // load an image file directly as a new OpenGL texture 
    GLuint tex_2d = SOIL_load_OGL_texture
        (
            path.c_str(),
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
        );
 
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, DEFAULT_TEXTURE_WRAP );
    //glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, DEFAULT_TEXTURE_WRAP );

    // check for an error during the load process 
    if( 0 == tex_2d )
    {
        cout << "SOIL loading " << path <<" error: " << SOIL_last_result() << '\n';
        // printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
    }
    else
    {
        texture = tex_2d;
        cout << "SOIL loaded " << path <<'\n';
    }
    return tex_2d;
}
*/

#endif // GLUTILS_H_INCLUDED
