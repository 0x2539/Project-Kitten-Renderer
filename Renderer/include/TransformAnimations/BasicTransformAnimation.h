/**
    BasicTransformAnimation.h
    Purpose: Implements basic class for any animation.
    If you need an animation then create a new class
    which inherits this class and implement your methods
    there.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef BASICTRANSFORMANIMATION_H
#define BASICTRANSFORMANIMATION_H

class BasicTransformAnimation
{
private:
	//The duration of the animation
	long _duration;
	//The length of time that passed since
	//the animation has begun
	long _elapsedTime;
	//Fill after
	bool _fillAfter;
	//The relative point from which to start
	//the animation
	Point _relativePoint;

protected:
	//For when finishing the animation
	bool _finished;

public:

    /**
        Set the duration of the animation.

        @param duration the duration of the animation
        @return
    */
	void setDuration(long duration);

    /**
        Get the duration of the animation.

        @param
        @return the duration of the animation
    */
	long getDuration();

    /**
        Set the amount of time passed since starting
        the animation.

        @param elapsedTime the amount of time passed
        since starting the animation
        @return
    */
	void setElapsedTime(long elapsedTime);

    /**
        Get the amount of time passed since starting
        the animation.

        @param
        @return the amount of time passed since starting
        the animation
    */
	long getElapsedTime();

    /**
        This sets if the shape will remain the same
        after the animation is finished.

        @param fillAfter if set to true, then the shape
        will be the same after the animation has finished,
        if set to false, then the shape will come back
        to its original properties before the animation
        @return
    */
	void setFillAfter(bool fillAfter);

    /**
        Get the fill after property. This is set using
        setFillAfter(bool) method.

        @param
        @return the fill after property
    */
	bool getFillAfter();

    /**
        Get if the animation has finished.

        @param
        @return true if the animation has finished,
        false otherwise
    */
	bool isFinished();

    /**
    	Set the point from where the animation will
    	make its effect. It will take values between
    	0 and 1.

        @param relativePoint the point from which to
        take the coordinates
        @return
    */
	void setRelativePoint(Point relativePoint);

    /**
    	Get the relative point from where the animation
    	makes its effect.

        @param
        @return the relative point from where the animation
    	makes its effect
    */
	Point getRelativePoint();

    /**
    	Set the x coordinate of the relative point.

        @param x the x coordinate of the relative point
        @return
    */
	void setRelativePointX(float x);

    /**
    	Get the x coordinate of the relative point.

        @param x the x coordinate of the relative point
        @return
    */
	float getRelativePointX();

    /**
    	Set the y coordinate of the relative point.

        @param y the y coordinate of the relative point
        @return
    */
	void setRelativePointY(float y);

    /**
    	Get the y coordinate of the relative point.

        @param y the y coordinate of the relative point
        @return
    */
	float getRelativePointY();

    /**
    	This method makes transformations on the shape
    	that has this animation.

        @param
        @return
    */
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
