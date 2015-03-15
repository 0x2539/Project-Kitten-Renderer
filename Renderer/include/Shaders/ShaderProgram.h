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
	ShaderProgram();
    /*
    Pre Condition:
     -None
    Post Condition:
     -Initializes variables
    Side Effects:
     -None
    */

    virtual ~ShaderProgram();
    /*
    Pre Condition:
     -None
    Post Condition:
     -Frees shader program
    Side Effects:
     -None
    */

	virtual bool loadProgram() = 0;
    /*
    Pre Condition:
     -A valid OpenGL context
    Post Condition:
     -Loads shader program
    Side Effects:
     -None
    */

	virtual void freeProgram();
    /*
    Pre Condition:
     -None
    Post Condition:
     -Frees shader program if it exists
    Side Effects:
     -None
    */

	bool bind();
    /*
    Pre Condition:
     -A loaded shader program
    Post Condition:
     -Sets this program as the current shader program
     -Reports to console if there was an error
    Side Effects:
     -None
    */

	void unbind();
    /*
    Pre Condition:
     -None
    Post Condition:
     -Sets default shader program as current program
    Side Effects:
     -None
    */

	GLuint getProgramID();
    /*
    Pre Condition:
     -None
    Post Condition:
     -Returns program ID
    Side Effects:
     -None
    */

protected:
	void printProgramLog( GLuint program );
    /*
    Pre Condition:
     -None
    Post Condition:
     -Prints program log
     -Reports error is GLuint ID is not a shader program
    Side Effects:
     -None
    */

	void printShaderLog( GLuint shader );
    /*
    Pre Condition:
     -None
    Post Condition:
     -Prints shader log
     -Reports error is GLuint ID is not a shader
    Side Effects:
     -None
    */

	GLuint loadShaderFromFile( std::string path, GLenum shaderType );


    //load uniform from shader
    GLint loadUniform( std::string uniformName );

    //load attribute from shader
    GLint loadAttrib( std::string attribName );

	//Program ID
	GLuint mProgramID;
};




/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

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
//        printf( "Error binding shader! %s\n", gluErrorString( error ) );
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
//			printf( "%s\n", infoLog );
		}

		//Deallocate string
		delete[] infoLog;
	}
	else
	{
	    cout << "Name " << program << " is not a program\n";
//		printf( "Name %d is not a program\n", program );
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
//			printf( "%s\n", infoLog );
		}

		//Deallocate string
		delete[] infoLog;
	}
	else
	{
	    cout << "Name " << shader << " is not a shader\n";
//		printf( "Name %d is not a shader\n", shader );
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
