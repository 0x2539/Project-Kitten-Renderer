/**
    Point.h
    Purpose: Implements a basic point.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef POINT_H
#define POINT_H

class Point
{
  private:

    //The x coordinate
    float *_x;
    //The y coordinate
    float *_y;

  public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
    Point();

    /**
        Initialise a new instance of this class.

        @param x the x coordinate
        @param y the y coordinate
        @return
    */
    Point(float x, float y);

    /**
        Initialise a new instance of this class.

        @param x the x coordinate
        @param y the y coordinate
        @return
    */
    Point(float *x, float *y);

    /**
        Set a new location for the point.

        @param p the point from which the current
        point will get the location
        @return
    */
    void setLocation(Point p);

    /**
        Set a new location for the point.

        @param x the x coordinate
        @param y the y coordinate
        @return
    */
    void setLocation(float x, float y);
    
    /**
        Set a new x coordinate for the point.

        @param x the x coordinate of the point
        @return
    */
    void setX(float x);

    /**
        Get the point's x coordinate.

        @param
        @return the point's x coordinate
    */
    float getX();
    
    /**
        Set a new y coordinate for the point.

        @param y the y coordinate of the point
        @return
    */
    void setY(float y);

    /**
        Get the point's y coordinate.

        @param
        @return the point's y coordinate
    */
    float getY();

    /**
        Allocate dynamic memory for the x and y
        coordinates.

        @param
        @return
    */
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
