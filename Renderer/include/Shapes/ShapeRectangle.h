/**
    ShapeRectangle.h
    Purpose: Implements a basic rectangle.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef SHAPERECTANGLE_H
#define SHAPERECTANGLE_H

#include "Shapes/Shapes.h"
#include "Shapes/GLTexturedVertex.h"
#include "TransformAnimations/ScaleAnimation.h"
#include "vector"
#include "Utils/Utils.h"
#include "Logger.h"
#include "Camera.h"
#include "BasicWindow.h"

using namespace std;

class ShapeRectangle : public Shape{
  private:
    //The location
    Point *_location;
    //The initial width
    float *_initialWidth;
    //The initial height
    float *_initialHeight;
    //The width
    float *_width;
    //The height
    float *_height;

    //The vertices of the rectangle
    GLTexturedVertex vertices[ 4 ];
    //GLVertexCoord quadVertices[ 4 ];
    //The indices order
    GLuint indices[ 4 ];
    //The vertex buffer object
    GLuint gVBO = NULL;
    //The index buffer object
    GLuint gIBO = NULL;

    //The shader program
    BasicTexturedPolygonShader *basicTexturedPolygonShader;

    //The animation vector
    vector<BasicTransformAnimation*> animations;

    /**
        Set the data for each vertex, initializes
        the buffer objects and binds data to it.

        @param
        @return
    */
    void setGraphicBuffers();

    /**
        Updates the rectangle based on each animation.

        @param
        @return
    */
    void updateAnimations();

    /**
        Updates the vertices data.

        @param
        @return
    */
    void updateVertices();

  public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
    ShapeRectangle();

    /**
        Initialise a new instance of this class.

        @param location the location where to
        render to rectangle
        @param width the width of the rectangle
        @param height the height of the rectangle
        @param Texture the texture to bind to the
        rectangle
        @return
    */
    ShapeRectangle(Point* location, float width, float height, GLuint Texture = 0);

    /**
        Initialise a new instance of this class.

        @param location the location where to
        render to rectangle
        @param width the width of the rectangle
        @param height the height of the rectangle
        @param Texture the texture to bind to the
        rectangle
        @return
    */
    ShapeRectangle(Point* location, float *width, float *height, GLuint Texture = 0);

    /**
        Draw a border around the rectangle

        @param lineWidth the width of the border
        @return
    */
    void drawBorder(float lineWidth);

    /**
        Draw the rectangle.

        @param
        @return
    */
    void draw();

    /**
        Update the rectangle's animations and
        other stuff.

        @param
        @return
    */
    void update();

    /**
        Set a new location for the rectangle.

        @param location the point from which the rectangle
        will get the location
        @return
    */
    void setLocation(Point* location);

    /**
        Set a new location for the rectangle.

        @param xCoordinate the x coordinate
        @param yCoordinate the y coordinate
        @return
    */
    void setLocation(float xCoordinate, float yCoordinate);

    /**
        Get the rectangle location.

        @param
        @return the location of the rectangle
    */
    Point* getLocation();

    /**
        Set the rectangle's x coordinate.

        @param xCoordinate the rectangle's x coordinate
        @return
    */
    void setLocationX(float xCoordinate);

    /**
        Get the rectangle's x coordinate.

        @param
        @return the rectangle's x coordinate
    */
    float getLocationX();

    /**
        Set the rectangle's y coordinate.

        @param yCoordinate the rectangle's y coordinate
        @return
    */
    void setLocationY(float yCoordinate);

    /**
        Get the rectangle's y coordinate.

        @param
        @return the rectangle's y coordinate
    */
    float getLocationY();

    /**
        Set the size of the rectangle.

        @param width the width of the rectangle
        @param height the height of the rectangle
        @return
    */
    void setSize(float width, float height);

    /**
        Set the width of the rectangle.

        @param width the width of the rectangle
        @return
    */
    void setWidth(float width);

    /**
        Get the width of the rectangle.

        @param
        @return the width of the rectangle
    */
    float getWidth();
    
    /**
        Set the height of the rectangle.

        @param height the height of the rectangle
        @return
    */
    void setHeight(float height);

    /**
        Get the height of the rectangle.

        @param
        @return the height of the rectangle
    */
    float getHeight();

    /**
        Add a new animation and start it immediately.

        @param animation the animation to add and start
        @return
    */
    void addAndStartAnimation(BasicTransformAnimation *animation);

    /**
        Set what part of the sprite to draw.

        @param texLeft the left coordinate
        @param texTop the top coordinate
        @param texRight the right coordinate
        @param texBottom the bottom coordinate
        @return
    */
    void setTextCoord(GLfloat texLeft, GLfloat texTop, GLfloat texRight, GLfloat texBottom);

    /**
        Allocates dynamic memory.

        @param
        @return
    */
    void allocateDynamicMemory();
};

