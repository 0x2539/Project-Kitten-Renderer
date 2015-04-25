#ifndef CAMERA_H
#define CAMERA_H

#include <algorithm>
#include "BasicWindow.h"

class Camera{
private:
	static float _x, _y;
	static float _movingSpeed;

public:

	static void init(float playerX, float playerY, float playerWidth, float playerHeight){
		_x = max(0.0f, playerX + (playerWidth - BasicWindow::SCREEN_WIDTH) / 2);
		_y = max(0.0f, playerY + (playerHeight - BasicWindow::SCREEN_HEIGHT) / 2);
	}

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