/**
    Animation.h
    Purpose: Implements an animation.

    @author Ion Ureche
    @version 1.0
*/
#ifndef ANIMATION_H
#define ANIMATION_H
#include "Shapes/ShapeRectangle.h"
#include "Timer.h"
#include <cmath>

class Animation{
private:

	//The rectangle
	ShapeRectangle *_rect;
	//The duration of the animation
	float _totalDuration;
	//The rows of the sprite
	int _nrRows;
	//The columns of the sprite
	int _nrColumns;

	//The milliseconds per frame
	int _millisecondPerFrame;
	//The last time of the last frame
	int _lastTime;
	//The horizontal frame length
	float _xTextureFrameLength;
	//The vertical frame height
	float _yTextureFrameLength;
	//The x coordinate of the texture
	float _currentTextureXPos;
	//The y coordinate of the texture
	float _currentTextureYPos;
	//The current row of the sprite
	int _currentRow;
	//The current column of the sprite
	int _currentColumn;

	//If play the animation on a loop
	bool _loop;
	//If completed one cicle
	bool _completedOneCicle;
	//If started
	bool _started;

public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
	Animation(){
		_rect = new ShapeRectangle();
		_nrColumns = _nrRows = 1;
		_totalDuration = 1000;
		init();
	}

    /**
        Initialise a new instance of this class.

        @param rect the rectangle
        @param totalDuration the duration of the
        animation
        @param nrRows the number of rows of the
        sprite
        @param nrColumns the number of columns of
        the sprite
        @param loop if plays the animation on a loop
        @return
    */
	Animation(ShapeRectangle *rect, float totalDuration,
		int nrRows, int nrColumns, bool loop = false){

		_rect = rect;
		_totalDuration = abs(totalDuration);
		_nrRows = nrRows;
		_nrColumns = nrColumns;
		_loop = loop;
		init();
	}

    /**
        Initialise the current instance of this class.

        @param
        @return
    */
	void init(){
		_currentRow = _currentColumn = 0;
		_completedOneCicle = false;
		_currentTextureYPos = _currentTextureXPos = 0;
		_xTextureFrameLength = 1.0f / (float) (_nrColumns);
		_yTextureFrameLength = 1.0f / (float) (_nrRows);
		_millisecondPerFrame = (int) (_totalDuration / (_nrRows * _nrColumns));
	}

    /**
        Get the rectangle.

        @param
        @return the rectangle
    */
	ShapeRectangle* getRectanglePointer()
	{
		return _rect;
	}

    /**
        Get the x coordinate.

        @param
        @return the x coordinate
    */
	float getX()
	{
		_rect -> getLocationX();
	}

    /**
        Get the y coordinate.

        @param
        @return the y coordinate
    */
	float getY()
	{
		_rect -> getLocationY();
	}

    /**
        Set the location of the animation.

        @param x the x coordinate
        @param y the y coordinate
        @return
    */
	void setCoords(float x, float y)
	{
		_rect -> setLocation(x, y);
	}

    /**
        Play the next frame of the animation.

        @param
        @return
    */
	void switchToNextFrame()
	{
		int currentTime = Timer::getTime();

		if(currentTime - _lastTime >= _millisecondPerFrame)
		{
			// switch frame
			_currentRow += (_currentColumn + 1) / _nrColumns;
			_currentColumn = (_currentColumn + 1) % _nrColumns;

			if(_currentRow == _nrRows) 
			{
				if(_loop) _currentRow = 0;
				_completedOneCicle = true;
			}

			_lastTime += _millisecondPerFrame;
		}
	}

    /**
        Start the animation.

        @param
        @return
    */
	void start()
	{
		if(!_started) 
		{
			_lastTime = Timer::getTime(); // Sets last_time variable on first animation play
			_started = true; 

			_rect -> setTextCoord(_currentColumn * _xTextureFrameLength, // Left
						  _currentRow * _yTextureFrameLength, // Top
						  (_currentColumn + 1) *  _xTextureFrameLength, // Right
						  (_currentRow + 1) * _yTextureFrameLength); // Bottom             
		}
	}

    /**
        Play the animation.

        @param
        @return
    */	
	void play()
	{	

		if(!_started || (_started && _completedOneCicle && !_loop)) 
		{
			return ; // if is not looped we play only one animation cicle
		} 

		// draw current texture frame on the rectangle
		_rect -> draw();

		if(	_nrRows == 1 && _nrColumns == 1) return ;

		switchToNextFrame(); // check if we should move to next frame in the sprite sheed
							 // actualy we move the coordinates on texture
							 // and here we set these new(or old ones) coordinates to the rectangle
		_rect -> setTextCoord(_currentColumn * _xTextureFrameLength, // Left
						  _currentRow * _yTextureFrameLength, // Top
						  (_currentColumn + 1) *  _xTextureFrameLength, // Right
						  (_currentRow + 1) * _yTextureFrameLength); // Bottom
	}
};

#endif // ANIMATION_H