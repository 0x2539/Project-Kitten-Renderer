#ifndef POINT_H
#define POINT_H

class Point
{
  private:
    float *_x, *_y;

  public:
    Point();
    Point(float x, float y);
    Point(float *x, float *y);

    void setLocation(Point p);
    void setLocation(float x, float y);
    
    void setX(float x);
    float getX();
    
    void setY(float y);
    float getY();

    void allocateDynamicMemory();
};

void Point::allocateDynamicMemory()
{
    _x = new float;
    _y = new float;
}

Point::Point()
{
    allocateDynamicMemory();
	setLocation(0, 0);
}

Point::Point(float x, float y)
{
    allocateDynamicMemory();
	setLocation(x, y);
}

Point::Point(float *x, float *y)
{
    _x = x;
    _y = y;
}

void Point::setLocation(float x, float y)
{
	setX(x);
	setY(y);
}

void Point::setLocation(Point p)
{
	setLocation(p.getX(), p.getY());
}

void Point::setX(float x)
{
	*_x = x;
}

float Point::getX()
{
    return *_x;
}

void Point::setY(float y)
{
	*_y = y;
}

float Point::getY()
{
    return *_y;
}


#endif // POINT_H
