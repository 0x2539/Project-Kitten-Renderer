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


