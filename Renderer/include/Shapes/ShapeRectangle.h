#ifndef SHAPERECTANGLE_H
#define SHAPERECTANGLE_H

#include "Shapes/Shapes.h"
#include "Shapes/GLTexturedVertex.h"

class ShapeRectangle : public Shape{
  private:
    Point _location;
    float _width;
    float _height;

    GLTexturedVertex vertices[ 4 ];
    //GLVertexCoord quadVertices[ 4 ];
    GLuint indices[ 4 ];
    GLuint gVBO = NULL;
    GLuint gIBO = NULL;

    BasicTexturedPolygonShader *basicTexturedPolygonShader;

    void setGraphicBuffers();

  public:
    ShapeRectangle();
    ShapeRectangle(Point location, float width, float height);
    void drawBorder(float lineWidth);
    void draw();

    void setLocation(Point location);
    void setLocation(float xCoordinate, float yCoordinate);
    Point getLocation();

    void setLocationX(float xCoordinate);
    float getLocationX();

    void setLocationY(float yCoordinate);
    float getLocationY();

    void setSize(float width, float height);

    void setWidth(float width);
    float getWidth();
    
    void setHeight(float height);
    float getHeight();
};


ShapeRectangle::ShapeRectangle(){
	setLocation(0, 0);
    setSize(0, 0);
}

ShapeRectangle::ShapeRectangle(Point location, float width, float height){

    basicTexturedPolygonShader = BasicTexturedPolygonShader::getInstance();

    setLocation(location);
    setSize(width, height);

    setGraphicBuffers();
}
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

void ShapeRectangle::draw(){
    setColor(0.5f, 1.f, 0.5f, 1.0f);

    basicTexturedPolygonShader->setModelView( glm::translate<GLfloat>( glm::vec3( getLocationX(), getLocationY(), 0.f ) ) );
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


void ShapeRectangle::setLocation(Point location)
{
	_location = location;
}

void ShapeRectangle::setLocation(float xCoordinate, float yCoordinate)
{
	setLocationX(xCoordinate);
	setLocationY(yCoordinate);
}

Point ShapeRectangle::getLocation()
{
	return _location;
}

void ShapeRectangle::setLocationX(float xCoordinate)
{
	getLocation().setX(xCoordinate);
}

float ShapeRectangle::getLocationX()
{
	return getLocation().getX();
}

void ShapeRectangle::setLocationY(float yCoordinate)
{
	getLocation().setY(yCoordinate);
}

float ShapeRectangle::getLocationY()
{
	return getLocation().getY();
}

void ShapeRectangle::setSize(float width, float height)
{
	setWidth(width);
	setHeight(height);
}

void ShapeRectangle::setWidth(float width)
{
	_width = width;
}

float ShapeRectangle::getWidth()
{
	return _width;
}

void ShapeRectangle::setHeight(float height)
{
	_height = height;
}

float ShapeRectangle::getHeight()
{
	return _height;
}

#endif // SHAPERECTANGLE_H
