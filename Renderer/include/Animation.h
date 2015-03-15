#ifndef ANIMATION_H
#define ANIMATION_H
#include "Shapes.h"
#include "Timer.h"

class Animation{
private:

	Rectangle1 *_rect;
	float _totalDuration;
	int _nrRows;
	int _nrColumns;

	int _millisecondPerFrame;
	int _lastTime;
	float _xTextureFrameLength;
	float _yTextureFrameLength;
	float _currentTextureXPos;
	float _currentTextureYPos;
	int _currentRow;
	int _currentColumn;

	bool _loop;
	bool _completedOneCicle;
	bool _started;

public:

	Animation(){
		_rect = new Rectangle1();
		_nrColumns = _nrRows = 1;
		_totalDuration = 1000;
		init();
	}

	Animation(Rectangle1 *rect, float totalDuration,
		int nrRows, int nrColumns, bool loop = false){

		_rect = rect;
		_totalDuration = totalDuration;
		_nrRows = nrRows;
		_nrColumns = nrColumns;
		_loop = loop;
		init();
	}

	void init(){
		_currentRow = _currentColumn = 0;
		_completedOneCicle = false;
		_currentTextureYPos = _currentTextureXPos = 0;
		_xTextureFrameLength = 1.0f / (float) (_nrColumns);
		_yTextureFrameLength = 1.0f / (float) (_nrRows);
		_millisecondPerFrame = (int) (_totalDuration / (_nrRows * _nrColumns));
	}

	void switchToNextFrame(){
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

	void start(){
		if(!_started) {
			_lastTime = Timer::getTime(); // Sets last_time variable on first animation play
			_started = true;              
		}
	}
	
	void play(){	

		if(!_started || (_started && _completedOneCicle && !_loop)) return ; // if is not looped we play only one animation cicle

		switchToNextFrame(); // check if we should move to next frame in the sprite sheed
							 // actualy we move the coordinates on texture
							 // and here we set these new(or old ones) coordinates to the rectangle
		_rect -> setTextCoord(_currentColumn * _xTextureFrameLength, // Left
						  _currentRow * _yTextureFrameLength, // Top
						  (_currentColumn + 1) *  _xTextureFrameLength, // Right
						  (_currentRow + 1) * _yTextureFrameLength); // Bottom
		
		// draw current texture frame on the rectangle
		_rect -> draw();
	}
};

#endif // ANIMATION_H