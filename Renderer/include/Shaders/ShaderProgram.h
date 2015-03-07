#ifndef SHADERPROGRAM_H_INCLUDED
#define SHADERPROGRAM_H_INCLUDED

#include <iostream>
#include <OpenglHeaders.h>
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

		//Program ID
		GLuint mProgramID;
};

#endif // SHADERPROGRAM_H_INCLUDED
