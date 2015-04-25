#ifndef CAMERA_H
#define CAMERA_H

class Camera{
private:
	static float _x, _y;
	static float _movingSpeed;

public:

	static void setSpeed(float newCameraMovingSpeed){
		_movingSpeed = newCameraMovingSpeed;
	}

	static float getX()
	{
		return _x;
	}

	static float getY()
	{
		return _y;
	}

	static float getCameraMovingSpeed()
	{
		return _movingSpeed;
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

float Camera::_x, Camera::_y, Camera::_movingSpeed = 2;

#endif // CAMERA_H