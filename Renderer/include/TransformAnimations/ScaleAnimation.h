#ifndef SCALEANIMATION_H
#define SCALEANIMATION_H

#include "BasicTransformAnimation.h"
#include "Utils/Utils.h"

class ScaleAnimation : public BasicTransformAnimation
{
private:
	float _xScale;
	float _yScale;
	float _fromXScale;
	float _toXScale;
	float _fromYScale;
	float _toYScale;

public:
	void update();
	void setScale(float fromXScale, float toXScale, float fromYScale, float toYScale);

	float getScaleX();
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
