/**
    ShaderProgram.h
    Purpose: Offers basic shader loading and binding.
    It also contains basic methods to load uniforms
    and attributes from the shader programs. Every
    new created shape should inherit this class as it
    contains the basics for every shader program.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef SHADERPROGRAM_H_INCLUDED
#define SHADERPROGRAM_H_INCLUDED

#include <iostream>
#include <fstream>
#include "OpenglHeaders.h"
#include "Logger.h"
#ifdef _WIN32
#else
    #include <GL/freeglut.h>
#endif
using namespace std;

class ShaderProgram
{
public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
	ShaderProgram();

    /**
        Destroys an instance of this class. This
        is virtual because we don't want this class
        to have any instance.

        @param
        @return
    */
    virtual ~ShaderProgram();

    /**
        Load the shader files to memory and compile them.
        If no error occured during the loading and compilation,
        then link the shaders to our program.

        @param
        @return true if no error occured during the loading
        and compilation, false otherwise
    */
	virtual bool loadProgram() = 0;

    /**
        Free shader program if it exists.

        @param
        @return
    */
	virtual void freeProgram();

    /**
        Set this program as the current shader program.
        Reports to console if there was an error.

        @param
        @return true if no error occured during binding,
        false otherwise
    */
	bool bind();

    /**
        Set default shader program as current program.

        @param
        @return
    */
	void unbind();

    /**
        Get the id of the shader program.

        @param
        @return the program id
    */
	GLuint getProgramID();

protected:

    /**
        Print program log. Reports error is GLuint 
        ID is not a shader program.

        @param program the id of the shader program
        @return
    */
	void printProgramLog( GLuint program );

    /**
        Print shader log. Reports error is GLuint 
        ID is not a shader.

        @param shader the id of the shader
        @return
    */
	void printShaderLog( GLuint shader );

    /**
        Load a shader program from a file.

        @param path the path from where to load the shader
        @param shaderType the type of the shader
        @return the id of the shader
    */
	GLuint loadShaderFromFile( std::string path, GLenum shaderType );

    /**
        Loads a uniform from a loaded shader.

        @param uniformName the name of the uniform to load
        @return the id of the uniform
    */
    GLint loadUniform( std::string uniformName );

    /**
        Loads an attribute from a loaded shader.

        @param uniformName the name of the attribute to load
        @return the id of the attribute
    */
    GLint loadAttrib( std::string attribName );

	//Program ID
	GLuint mProgramID;
};

ShaderProgram::ShaderProgram()
{
    mProgramID = NULL;
}

ShaderProgram::~ShaderProgram()
{
    //Free program if it exists
    freeProgram();
}

void ShaderProgram::freeProgram()
{
    //Delete program
    glDeleteProgram( mProgramID );
}

bool ShaderProgram::bind()
{
	//Use shader
	glUseProgram( mProgramID );

	//Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        cout << "Error binding shader!\n" << gluErrorString( error );
		printProgramLog( mProgramID );
        return false;
    }

	return true;
}

void ShaderProgram::unbind()
{
    //Use default program
	glUseProgram( NULL );
}

GLuint ShaderProgram::getProgramID()
{
	return mProgramID;
}

void ShaderProgram::printProgramLog( GLuint program )
{
	//Make sure name is shader
	if( glIsProgram( program ) )
	{
		//Program log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		//Get info string length
		glGetProgramiv( program, GL_INFO_LOG_LENGTH, &maxLength );

		//Allocate string
		char* infoLog = new char[ maxLength ];

		//Get info log
		glGetProgramInfoLog( program, maxLength, &infoLogLength, infoLog );
		if( infoLogLength > 0 )
		{
			//Print Log
			cout << infoLog << '\n';
		}

		//Deallocate string
		delete[] infoLog;
	}
	else
	{
	    cout << "Name " << program << " is not a program\n";
	}
}

void ShaderProgram::printShaderLog( GLuint shader )
{
	//Make sure name is shader
	if( glIsShader( shader ) )
	{
		//Shader log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		//Get info string length
		glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &maxLength );

		//Allocate string
		char* infoLog = new char[ maxLength ];

		//Get info log
		glGetShaderInfoLog( shader, maxLength, &infoLogLength, infoLog );
		if( infoLogLength > 0 )
		{
			//Print Log
			cout << infoLog << '\n';
		}

		//Deallocate string
		delete[] infoLog;
	}
	else
	{
	    cout << "Name " << shader << " is not a shader\n";
	}
}

GLuint ShaderProgram::loadShaderFromFile( std::string path, GLenum shaderType )
{
	//Open file
	GLuint shaderID = 0;
	std::string shaderString;
	std::ifstream sourceFile( path.c_str() );

	//Source file loaded
	if( sourceFile )
	{
	    //Get shader source
		shaderString.assign( ( std::istreambuf_iterator< char >( sourceFile ) ), std::istreambuf_iterator< char >() );

		//Create shader ID
		shaderID = glCreateShader( shaderType );

        //Set shader source
        const GLchar* shaderSource = shaderString.c_str();
        glShaderSource( shaderID, 1, (const GLchar**)&shaderSource, NULL );

        //Compile shader source
        glCompileShader( shaderID );

        //Check shader for errors
        GLint shaderCompiled = GL_FALSE;
        glGetShaderiv( shaderID, GL_COMPILE_STATUS, &shaderCompiled );
        if( shaderCompiled != GL_TRUE )
        {
            printf( "Unable to compile shader %d!\n\nSource:\n%s\n", shaderID, shaderSource );
            printShaderLog( shaderID );
            glDeleteShader( shaderID );
            shaderID = 0;
        }
	}
    else
    {
        printf( "Unable to open file %s\n", path.c_str() );
    }

	return shaderID;
}

GLint ShaderProgram::loadUniform(std::string uniformName)
{
    //Get variable location
    GLint uniform = glGetUniformLocation( mProgramID, uniformName.c_str() );
    if( uniform == -1 )
    {
        Logger::write(uniformName + " is not a valid glsl program variable!");
    }
    return uniform;
}

GLint ShaderProgram::loadAttrib(std::string attribName)
{
    GLint attrib = glGetAttribLocation( mProgramID, attribName.c_str() );
    if( attrib == -1 )
    {
        Logger::write(attribName + " is not a valid glsl program variable!");
    }
    return attrib;
}
#endif // SHADERPROGRAM_H_INCLUDED
