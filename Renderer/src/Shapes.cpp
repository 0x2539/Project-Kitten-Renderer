#include "Shapes.h"
#include <SDL_opengl.h>
#include <GL\GLU.h>

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
    _leftTop.setCoord(leftTop);
    _xSideLength = xSideLength;
    _ySideLength = ySideLength;
}

void Rectangle1::draw(){
    glBegin(GL_QUADS);
        glVertex2f(_leftTop.getX(), _leftTop.getY());
        glVertex2f(_leftTop.getX(), _leftTop.getY() + _ySideLength);
        glVertex2f(_leftTop.getX() + _xSideLength, _leftTop.getY() + _ySideLength);
        glVertex2f(_leftTop.getX() + _xSideLength, _leftTop.getY());
    glEnd();
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
