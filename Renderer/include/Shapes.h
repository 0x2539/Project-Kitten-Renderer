#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "OpenglHeaders.h"

class Shape
{
    public:
        virtual void draw() = 0;
        GLuint texture;
        void setTexture( GLuint newTexture );
        void setColor( GLfloat r, GLfloat g, GLfloat b, GLfloat a );
};

class GLVertexCoord{
  private:
    float _x,_y;

  public:
    GLVertexCoord();
    GLVertexCoord(GLfloat x, GLfloat y);
    GLfloat getX();
    GLfloat getY();
    void setCoord(GLfloat x, GLfloat y);
    void setCoord(GLVertexCoord p);
};

class GLTexCoord{
private:
    GLfloat _s;
    GLfloat _t;
public:
    GLTexCoord();
    GLTexCoord(GLfloat s, GLfloat t);
    GLfloat getS();
    GLfloat getT();
    void setCoord(GLfloat s, GLfloat t);
    void setCoord(GLTexCoord p);
};

class GLTexturedVertex{
private:
public:
    GLVertexCoord _vertexCoord;
    GLTexCoord _textureCoord;
    GLTexturedVertex();
    GLTexturedVertex(GLVertexCoord vertexCoord, GLTexCoord textureCoord);
    void setVertexCoord(GLVertexCoord vertexCoord);
    void setTextureCoord(GLTexCoord textureCoord);
};

class Point : public Shape{
  private:
    float _x,_y;

  public:
    Point();
    Point(float x, float y);
    void draw();
    float getX();
    float getY();
    void setCoord(float x, float y);
    void setCoord(Point p);
};

class Line : public Shape{
  private:
      Point _p1, _p2;

  public:
    Line();
    Line(Point p1, Point p2);
    Line(float px1, float py1, float px2, float py2);
    void draw();
};

class Rectangle1 : public Shape{
  private:
    Point _leftTop;
    float _xSideLength;
    float _ySideLength;

    GLTexturedVertex vertices[ 4 ];
    //GLVertexCoord quadVertices[ 4 ];
    GLuint indices[ 4 ];
    GLuint gVBO = NULL;
    GLuint gIBO = NULL;


  public:
    Rectangle1();
    Rectangle1(Point leftTop, float xSideLength, float ySideLength);
    void drawBorder(float lineWidth);
    void draw();
};

class Square : public Shape{
  private:
    Point _leftTop;
    float _sideLength;

  public:
    Square();
    Square(Point leftTop, float sideLength);
    void drawBorder(float lineWidth);
    void draw();
};

void Shape::setTexture(GLuint newTexture){
    texture = newTexture;
}

GLVertexCoord::GLVertexCoord(){
    _x = 0.f;
    _y = 0.f;
}

GLVertexCoord::GLVertexCoord(GLfloat x, GLfloat y){
    _x = x;
    _y = y;
}

GLfloat GLVertexCoord::getX(){
    return _x;
}

GLfloat GLVertexCoord::getY(){
    return _y;
}

void GLVertexCoord::setCoord(GLfloat x, GLfloat y){
    _x = x;
    _y = y;
}
void GLVertexCoord::setCoord(GLVertexCoord p){
    setCoord(p.getX(), p.getY());
}

GLTexCoord::GLTexCoord(){
    _s = 0.f;
    _t = 0.f;
}

GLTexCoord::GLTexCoord(GLfloat s, GLfloat t){
    _s = s;
    _t = t;
}

GLfloat GLTexCoord::getS(){
    return _s;
}

GLfloat GLTexCoord::getT(){
    return _t;
}

void GLTexCoord::setCoord(GLfloat s, GLfloat t){
    _s = s;
    _t = t;
}
void GLTexCoord::setCoord(GLTexCoord p){
    setCoord(p.getS(), p.getT());
}

GLTexturedVertex::GLTexturedVertex()
{

}

GLTexturedVertex::GLTexturedVertex(GLVertexCoord vertexCoord, GLTexCoord textureCoord)
{
    _vertexCoord = vertexCoord;
    _textureCoord = textureCoord;
}

