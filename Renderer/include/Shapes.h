#ifndef SHAPES_H
#define SHAPES_H

#include "OpenglHeaders.h"

class Shape
{
    public:
        virtual void draw() = 0;
        void setColor( GLfloat r, GLfloat g, GLfloat b, GLfloat a );
};

class GLPoint{
  private:
    float _x,_y;

  public:
    GLPoint();
    GLPoint(GLfloat x, GLfloat y);
    GLfloat getX();
    GLfloat getY();
    void setCoord(GLfloat x, GLfloat y);
    void setCoord(GLPoint p);
};

class Point : Shape{
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

class Line : Shape{
  private:
      Point _p1, _p2;

  public:
    Line();
    Line(Point p1, Point p2);
    Line(float px1, float py1, float px2, float py2);
    void draw();
};

class Rectangle1 : Shape{
  private:
    Point _leftTop;
    float _xSideLength;
    float _ySideLength;

    GLPoint quadVertices[ 4 ];
    GLuint indices[ 4 ];
    GLuint gVBO = NULL;
    GLuint gIBO = NULL;


  public:
    Rectangle1();
    Rectangle1(Point leftTop, float xSideLength, float ySideLength);
    void drawBorder(float lineWidth);
    void draw();
};

class Square : Shape{
  private:
    Point _leftTop;
    float _sideLength;

  public:
    Square();
    Square(Point leftTop, float sideLength);
    void drawBorder(float lineWidth);
    void draw();
};

#endif // SHAPES_H
