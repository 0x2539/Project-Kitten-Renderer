#ifndef Rectangle2_H
#define Rectangle2_H

class Rectangle2{
private:
	float _x, _y;
	float _width, _height;

public:
	Rectangle2();
	Rectangle2(int x, int y, int width, int height);

	float getX();
	float getY();
	float getWidth();
	float getHeight();

	bool intersects(Rectangle2 *rectangle);
	bool contains(Rectangle2 *rectangle);
};

bool Rectangle2::intersects(Rectangle2 *rectangle){
	if(this -> getX() + this -> getWidth() - 1 < rectangle -> getX()) return false;
	if(this -> getY() + this -> getHeight() - 1 < rectangle -> getY()) return false;
	if(rectangle -> getX() + rectangle -> getWidth() - 1 < this -> getX()) return false;
	if(rectangle -> getY() + rectangle -> getHeight() - 1 < this -> getY()) return false;
	return true;
}

bool Rectangle2::contains(Rectangle2 *rectangle){
	return (this -> getX() <= rectangle -> getX() && \
			this -> getY() <= rectangle -> getY() && \
			this -> getX() + this -> getWidth() >= rectangle -> getX() + rectangle -> getWidth() && \
			this -> getY() + this -> getHeight() >= rectangle -> getY() + rectangle -> getHeight());
		
}

float Rectangle2::getX(){
	return _x;
}

float Rectangle2::getY(){
	return _y;
}

float Rectangle2::getWidth(){
	return _width;
}

float Rectangle2::getHeight(){
	return _height;
}


#endif // Rectangle2_H