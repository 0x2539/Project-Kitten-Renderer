/**
    BasicTexturedPolygonShader.h
    Purpose: Loads, compiles and operates on basic shaders 
    written in GLSL. It should only be used when you want 
    to create a textured polygon. This class follows the 
    singleton design pattern.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef BASICTEXTUREDPOLYGONSHADER_H_INCLUDED
#define BASICTEXTUREDPOLYGONSHADER_H_INCLUDED

#include "Shaders/ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ColorRGBA.h"

class BasicTexturedPolygonShader : public ShaderProgram
{
private:

    BasicTexturedPolygonShader();
    static BasicTexturedPolygonShader *_instance;

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

	/**
	    Instead of creating a new object, use this method to 
	    get a pointer to an object that will be persistent 
	    through out the program.

	    @param
	    @return the only instance of this class
	*/
    static BasicTexturedPolygonShader* getInstance();

	/**
	    Load the shader files to memory and compile them.
	    If no error occured during the loading and compilation,
	    then link the shaders to our program.

	    @param
	    @return true if no error occured during the loading
	    and compilation, false otherwise
	*/
    bool loadProgram();

	/**
	    Set the value of the projection matrix to pass to
	    the shader program.

	    @param matrix the matrix that will be passed to 
	    the shader program
	    @return
	*/
    void setProjection( glm::mat4 matrix );

	/**
	    Set the value of the model view matrix to pass to
	    the shader program.

	    @param matrix the matrix that will be passed to 
	    the shader program
	    @return
	*/
    void setModelView( glm::mat4 matrix );

	/**
	    Multiplies the projection matrix.

	    @param matrix the projection matrix to be
	    multiplied
	    @return
	*/
    void leftMultProjection( glm::mat4 matrix );

	/**
	    Multiplies the model view matrix.

	    @param matrix the model view matrix to be
	    multiplied
	    @return
	*/
    void leftMultModelView( glm::mat4 matrix );

	/**
	    Updates shader program projection matrix 
	    with member projection matrix.

	    @param
	    @return
	*/
    void updateProjection();

	/**
	    Updates shader program modelview matrix 
	    with member modelview matrix.

	    @param
	    @return
	*/
    void updateModelView();

	/**
	    Sets vertex position attribute pointer.

	    @param stride the stride of the position
	    vertex
	    @param data the data inside the position
	    vertex
	    @return
	*/
    void setVertexPointer( GLsizei stride, const GLvoid* data );

	/**
	    Sets texture coordinate attribute pointer.

	    @param stride the stride of the texture 
	    vertex
	    @param data the data inside the texture
	    vertex
	    @return
	*/
    void setTexCoordPointer( GLsizei stride, const GLvoid* data );

	/**
	    Enables vertex position attribute.

	    @param
	    @return
	*/
    void enableVertexPointer();

	/**
	    Disables vertex position attribute.

	    @param
	    @return
	*/
    void disableVertexPointer();

	/**
	    Enables texture coordinate attribute.

	    @param
	    @return
	*/
    void enableTexCoordPointer();

	/**
	    Disables texture coordinate attribute.

	    @param
	    @return
	*/
    void disableTexCoordPointer();

	/**
	    Updates shader program textured polygon color.

	    @param
	    @return
	*/
    void setTextureColor( ColorRGBA color );

	/**
	    Updates shader program multitexture unit.

	    @param unit the new value for the texture unit.
	    @return
	*/
    void setTextureUnit( GLuint unit );
};

BasicTexturedPolygonShader* BasicTexturedPolygonShader::_instance;

BasicTexturedPolygonShader::BasicTexturedPolygonShader()
{
    mVertexPos2DLocation = 0;
    mTexCoordLocation = 0;

    mProjectionMatrixLocation = 0;
    mModelViewMatrixLocation = 0;
    mTextureColorLocation = 0;
    mTextureUnitLocation = 0;
}

BasicTexturedPolygonShader* BasicTexturedPolygonShader::getInstance()
{
    if(_instance == NULL) {
        _instance = new BasicTexturedPolygonShader();
    }
    return _instance;
}

bool BasicTexturedPolygonShader::loadProgram()
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

void BasicTexturedPolygonShader::loadUniforms()
{
    mVertexPos2DLocation = loadAttrib("VertexPos2D");
    mTexCoordLocation = loadAttrib("TexCoord");

    mTextureColorLocation = loadUniform("TextureColor");
    mTextureUnitLocation = loadUniform("TextureUnit");

    mProjectionMatrixLocation = loadUniform("ProjectionMatrix");
    mModelViewMatrixLocation = loadUniform("ModelViewMatrix");
}

void BasicTexturedPolygonShader::setProjection( glm::mat4 matrix )
{
    mProjectionMatrix = matrix;
}

void BasicTexturedPolygonShader::setModelView( glm::mat4 matrix )
{
    mModelViewMatrix = matrix;
}

void BasicTexturedPolygonShader::leftMultProjection( glm::mat4 matrix )
{
    mProjectionMatrix = matrix * mProjectionMatrix;
}

void BasicTexturedPolygonShader::leftMultModelView( glm::mat4 matrix )
{
    mModelViewMatrix = matrix * mModelViewMatrix;
}

void BasicTexturedPolygonShader::updateProjection()
{
    glUniformMatrix4fv( mProjectionMatrixLocation, 1, GL_FALSE, glm::value_ptr( mProjectionMatrix ) );
}

void BasicTexturedPolygonShader::updateModelView()
{
    glUniformMatrix4fv( mModelViewMatrixLocation, 1, GL_FALSE, glm::value_ptr( mModelViewMatrix ) );
}

void BasicTexturedPolygonShader::setVertexPointer( GLsizei stride, const GLvoid* data )
{
    glVertexAttribPointer( mVertexPos2DLocation, 2, GL_FLOAT, GL_FALSE, stride, data );
}

void BasicTexturedPolygonShader::setTexCoordPointer( GLsizei stride, const GLvoid* data )
{
    glVertexAttribPointer( mTexCoordLocation, 2, GL_FLOAT, GL_FALSE, stride, data );
}

void BasicTexturedPolygonShader::enableVertexPointer()
{
    glEnableVertexAttribArray( mVertexPos2DLocation );
}

void BasicTexturedPolygonShader::disableVertexPointer()
{
    glDisableVertexAttribArray( mVertexPos2DLocation );
}

void BasicTexturedPolygonShader::enableTexCoordPointer()
{
    glEnableVertexAttribArray( mTexCoordLocation );
}

void BasicTexturedPolygonShader::disableTexCoordPointer()
{
    glDisableVertexAttribArray( mTexCoordLocation );
}

void BasicTexturedPolygonShader::setTextureColor( ColorRGBA color )
{
    glUniform4f( mTextureColorLocation, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha() );
}

void BasicTexturedPolygonShader::setTextureUnit( GLuint unit )
{
    glUniform1i( mTextureUnitLocation, unit );
}


#endif // BASICTEXTUREDPOLYGONSHADER_H_INCLUDED
