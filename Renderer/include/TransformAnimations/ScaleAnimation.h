/**
    ScaleAnimation.h
    Purpose: Implements the scale animation.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef SCALEANIMATION_H
#define SCALEANIMATION_H

#include "BasicTransformAnimation.h"
#include "Utils/Utils.h"

class ScaleAnimation : public BasicTransformAnimation
{
private:
	//The current scale on horizontal
	float _xScale;
	//The current scale on vertical
	float _yScale;
	//From what scale to start the animation
	//on horizontal
	float _fromXScale;
	//To what scale to finish the animation
	//on horizontal
	float _toXScale;
	//From what scale to start the animation
	//on vertical
	float _fromYScale;
	//To what scale to finish the animation
	//on vertical
	float _toYScale;

public:

    /**
    	This method makes transformations on the shape
    	that has this animation.

        @param
        @return
    */
	void update();

    /**
    	Initialise the scales.

        @param fromXScale the scale from which to start
        the animation on horizontal
        @param toXScale the scale to which to finish
        the animation on horizontal
        @param fromYScale the scale from which to start
        the animation on vertical
        @param toYScale the scale to which to finish
        the animation on vertical
        @return
    */
	void setScale(float fromXScale, float toXScale, float fromYScale, float toYScale);

    /**
    	Get the horizontal scale.

        @param
        @return the horizontal scale
    */
	float getScaleX();

    /**
    	Get the vertical scale.

        @param
        @return the vertical scale
    */
	float getScaleY();
};


void ScaleAnimation::update()
{
	if(!_finished && getElapsedTime() < getDuration())
	{
		_xScale = _fromXScale + (float)(_toXScale - _fromXScale) * ((float)getElapsedTime() / getDuration());
		_yScale = _fromYScale + (float)(_toYScale - _fromYScale) * ((float)getElapsedTime() / getDuration());
	}
	else
	{
		if(!getFillAfter())
		{
			_xScale = _fromXScale;
			_yScale = _fromYScale;
		}
		_finished = true;
	}
	//Logger::write(toString((float)getElapsedTime() / getDuration()) + " " + toString(_xScale) + " " + toString(getElapsedTime()) + " " + toString(getDuration()));
	setElapsedTime(getElapsedTime() + 17);
}

void ScaleAnimation::setScale(float fromXScale, float toXScale, float fromYScale, float toYScale)
{
	_fromXScale = fromXScale;
	_toXScale = toXScale;

	_fromYScale = fromYScale;
	_toYScale = toYScale;

	_xScale = fromXScale;
	_yScale = fromYScale;
}

float ScaleAnimation::getScaleX()
{
	return _xScale;
}

float ScaleAnimation::getScaleY()
{
	return _yScale;
}

#endif // SCALEANIMATION_H