void GLTexturedVertex::setVertexCoord(GLVertexCoord vertexCoord)
{
    _vertexCoord = vertexCoord;
}

void GLTexturedVertex::setTextureCoord(GLTexCoord textureCoord)
{
    _textureCoord = textureCoord;
}

Point::Point(){
    _x = 0.f;
    _y = 0.f;
}

Point::Point(float x, float y){
    _x = x;
    _y = y;
}

float Point::getX(){
    return _x;
}

float Point::getY(){
    return _y;
}

void Point::setCoord(float x, float y){
    _x = x;
    _y = y;
}
void Point::setCoord(Point p){
    _x = p.getX();
    _y = p.getY();
}

void Point::draw(){
    glBegin(GL_POINTS);
        glVertex2f(_x, _y);
    glEnd();
}

Line::Line(){
    _p1.setCoord(0.f, 0.f);
    _p2.setCoord(0.f, 0.f);
}

Line::Line(float px1, float py1, float px2, float py2){
    _p1.setCoord(px1, py1);
    _p2.setCoord(px2, py2);
}

Line::Line(Point p1, Point p2){
    _p1.setCoord(p1);
    _p2.setCoord(p2);
}

void Line::draw(){
    glBegin(GL_LINES);
      glVertex2f(_p1.getX(), _p1.getY());
      glVertex2f(_p2.getX(), _p2.getY());
    glEnd();
}

Rectangle1::Rectangle1(){
    _leftTop.setCoord(0.0f, 0.0f);
    _xSideLength = 0.0f;
    _ySideLength = 0.0f;
}

Rectangle1::Rectangle1(Point leftTop, float xSideLength, float ySideLength){

    GLfloat texLeft = 0;
    GLfloat texTop = 0;
    GLfloat texRight = 1;
    GLfloat texBottom = 1;

    vertices[ 0 ].setVertexCoord( GLVertexCoord( 0, 0 ) );
    vertices[ 1 ].setVertexCoord( GLVertexCoord( xSideLength, 0 ) );
    vertices[ 2 ].setVertexCoord( GLVertexCoord( xSideLength, ySideLength ) );
    vertices[ 3 ].setVertexCoord( GLVertexCoord( 0, ySideLength ) );

    vertices[ 0 ].setTextureCoord( GLTexCoord( texLeft, texTop ) );
    vertices[ 1 ].setTextureCoord( GLTexCoord( texRight, texTop ) );
    vertices[ 2 ].setTextureCoord( GLTexCoord( texRight, texBottom ) );
    vertices[ 3 ].setTextureCoord( GLTexCoord( texLeft, texBottom ) );

    /*quadVertices[ 0 ].setCoord(leftTop.getX(), leftTop.getY());

    quadVertices[ 1 ].setCoord(leftTop.getX() + xSideLength, leftTop.getY());

    quadVertices[ 2 ].setCoord(leftTop.getX() + xSideLength, leftTop.getY() + ySideLength);

    quadVertices[ 3 ].setCoord(leftTop.getX(), leftTop.getY() + ySideLength);

        vData[ 0 ].texCoord.s =  texLeft; vData[ 0 ].texCoord.t =    texTop;
        vData[ 1 ].texCoord.s = texRight; vData[ 1 ].texCoord.t =    texTop;
        vData[ 2 ].texCoord.s = texRight; vData[ 2 ].texCoord.t = texBottom;
        vData[ 3 ].texCoord.s =  texLeft; vData[ 3 ].texCoord.t = texBottom;*/

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

    _leftTop.setCoord(leftTop);
    _xSideLength = xSideLength;
    _ySideLength = ySideLength;
}

