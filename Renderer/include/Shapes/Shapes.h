#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "OpenglHeaders.h"
#include "Shapes/Shape.h"
#include "Shapes/Point.h"


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

class Line : public Shape{
  private:
      Point _p1, _p2;

  public:
    Line();
    Line(Point p1, Point p2);
    Line(float px1, float py1, float px2, float py2);
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

Line::Line(){
    _p1.setLocation(0.f, 0.f);
    _p2.setLocation(0.f, 0.f);
}

Line::Line(float px1, float py1, float px2, float py2){
    _p1.setLocation(px1, py1);
    _p2.setLocation(px2, py2);
}

Line::Line(Point p1, Point p2){
    _p1.setLocation(p1);
    _p2.setLocation(p2);
}

void Line::draw(){
    glBegin(GL_LINES);
      glVertex2f(_p1.getX(), _p1.getY());
      glVertex2f(_p2.getX(), _p2.getY());
    glEnd();
}

Square::Square(){
    _leftTop.setLocation(0.0f, 0.0f);
    _sideLength = 0.0f;
}

Square::Square(Point leftTop, float sideLength){
    _leftTop.setLocation(leftTop);
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
