#ifndef SHADERUTILS_H_INCLUDED
#define SHADERUTILS_H_INCLUDED

#include "Shaders/ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ColorRGBA
{
public:
    GLfloat r, g, b, a;
};

class ShaderUtils : public ShaderProgram
{
private:

    //Attribute locations
    GLint mVertexPos2DLocation;
    GLint mTexCoordLocation;

    //Coloring location
    GLint mTextureColorLocation;

    //Texture unit location
    GLint mTextureUnitLocation;

    //Projection matrix
    glm::mat4 mProjectionMatrix;
    GLint mProjectionMatrixLocation;

    //Modelview matrix
    glm::mat4 mModelViewMatrix;
    GLint mModelViewMatrixLocation;


    void loadUniforms();

public:
    ShaderUtils();
    bool loadProgram();
    GLint loadUniform(std::string uniformName);
    GLint loadAttrib(std::string attribName);

        void setProjection( glm::mat4 matrix );
        /*
        Pre Condition:
         -None
        Post Condition:
         -Sets member projection matrix
        Side Effects:
         -None
        */

        void setModelView( glm::mat4 matrix );
        /*
        Pre Condition:
         -None
        Post Condition:
         -Sets member modelview matrix
        Side Effects:
         -None
        */

        void leftMultProjection( glm::mat4 matrix );
        /*
        Pre Condition:
         -None
        Post Condition:
         -Left multiplies member projection matrix
        Side Effects:
         -None
        */

        void leftMultModelView( glm::mat4 matrix );
        /*
        Pre Condition:
         -None
        Post Condition:
         -Left multiplies member modelview matrix
        Side Effects:
         -None
        */

        void updateProjection();
        /*
        Pre Condition:
         -Bound LPlainPolygonProgram2D
        Post Condition:
         -Updates shader program projection matrix with member projection matrix
        Side Effects:
         -None
        */

        void updateModelView();
        /*
        Pre Condition:
         -Bound LPlainPolygonProgram2D
        Post Condition:
         -Updates shader program modelview matrix with member modelview matrix
        Side Effects:
         -None
        */

        void setVertexPointer( GLsizei stride, const GLvoid* data );
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Sets vertex position attribute pointer
        Side Effects:
         -None
        */

        void setTexCoordPointer( GLsizei stride, const GLvoid* data );
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Sets texture coordinate attribute pointer
        Side Effects:
         -None
        */

        void enableVertexPointer();
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Enables vertex position attribute
        Side Effects:
         -None
        */

        void disableVertexPointer();
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Disables vertex position attribute
        Side Effects:
         -None
        */

        void enableTexCoordPointer();
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Enables texture coordinate attribute
        Side Effects:
         -None
        */

        void disableTexCoordPointer();
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Enables texture coordinate attribute
        Side Effects:
         -None
        */

        void setTextureColor( ColorRGBA color );
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Updates shader program textured polygon color
        Side Effects:
         -None
        */

        void setTextureUnit( GLuint unit );
        /*
        Pre Condition:
         -Bound LTexturedPolygonProgram2D
        Post Condition:
         -Updates shader program multitexture unit
        Side Effects:
         -None
        */
};


/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redestributed without written permission.*/
//Version: 002


ShaderUtils::ShaderUtils()
{
    mVertexPos2DLocation = 0;
    mTexCoordLocation = 0;

    mProjectionMatrixLocation = 0;
    mModelViewMatrixLocation = 0;
    mTextureColorLocation = 0;
    mTextureUnitLocation = 0;
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

    loadUniforms();

	//Clean up excess shader references
    glDeleteShader( vertexShader );
    glDeleteShader( fragmentShader );

	return true;
}

void ShaderUtils::loadUniforms()
{
    mVertexPos2DLocation = loadAttrib("VertexPos2D");
    mTexCoordLocation = loadAttrib("TexCoord");

    mTextureColorLocation = loadUniform("TextureColor");
    mTextureUnitLocation = loadUniform("TextureUnit");

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

void ShaderUtils::setVertexPointer( GLsizei stride, const GLvoid* data )
{
    glVertexAttribPointer( mVertexPos2DLocation, 2, GL_FLOAT, GL_FALSE, stride, data );
}

void ShaderUtils::setTexCoordPointer( GLsizei stride, const GLvoid* data )
{
    glVertexAttribPointer( mTexCoordLocation, 2, GL_FLOAT, GL_FALSE, stride, data );
}

void ShaderUtils::enableVertexPointer()
{
    glEnableVertexAttribArray( mVertexPos2DLocation );
}

void ShaderUtils::disableVertexPointer()
{
    glDisableVertexAttribArray( mVertexPos2DLocation );
}

void ShaderUtils::enableTexCoordPointer()
{
    glEnableVertexAttribArray( mTexCoordLocation );
}

void ShaderUtils::disableTexCoordPointer()
{
    glDisableVertexAttribArray( mTexCoordLocation );
}

void ShaderUtils::setTextureColor( ColorRGBA color )
{
    glUniform4f( mTextureColorLocation, color.r, color.g, color.b, color.a );
}

void ShaderUtils::setTextureUnit( GLuint unit )
{
    glUniform1i( mTextureUnitLocation, unit );
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

GLint ShaderUtils::loadAttrib(std::string attribName)
{
    GLint attrib = glGetAttribLocation( mProgramID, attribName.c_str() );
    if( attrib == -1 )
    {
        cout << attribName << " is not a valid glsl program variable!\n";
        //printf( "%s is not a valid glsl program variable!\n", "LTexCoord" );
    }
    return attrib;
}

#endif // SHADERUTILS_H_INCLUDED
