#ifndef BASICTRANSFORMANIMATION_H
#define BASICTRANSFORMANIMATION_H

class BasicTransformAnimation
{
private:
	long _duration;
	long _elapsedTime;
	bool _fillAfter;
	Point _relativePoint;

protected:
	bool _finished;

public:

	void setDuration(long duration);
	long getDuration();

	void setElapsedTime(long elapsedTime);
	long getElapsedTime();

	void setFillAfter(bool fillAfter);
	bool getFillAfter();

	bool isFinished();

	void setRelativePoint(Point relativePoint);
	Point getRelativePoint();

	void setRelativePointX(float x);
	float getRelativePointX();

	void setRelativePointY(float y);
	float getRelativePointY();

	virtual void update() = 0;
};

void BasicTransformAnimation::setDuration(long duration)
{
	_duration = duration;
}

long BasicTransformAnimation::getDuration()
{
	return _duration;
}

void BasicTransformAnimation::setElapsedTime(long elapsedTime)
{
	_elapsedTime = elapsedTime;
}

long BasicTransformAnimation::getElapsedTime()
{
	return _elapsedTime;
}

void BasicTransformAnimation::setFillAfter(bool fillAfter)
{
	_fillAfter = fillAfter;
}

bool BasicTransformAnimation::getFillAfter()
{
	return _fillAfter;
}

bool BasicTransformAnimation::isFinished()
{
	return _finished;
}

void BasicTransformAnimation::setRelativePoint(Point relativePoint)
{
	_relativePoint = relativePoint;
}

void BasicTransformAnimation::setRelativePointX(float x)
{
	_relativePoint.setX(x);
}

float BasicTransformAnimation::getRelativePointX()
{
	return _relativePoint.getX();
}

void BasicTransformAnimation::setRelativePointY(float y)
{
	_relativePoint.setX(y);
}

float BasicTransformAnimation::getRelativePointY()
{
	return _relativePoint.getY();
}

Point BasicTransformAnimation::getRelativePoint()
{
	return _relativePoint;
}

#endif // BASICTRANSFORMANIMATION_H
