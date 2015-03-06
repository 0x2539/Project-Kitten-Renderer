#ifndef SHAPES_H
#define SHAPES_H

class Shape
{
    public:
        virtual void draw() = 0;
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

class Square : Shape{
  private:
    Point _leftTop;
    Point _leftBottom;
    Point _rightBottom;
    Point _rightTop;

  public:
    Square();
    Square(Point leftTop, Point leftBottom, Point rightBottom, Point rightTop);
    void drawBorder();
    void draw();
};

#endif // SHAPES_H
