/**
    Stars.h
    Purpose: Decorative background for games, which simulates rotating stars on the night sky.

    @author Ion Ureche
    @version 1.0
*/
#ifndef STARS_H
#define STARS_H

#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "TextureLoader.h"
#include "Shapes/ShapeRectangle.h"

class Stars{

private:
	//The stars rectangles
	static vector<ShapeRectangle*> stars;
	//The stars initial angle
	static vector<float> starsInitialAngle;
	//The stars rotation speed
	static vector<float> starsRotationSpeed;

	//The texture
	static GLuint texture;
	//The x coordinate of the center
	static float _CenterX;
	//The y coordinate of the center
	static float _CenterY;

public:

    /**
        Generates a random float between a and b.

        @param a the minimum value returned
        @param b the maximum value returned
        @return a random float
    */
	static float randomFloat(float a, float b);

    /**
        Get the distance between two points.

        @param x1 the x coordinate of the first point
        @param y1 the y coordinate of the first point
        @param x2 the x coordinate of the second point
        @param y2 the y coordinate of the second point
        @return the distance between the two points
    */
	static float dist(float x1, float y1, float x2, float y2);	

    /**
        Get the angle between two points.

        @param x1 the x coordinate of the first point
        @param y1 the y coordinate of the first point
        @param x2 the x coordinate of the second point
        @param y2 the y coordinate of the second point
        @return the distance between the two points
    */
	static float getAngle(float x1, float y1, float x2, float y2);

    /**
        Initialise the stars.

        @param
        @return
    */
	static void init();

    /**
        Draw the stars.

        @param
        @return
    */
	static void draw();

    /**
        Update the stars.

        @param
        @return
    */
	static void update();

    /**
        Create the universe for the stars.

        @param starsNumber the number of the stars
        @param CeterX the x coordinate of the center
        for the universe
        @param CeterY the y coordinate of the center
        for the universe
        @param UniverseSizeX the horizontal size
        of the universe
        @param UniverseSizeY the vertical size
        of the universe
        @return
    */
	static void CreateUniverse(int starsNumber, float CenterX, float CenterY, float UniverseSizeX, float UniverseSizeY);
	
    /**
        Clear the memory.

        @param
        @return
    */
	static void clearMemory();	

    /**
        Set the default texture for stars.

        @param
        @return
    */
	static void setDefaultTexture();
};

void Stars::setDefaultTexture(){
	TextureLoader *TL = TextureLoader::getInstance();
	TL -> addTexture("Assets/WhiteSquare.png");
	texture = TL -> getTexture("Assets/WhiteSquare.png");
}

void Stars::clearMemory(){
	stars.clear();
	starsInitialAngle.clear();
	starsRotationSpeed.clear();
}

void Stars::init(){
	clearMemory();
	setDefaultTexture();
	srand(time(NULL));
}

float Stars::dist(float x1, float y1, float x2, float y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float Stars::randomFloat(float a, float b){
  return a + (b - a)*(rand() * 1.0f / RAND_MAX); 
}

float Stars::getAngle(float x1, float y1, float x2, float y2){
    float angle;

    angle = atan2(y1, x1) - atan2(y2, x2);

    angle = angle * 360 / (2 * M_PI);

    if(angle < 0) angle += 360;

    return angle;
}

void Stars::CreateUniverse(int starsNumber, float CenterX, float CenterY, float UniverseSizeX, float UniverseSizeY)
{
	init();
	_CenterX = CenterX;
	_CenterY = CenterY;

	for(int t = 0; t < starsNumber; ++t)
	  {
	    float sz = randomFloat(0, 1);
	    float newx = randomFloat(0, UniverseSizeX);
	    float newy = randomFloat(0, UniverseSizeY);
	    stars.push_back(new ShapeRectangle(new Point(newx, newy), 1, 1, texture));
	             
	    starsInitialAngle.push_back(getAngle(0, 0, newx -_CenterX, newy - _CenterY));

	    starsRotationSpeed.push_back(randomFloat(-2,2));
	  }

}

void Stars::update(){

    for(unsigned int i = 0; i < stars.size(); ++i)
    {
        float distance = dist(_CenterX, _CenterY, stars[i] -> getLocationX(), stars[i] -> getLocationY());
        float angle = starsInitialAngle[i] + starsRotationSpeed[i];

        if(angle >= 360) angle -= 360;
        if(angle < 0) angle += 360;

        float x = _CenterX + distance * cos(angle * M_PI / 180);
        float y = _CenterY + distance * sin(angle * M_PI / 180);

        starsInitialAngle[i] = angle;

        stars[i] -> setLocation(x, y);
    }

}

void Stars::draw(){
	for(auto star : stars)
  	{
    	star -> draw();
  	}
}

vector<ShapeRectangle*> Stars::stars;
vector<float> Stars::starsInitialAngle;
vector<float> Stars::starsRotationSpeed;
GLuint Stars::texture;
float Stars::_CenterX;
float Stars::_CenterY;

#endif // STARS_H