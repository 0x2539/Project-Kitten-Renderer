#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "OpenglHeaders.h"
#include "Shapes/Shape.h"
#include "Shapes/Point.h"


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