void Rectangle1::draw(){
    setColor(0.5f, 1.f, 0.5f, 1.0f);

    //glLoadIdentity();

    shaderUtils.setModelView( glm::translate<GLfloat>( glm::vec3( BasicWindow::SCREEN_WIDTH / 2.f, BasicWindow::SCREEN_HEIGHT / 2.f, 0.f ) ) );
    shaderUtils.updateModelView();

    //Set texture ID
    glBindTexture( GL_TEXTURE_2D, texture );

        shaderUtils.enableVertexPointer();
        shaderUtils.enableTexCoordPointer();
    //Enable vertex arrays
    //glEnableClientState( GL_VERTEX_ARRAY );

        //Set vertex data
        glBindBuffer( GL_ARRAY_BUFFER, gVBO );
        //glVertexPointer( 2, GL_FLOAT, 0, NULL );
            //Update vertex buffer data
            glBufferSubData( GL_ARRAY_BUFFER, 0, 4 * sizeof(GLTexturedVertex), vertices );

            //Set texture coordinate data
            shaderUtils.setTexCoordPointer( sizeof(GLTexturedVertex), (GLvoid*)offsetof( GLTexturedVertex, _textureCoord ) );

            //Set vertex data
            shaderUtils.setVertexPointer( sizeof(GLTexturedVertex), (GLvoid*)offsetof( GLTexturedVertex, _vertexCoord ) );


        //Draw quad using vertex data and index data
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
        glDrawElements( GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL );

    //Disable vertex arrays
    //glDisableClientState( GL_VERTEX_ARRAY );
    //Disable vertex and texture coordinate arrays
    shaderUtils.disableVertexPointer();
    shaderUtils.disableTexCoordPointer();

//    glBegin(GL_QUADS);
//        glVertex2f(_leftTop.getX(), _leftTop.getY());
//        glVertex2f(_leftTop.getX(), _leftTop.getY() + _ySideLength);
//        glVertex2f(_leftTop.getX() + _xSideLength, _leftTop.getY() + _ySideLength);
//        glVertex2f(_leftTop.getX() + _xSideLength, _leftTop.getY());
//    glEnd();
}

void Rectangle1::drawBorder(float lineWidth){
    glLineWidth(lineWidth);
    glBegin(GL_LINE_STRIP);
        glVertex2f(_leftTop.getX(), _leftTop.getY());
        glVertex2f(_leftTop.getX(), _leftTop.getY() + _ySideLength);
        glVertex2f(_leftTop.getX() + _xSideLength, _leftTop.getY() + _ySideLength);
        glVertex2f(_leftTop.getX() + _xSideLength, _leftTop.getY());
        glVertex2f(_leftTop.getX(), _leftTop.getY());
    glEnd();
}

Square::Square(){
    _leftTop.setCoord(0.0f, 0.0f);
    _sideLength = 0.0f;
}

Square::Square(Point leftTop, float sideLength){
    _leftTop.setCoord(leftTop);
    _sideLength = sideLength;
}

void Square::draw(){
    glBegin(GL_QUADS);
        glVertex2f(_leftTop.getX(), _leftTop.getY());
        glVertex2f(_leftTop.getX(), _leftTop.getY() + _sideLength);
        glVertex2f(_leftTop.getX() + _sideLength, _leftTop.getY() + _sideLength);
        glVertex2f(_leftTop.getX() + _sideLength, _leftTop.getY());
    glEnd();
}

void Square::drawBorder(float lineWidth){
    glLineWidth(lineWidth);
    glBegin(GL_LINE_STRIP);
        glVertex2f(_leftTop.getX(), _leftTop.getY());
        glVertex2f(_leftTop.getX(), _leftTop.getY() + _sideLength);
        glVertex2f(_leftTop.getX() + _sideLength, _leftTop.getY() + _sideLength);
        glVertex2f(_leftTop.getX() + _sideLength, _leftTop.getY());
        glVertex2f(_leftTop.getX(), _leftTop.getY());
    glEnd();
}

void Shape::setColor( GLfloat r, GLfloat g, GLfloat b, GLfloat a )
{
    //Update color in shader
//    glUniform4f( mPolygonColorLocation, r, g, b, a );
}


#endif // SHAPES_H
