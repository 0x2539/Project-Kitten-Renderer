/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redestributed without written permission.*/
//Version: 002

#include "ShaderUtils.h"
#include <glm/gtc/type_ptr.hpp>

ShaderUtils::ShaderUtils()
{
    mPolygonColorLocation = 0;
    mProjectionMatrixLocation = 0;
    mModelViewMatrixLocation = 0;
}

bool ShaderUtils::loadProgram()
{
	//Generate program
	mProgramID = glCreateProgram();

	//Load vertex shader
	GLuint vertexShader = loadShaderFromFile( "shaders/basicPolygon.glvs", GL_VERTEX_SHADER );

    //Check for errors
    if( vertexShader == 0 )
    {
        glDeleteProgram( mProgramID );
        mProgramID = 0;
        return false;
    }

	//Attach vertex shader to program
	glAttachShader( mProgramID, vertexShader );


	//Create fragment shader
	GLuint fragmentShader = loadShaderFromFile( "shaders/basicPolygon.glfs", GL_FRAGMENT_SHADER );

    //Check for errors
    if( fragmentShader == 0 )
    {
        glDeleteShader( vertexShader );
        glDeleteProgram( mProgramID );
        mProgramID = 0;
        return false;
    }

	//Attach fragment shader to program
	glAttachShader( mProgramID, fragmentShader );

	//Link program
    glLinkProgram( mProgramID );

	//Check for errors
	GLint programSuccess = GL_TRUE;
	glGetProgramiv( mProgramID, GL_LINK_STATUS, &programSuccess );
	if( programSuccess != GL_TRUE )
    {
        cout << "Error linking program " << mProgramID << "!\n";
//		printf( "Error linking program %d!\n", mProgramID );
		printProgramLog( mProgramID );
        glDeleteShader( vertexShader );
        glDeleteShader( fragmentShader );
        glDeleteProgram( mProgramID );
        mProgramID = 0;
        return false;
    }

	//Clean up excess shader references
    glDeleteShader( vertexShader );
    glDeleteShader( fragmentShader );

    loadUniforms();

	return true;
}

void ShaderUtils::loadUniforms()
{
    mPolygonColorLocation = loadUniform("PolygonColor");
    mProjectionMatrixLocation = loadUniform("ProjectionMatrix");
    mModelViewMatrixLocation = loadUniform("ModelViewMatrix");
}

void ShaderUtils::setProjection( glm::mat4 matrix )
{
    mProjectionMatrix = matrix;
}

void ShaderUtils::setModelView( glm::mat4 matrix )
{
    mModelViewMatrix = matrix;
}

void ShaderUtils::leftMultProjection( glm::mat4 matrix )
{
    mProjectionMatrix = matrix * mProjectionMatrix;
}

void ShaderUtils::leftMultModelView( glm::mat4 matrix )
{
    mModelViewMatrix = matrix * mModelViewMatrix;
}

void ShaderUtils::updateProjection()
{
    glUniformMatrix4fv( mProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr( mProjectionMatrix ) );
}

void ShaderUtils::updateModelView()
{
    glUniformMatrix4fv( mModelViewMatrixLocation, 1, GL_FALSE, glm::value_ptr( mModelViewMatrix ) );
}

GLint ShaderUtils::loadUniform(std::string uniformName)
{
    //Get variable location
    GLint uniform = glGetUniformLocation( mProgramID, uniformName.c_str() );
    if( uniform == -1 )
    {
        cout << uniformName << " is not a valid glsl program variable!\n";
//        printf( "%s is not a valid glsl program variable!\n", "PolygonColor" );
    }
    return uniform;
}
