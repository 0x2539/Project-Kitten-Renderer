#ifndef CAMERA_H
#define CAMERA_H

class Camera{
private:
	static float _x, _y;

public:

	static float getX()
	{
		return _x;
	}

	static float getY()
	{
		return _y;
	}

	static void setCoords(float x, float y)
	{
		setX(x);
		setY(y);
	}

	static void setX(float x)
	{
		_x = x;
	}

	static void setY(float y)
	{
		_y = y;
	}

};

float Camera::_x, Camera::_y;

#endif // CAMERA_H