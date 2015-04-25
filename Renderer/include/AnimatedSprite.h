#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "Animation.h"
#include "Shapes/ShapeRectangle.h"
#include <vector>
using namespace std;

class AnimatedSprite 
{
private:
	Animation *_spriteAnimation;
	vector< Animation* > _spriteEffectsAnimations;

public:

	AnimatedSprite()
	{
		_spriteAnimation = new Animation();
		start();
	}

	AnimatedSprite(Animation *spriteAnimation)
	{
		_spriteAnimation = spriteAnimation;
		start();
	}

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

	void addEffectAnimation(Animation *newEffectAnimation)
	{
		newEffectAnimation -> start();
		_spriteEffectsAnimations.push_back(newEffectAnimation);
	}

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

	void start()
	{
		_spriteAnimation -> start();
	}

	void draw()
	{
		_spriteAnimation -> play();
		for(auto x: _spriteEffectsAnimations)
			x -> play();
	}

	float getX()
	{
		return _spriteAnimation -> getX();
	}

	float getY()
	{
		return _spriteAnimation -> getY();
	}

	void setCoords(float x, float y)
	{
		_spriteAnimation -> setCoords(x, y);
	}

	ShapeRectangle* getRectanglePointer(){
		return _spriteAnimation -> getRectanglePointer();
	}

};

#endif // ANIMATED_SPRITE_H