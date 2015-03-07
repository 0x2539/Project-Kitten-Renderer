#include "Shapes.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

GLPoint::GLPoint(){
    _x = 0.f;
    _y = 0.f;
}

GLPoint::GLPoint(GLfloat x, GLfloat y){
    _x = x;
    _y = y;
}

GLfloat GLPoint::getX(){
    return _x;
}

GLfloat GLPoint::getY(){
    return _y;
}

void GLPoint::setCoord(GLfloat x, GLfloat y){
    _x = x;
    _y = y;
}
void GLPoint::setCoord(GLPoint p){
    _x = p.getX();
    _y = p.getY();
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

    quadVertices[ 0 ].setCoord(leftTop.getX(), leftTop.getY());

    quadVertices[ 1 ].setCoord(leftTop.getX() + xSideLength, leftTop.getY());

    quadVertices[ 2 ].setCoord(leftTop.getX() + xSideLength, leftTop.getY() + ySideLength);

    quadVertices[ 3 ].setCoord(leftTop.getX(), leftTop.getY() + ySideLength);

    //Set rendering indices
    indices[ 0 ] = 0;
    indices[ 1 ] = 1;
    indices[ 2 ] = 2;
    indices[ 3 ] = 3;

    //Create VBO
    glGenBuffers( 1, &gVBO );
    glBindBuffer( GL_ARRAY_BUFFER, gVBO );
    glBufferData( GL_ARRAY_BUFFER, 4 * sizeof(GLPoint), quadVertices, GL_STATIC_DRAW );

    //Create IBO
    glGenBuffers( 1, &gIBO );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indices, GL_STATIC_DRAW );

    _leftTop.setCoord(leftTop);
    _xSideLength = xSideLength;
    _ySideLength = ySideLength;
}

void Rectangle1::draw(){
    setColor(0.5f, 1.f, 0.5f, 1.0f);

    //glLoadIdentity();

    shaderUtils.setModelView( glm::translate<GLfloat>( glm::vec3( BasicWindow::SCREEN_WIDTH / 2.f, BasicWindow::SCREEN_HEIGHT / 2.f, 0.f ) ) );
    shaderUtils.updateModelView();

    //Enable vertex arrays
    glEnableClientState( GL_VERTEX_ARRAY );

        //Set vertex data
        glBindBuffer( GL_ARRAY_BUFFER, gVBO );
        glVertexPointer( 2, GL_FLOAT, 0, NULL );

        //Draw quad using vertex data and index data
        glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
        glDrawElements( GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL );

    //Disable vertex arrays
    glDisableClientState( GL_VERTEX_ARRAY );

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