void ShapeRectangle::allocateDynamicMemory()
{
    _initialWidth = new float;
    _initialHeight = new float;
    _width = new float;
    _height = new float;
}


ShapeRectangle::ShapeRectangle(){
    allocateDynamicMemory();

	setLocation(0, 0);
    setSize(0, 0);
}

ShapeRectangle::ShapeRectangle(Point *location, float width, float height, GLuint Texture){

    basicTexturedPolygonShader = BasicTexturedPolygonShader::getInstance();

    allocateDynamicMemory();

    setLocation(location);
    setSize(width, height);
    setTexture(Texture);

    setGraphicBuffers();
}

// TESTING
ShapeRectangle::ShapeRectangle(Point *location, float *width, float *height, GLuint Texture){

    basicTexturedPolygonShader = BasicTexturedPolygonShader::getInstance();

    allocateDynamicMemory();

    setLocation(location);
    _width = width;
    _height = height;
    *_initialHeight = *height;
    *_initialWidth = *width;
    //setSize(width, height);
    //setTexture(Texture);

    setGraphicBuffers();
}
// END TESTING

void ShapeRectangle::setGraphicBuffers()
{
    GLfloat texLeft = 0;
    GLfloat texTop = 0;
    GLfloat texRight = 1;
    GLfloat texBottom = 1;

    vertices[ 0 ].setVertexCoord( GLVertexCoord( 0, 0 ) );
    vertices[ 1 ].setVertexCoord( GLVertexCoord( getWidth(), 0 ) );
    vertices[ 2 ].setVertexCoord( GLVertexCoord( getWidth(), getHeight() ) );
    vertices[ 3 ].setVertexCoord( GLVertexCoord( 0, getHeight() ) );

    vertices[ 0 ].setTextureCoord( GLTexCoord( texLeft, texTop ) );
    vertices[ 1 ].setTextureCoord( GLTexCoord( texRight, texTop ) );
    vertices[ 2 ].setTextureCoord( GLTexCoord( texRight, texBottom ) );
    vertices[ 3 ].setTextureCoord( GLTexCoord( texLeft, texBottom ) );

    //Set rendering indices
    indices[ 0 ] = 0;
    indices[ 1 ] = 1;
    indices[ 2 ] = 2;
    indices[ 3 ] = 3;

    //glBindTexture( GL_TEXTURE_2D, GLUtils::texture );
    //Create VBO
    glGenBuffers( 1, &gVBO );
    glBindBuffer( GL_ARRAY_BUFFER, gVBO );
    glBufferData( GL_ARRAY_BUFFER, 4 * sizeof(GLTexturedVertex), vertices, GL_DYNAMIC_DRAW );

    //Create IBO
    glGenBuffers( 1, &gIBO );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indices, GL_DYNAMIC_DRAW );

    //Unbind buffers
    glBindBuffer( GL_ARRAY_BUFFER, NULL );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, NULL );
}

void ShapeRectangle::updateVertices()
{
    vertices[ 0 ].setVertexCoord( GLVertexCoord( 0, 0 ) );
    vertices[ 1 ].setVertexCoord( GLVertexCoord( getWidth(), 0 ) );
    vertices[ 2 ].setVertexCoord( GLVertexCoord( getWidth(), getHeight() ) );
    vertices[ 3 ].setVertexCoord( GLVertexCoord( 0, getHeight() ) );   
}

void ShapeRectangle::setTextCoord(GLfloat texLeft, GLfloat texTop, GLfloat texRight, GLfloat texBottom){
    vertices[ 0 ].setTextureCoord( GLTexCoord( texLeft, texTop ) );
    vertices[ 1 ].setTextureCoord( GLTexCoord( texRight, texTop ) );
    vertices[ 2 ].setTextureCoord( GLTexCoord( texRight, texBottom ) );
    vertices[ 3 ].setTextureCoord( GLTexCoord( texLeft, texBottom ) );
}

