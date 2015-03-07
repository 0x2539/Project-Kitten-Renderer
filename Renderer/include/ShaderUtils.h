#ifndef SHADERUTILS_H_INCLUDED
#define SHADERUTILS_H_INCLUDED

#include "ShaderProgram.h"

class ShaderUtils : public ShaderProgram
{
public:
    bool loadProgram();
    GLint loadUniform(std::string uniformName);
};


#endif // SHADERUTILS_H_INCLUDED
