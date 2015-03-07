#include "GLUtils.h"

bool GLUtils::initGL(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    //Initialize GLEW
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK )
    {
        cout << "Error initializing GLEW!\n" << glewGetErrorString( glewError );
//        printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
        return false;
    }

    //Make sure OpenGL 2.1 is supported
    if( !GLEW_VERSION_2_1 )
    {
        cout << "OpenGL 2.1 not supported!\n";
//        printf( "OpenGL 2.1 not supported!\n" );
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
        cout << "Error initializing OpenGL!\n" << gluErrorString( error );
//        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
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
