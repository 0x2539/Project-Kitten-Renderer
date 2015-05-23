/**
    Camera.h
    Purpose: Manages the application's camera.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef CAMERA_H
#define CAMERA_H

#include <algorithm>
#include "BasicWindow.h"

class Camera{
private:
	//The x coordinate
	static float _x;
	//The y coordinate
	static float _y;
	//The moving speed of the camera
	static float _movingSpeed;

public:

    /**
        Initialise the camera.

        @param playerX the x coordinate of the player
        @param playerY the y coordinate of the player
        @param playerWidth the width of the player
        @param playerHeight the height of the player
        @return
    */
	static void init(float playerX, float playerY, float playerWidth, float playerHeight){
		_x = max(0.0f, playerX + (playerWidth - BasicWindow::SCREEN_WIDTH) / 2);
		_y = max(0.0f, playerY + (playerHeight - BasicWindow::SCREEN_HEIGHT) / 2);
	}

    /**
        Gets the visibility of the camera.

        @param x the x coordinate of the camera
        @param y the y coordinate of the camera
        @param width the width of the camera
        @param height the height of the camera
        @return the visibility of the camera
    */
	static bool isVisible(float x, float y, float width, float height){
	    float cx = Camera::getX();
	    float cy = Camera::getY();

	    if(x < cx && x + width < cx) return false;
	    if(y < cy && y + height < cy) return false;
	    if(x >= cx + BasicWindow::SCREEN_WIDTH) return false;
	    if(y >= cy + BasicWindow::SCREEN_HEIGHT) return false;
	    return true;
	}

    /**
        Set the moving speed of the camera.

        @param newCameraMovingSpeed the new moving
        speed of the camera
        @return
    */
	static void setSpeed(float newCameraMovingSpeed){
		_movingSpeed = newCameraMovingSpeed;
	}

    /**
        Get the x coordinate of the camera.

        @param
        @return the x coordinate of the camera
    */
	static float getX()
	{
		return _x;
	}

    /**
        Get the y coordinate of the camera.

        @param
        @return the y coordinate of the camera
    */
	static float getY()
	{
		return _y;
	}

    /**
        Get the moving speed of the camera.

        @param
        @return the moving speed of the camera
    */
	static float getCameraMovingSpeed()
	{
		return _movingSpeed;
	}

    /**
        Set the coordinates of the camera.

        @param x the x coordinate of the camera
        @param y the y coordinate of the camera
        @return
    */
	static void setCoords(float x, float y)
	{
		setX(x);
		setY(y);
	}

    /**
        Set the x coordinate of the camera.

        @param x the x coordinate of the camera
        @return
    */
	static void setX(float x)
	{
		_x = x;
	}

    /**
        Set the y coordinate of the camera.

        @param y the y coordinate of the camera
        @return
    */
	static void setY(float y)
	{
		_y = y;
	}

};

float Camera::_x, Camera::_y, Camera::_movingSpeed = 2;

#endif // CAMERA_H