void ShapeRectangle::draw(){

    // if it's not currently on the screen (actually camera doesn't see it), don't draw it
    if(! Camera::isVisible(this -> getLocationX(), this -> getLocationY(), this -> getWidth(), this -> getHeight()))
        return ;

    setColor(0.5f, 1.f, 0.5f, 1.0f);

    basicTexturedPolygonShader->setModelView( glm::translate<GLfloat>( 
                                        glm::vec3( this -> getLocationX() - Camera::getX(), 
                                                   this -> getLocationY() - Camera::getY(), 0.f ) ) );
    basicTexturedPolygonShader->updateModelView();

    //Set texture ID
    glBindTexture( GL_TEXTURE_2D, texture );

    basicTexturedPolygonShader->enableVertexPointer();
    basicTexturedPolygonShader->enableTexCoordPointer();
    //Enable vertex arrays
    //glEnableClientState( GL_VERTEX_ARRAY );

        //Set vertex data
        glBindBuffer( GL_ARRAY_BUFFER, gVBO );
            //Update vertex buffer data
            glBufferSubData( GL_ARRAY_BUFFER, 0, 4 * sizeof(GLTexturedVertex), vertices );

            //Set texture coordinate data
            basicTexturedPolygonShader->setTexCoordPointer( sizeof(GLTexturedVertex), (GLvoid*)offsetof( GLTexturedVertex, _textureCoord ) );

            //Set vertex data
            basicTexturedPolygonShader->setVertexPointer( sizeof(GLTexturedVertex), (GLvoid*)offsetof( GLTexturedVertex, _vertexCoord ) );


        //Draw quad using vertex data and index data
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
        glDrawElements( GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL );

    //Disable vertex arrays
    //glDisableClientState( GL_VERTEX_ARRAY );
    //Disable vertex and texture coordinate arrays
    basicTexturedPolygonShader->disableVertexPointer();
    basicTexturedPolygonShader->disableTexCoordPointer();
}

void ShapeRectangle::update()
{
    updateAnimations();
}

void ShapeRectangle::drawBorder(float lineWidth){

    glLineWidth(lineWidth);
    glBegin(GL_LINE_STRIP);
        glVertex2f(getLocationX(), getLocationY());
        glVertex2f(getLocationX(), getLocationY() + getHeight());
        glVertex2f(getLocationX() + getWidth(), getLocationY() + getHeight());
        glVertex2f(getLocationX() + getWidth(), getLocationY());
        glVertex2f(getLocationX(), getLocationY());
    glEnd();
}


void ShapeRectangle::setLocation(Point *location)
{
	_location = location;
}

void ShapeRectangle::setLocation(float xCoordinate, float yCoordinate)
{
	setLocationX(xCoordinate);
	setLocationY(yCoordinate);
}

Point* ShapeRectangle::getLocation()
{
	return _location;
}

void ShapeRectangle::setLocationX(float xCoordinate)
{
	getLocation() -> setX(xCoordinate);
}

float ShapeRectangle::getLocationX()
{
	return getLocation() -> getX();
}

void ShapeRectangle::setLocationY(float yCoordinate)
{
	getLocation() -> setY(yCoordinate);
}

float ShapeRectangle::getLocationY()
{
	return getLocation() -> getY();
}

void ShapeRectangle::setSize(float width, float height)
{
	setWidth(width);
	setHeight(height);
}

void ShapeRectangle::setWidth(float width)
{
	*_width = width;
    *_initialWidth = width;
}

float ShapeRectangle::getWidth()
{
	return *_width;
}

void ShapeRectangle::setHeight(float height)
{
    *_initialHeight = height;
	*_height = height;
}

float ShapeRectangle::getHeight()
{
	return *_height;
}

void ShapeRectangle::addAndStartAnimation(BasicTransformAnimation *animation)
{
    animations.push_back(animation);
}

void ShapeRectangle::updateAnimations()
{
    vector<BasicTransformAnimation*>::iterator it;

    for ( it = animations.begin(); it != animations.end(); )
    {
        (*it)->update();
        *_width = ((ScaleAnimation*)(*it))->getScaleX() * (*_initialWidth);
        *_height = ((ScaleAnimation*)(*it))->getScaleY() * (*_initialHeight);
        // setGraphicBuffers();
        updateVertices();
        Logger::write(toString(getWidth()));

        if( (*it)->isFinished())
        {
            delete * it;  
            it = animations.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}


#endif // SHAPERECTANGLE_H
