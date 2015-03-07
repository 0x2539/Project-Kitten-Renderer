#ifndef SHADERUTILS_H_INCLUDED
#define SHADERUTILS_H_INCLUDED

#include "Shaders/ShaderProgram.h"
#include <glm/glm.hpp>

class ShaderUtils : public ShaderProgram
{
private:
    //Color uniform location
    GLint mPolygonColorLocation;

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
};


#endif // SHADERUTILS_H_INCLUDED
