/**
    AnimatedSprite.h
    Purpose: Implements an animated sprite.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "Animation.h"
#include "Shapes/ShapeRectangle.h"
#include <vector>
using namespace std;

class AnimatedSprite
{
private:
	//The sprite animation
	Animation *_spriteAnimation;
	//The animations vector
	vector< Animation* > _spriteEffectsAnimations;

public:

    /**
        Initialise a new instance of this class.

        @param
        @return
    */
	AnimatedSprite()
	{
		_spriteAnimation = new Animation();
		start();
	}

    /**
        Initialise a new instance of this class.

        @param spriteAnimation the sprite animation
        to play
        @return
    */
	AnimatedSprite(Animation *spriteAnimation)
	{
		_spriteAnimation = spriteAnimation;
		start();
	}

    /**
        Initialise a new instance of this class.

        @param coordX the x coordinate
        @param coordY the y coordinate
        @param width the width
        @param height the height
        @param texture the texture
        @param duration the duration of the animation
        @param textureRows the number of texture's 
        rows
        @param textureCols the number of texture's
        columns
        @param looped if looping through the animation
        @return
    */
	AnimatedSprite(int coordX, int coordY, int width, int height, 
							GLuint texture, int duration, int textureRows, 
							int textureCols, bool looped = false)
	{
		ShapeRectangle *rect = new ShapeRectangle(new Point(coordX, coordY), width, height);

		rect -> setTexture(texture);

		Animation *newEffectAnimation = new Animation(rect, duration, textureRows, textureCols, looped);

		newEffectAnimation -> start();

		_spriteAnimation = newEffectAnimation;

		start();
	}
	// *** TESTING

    /**
        Initialise a new instance of this class.

        @param coordX the x coordinate
        @param coordY the y coordinate
        @param width the width
        @param height the height
        @param texture the texture
        @param duration the duration of the animation
        @param textureRows the number of texture's 
        rows
        @param textureCols the number of texture's
        columns
        @param looped if looping through the animation
        @return
    */
	AnimatedSprite(float *coordX, float *coordY, float *width, float *height, 
							GLuint texture, int duration, int textureRows, 
							int textureCols, bool looped = false)
	{
		ShapeRectangle *rect = new ShapeRectangle(new Point(coordX, coordY), width, height);

		rect -> setTexture(texture);

		Animation *newEffectAnimation = new Animation(rect, duration, textureRows, textureCols, looped);

		newEffectAnimation -> start();

		_spriteAnimation = newEffectAnimation;

		start();
	}



	// *** END TESTING

    /**
        Add a new animation.

        @param newEffectAnimation the new animation
        @return
    */
	void addEffectAnimation(Animation *newEffectAnimation)
	{
		newEffectAnimation -> start();
		_spriteEffectsAnimations.push_back(newEffectAnimation);
	}

    /**
        Add a new animation.

        @param coordX the x coordinate
        @param coordY the y coordinate
        @param width the width
        @param height the height
        @param texture the texture
        @param duration the duration of the animation
        @param textureRows the number of texture's 
        rows
        @param textureCols the number of texture's
        columns
        @param looped if looping through the animation
        @return
    */
	void addEffectAnimation(float coordX, float coordY, float width, float height, 
							GLuint texture, int duration, int textureRows, 
							int textureCols, bool looped = false)
	{
		ShapeRectangle *rect = new ShapeRectangle(new Point(coordX, coordY), width, height);

		rect -> setTexture(texture);

		Animation *newEffectAnimation = new Animation(rect, duration, textureRows, textureCols, looped);

		newEffectAnimation -> start();

		_spriteEffectsAnimations.push_back(newEffectAnimation);
	}

	// TESTING

    /**
        Add a new animation.

        @param coordX the x coordinate
        @param coordY the y coordinate
        @param width the width
        @param height the height
        @param texture the texture
        @param duration the duration of the animation
        @param textureRows the number of texture's 
        rows
        @param textureCols the number of texture's
        columns
        @param looped if looping through the animation
        @return
    */
	void addEffectAnimation(float *coordX, float *coordY, float *width, float *height, 
							GLuint texture, int duration, int textureRows, 
							int textureCols, bool looped = false)
	{
		ShapeRectangle *rect = new ShapeRectangle(new Point(coordX, coordY), width, height);

		rect -> setTexture(texture);

		Animation *newEffectAnimation = new Animation(rect, duration, textureRows, textureCols, looped);

		newEffectAnimation -> start();

		_spriteEffectsAnimations.push_back(newEffectAnimation);
	}

	// END TESTING

    /**
        Start the animation.

        @param
        @return
    */
	void start()
	{
		_spriteAnimation -> start();
	}

    /**
        Update the animations.

        @param
        @return
    */
	void draw()
	{
		_spriteAnimation -> play();
		for(auto x: _spriteEffectsAnimations)
			x -> play();
	}

    /**
        Get the x coordinate.

        @param
        @return the x coordinate
    */
	float getX()
	{
		return _spriteAnimation -> getX();
	}

    /**
        Get the y coordinate.

        @param
        @return the y coordinate
    */
	float getY()
	{
		return _spriteAnimation -> getY();
	}

    /**
        Set new coordinates.

        @param x the x coordinate
        @param y the y coordinate
        @return
    */
	void setCoords(float x, float y)
	{
		_spriteAnimation -> setCoords(x, y);
	}

    /**
        Get the rectangle.

        @param
        @return the rectangle
    */
	ShapeRectangle* getRectanglePointer(){
		return _spriteAnimation -> getRectanglePointer();
	}

};

#endif // ANIMATED_SPRITE_H