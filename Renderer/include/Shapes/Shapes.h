/**
    Shapes.h
    Purpose: Implements basic shapes: line and square.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "OpenglHeaders.h"
#include "Shapes/Shape.h"
#include "Shapes/Point.h"


class Line : public Shape{
  private:
    //Point p1
    Point _p1;
    //Point p2
    Point _p2;

  public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
    Line();

    /**
        Initialise a new instance of this class.

        @param p1 the first point of the line
        @param p2 the second point of the line
        @return
    */
    Line(Point p1, Point p2);

    /**
        Initialise a new instance of this class.

        @param px1 the x coordinate of the first point
        @param py1 the y coordinate of the first point
        @param px2 the x coordinate of the second point
        @param py2 the y coordinate of the second point
        @return
    */
    Line(float px1, float py1, float px2, float py2);

    /**
        Draw the line.

        @param
        @return
    */
    void draw();
};

class Square : public Shape{
  private:
    //The top-left point
    Point _leftTop;
    //The length of a side
    float _sideLength;

  public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
    Square();

    /**
        Initialise a new instance of this class.

        @param leftTop the top-left point
        @return sideLength the length of a side
    */
    Square(Point leftTop, float sideLength);

    /**
        Draw a border around the square.

        @param lineWidth the width of the border
        @return
    */
    void drawBorder(float lineWidth);

    /**
        Draw the square.

        @param
        @return
    */
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

#endif // SHAPES_H