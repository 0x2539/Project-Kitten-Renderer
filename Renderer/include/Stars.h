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
	static vector<ShapeRectangle*> stars;
	static vector<float> starsInitialAngle;
	static vector<float> starsDirection;
	static GLuint texture;
	static float Alpha;
	static float rotationSpeed;
	static float _CenterX;
	static float _CenterY;

public:
	static float randomFloat(float a, float b);
	static float dist(float x1, float y1, float x2, float y2);	
	static float getAngle(float x1, float y1, float x2, float y2);

	static void init();
	static void draw();
	static void update();
	static void CreateUniverse(int starsNumber, float CenterX, float CenterY, float UniverseSizeX, float UniverseSizeY);
	
	static void setRotationSpeed(float newRotationSpeed);	
	static void clearMemory();	
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
	starsDirection.clear();
}

void Stars::init(){
	clearMemory();
	setDefaultTexture();
	srand(time(NULL));
	Alpha = 0;
	rotationSpeed = 1;
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

	    starsDirection.push_back((randomFloat(0,1) - 0.5f < 0) ? -1 : 1);
	  }

}

void Stars::update(){

	Alpha += rotationSpeed;
	if(Alpha >= 360) Alpha -= 360;

    for(unsigned int i = 0; i < stars.size(); ++i)
    {
        float distance = dist(_CenterX, _CenterY, stars[i] -> getLocationX(), stars[i] -> getLocationY());
        float angle = starsInitialAngle[i] + starsDirection[i] * Alpha;

        if(angle > 360) angle -= 360;
        if(angle < 0) angle += 360;

        float x = _CenterX + distance * cos(angle * M_PI / 180);
        float y = _CenterY + distance * sin(angle * M_PI / 180);

        stars[i] -> setLocation(x, y);
    }

}

void Stars::draw(){
	for(auto star : stars)
  	{
    	star -> draw();
  	}
}

void Stars::setRotationSpeed(float newRotationSpeed){
	rotationSpeed = newRotationSpeed;
}

vector<ShapeRectangle*> Stars::stars;
vector<float> Stars::starsInitialAngle;
vector<float> Stars::starsDirection;
GLuint Stars::texture;
float Stars::Alpha;
float Stars::rotationSpeed;
float Stars::_CenterX;
float Stars::_CenterY;

#endif // STARS_H