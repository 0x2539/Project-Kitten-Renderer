#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>
#include <cstring>
#include "Shapes/ShapeRectangle.h"
#include "Rectangle2.h"

#include <algorithm>

using namespace std;

class Quadtree{
private:
	int MAX_OBJECTS = 10;
	int MAX_DEPTH = 5;

	int _level;
	Rectangle2 *_box;
	vector<ShapeRectangle*> _objects;
	Quadtree* _children[4], *_parent;

public:
	
	Quadtree(int depthLevel, Quadtree* parent, int x, int y, int width, int height);

	bool contains(ShapeRectangle* obj);

	Quadtree* insert(Quadtree *root, ShapeRectangle* obj);
	Quadtree* insert(ShapeRectangle* obj);

	int query(ShapeRectangle* obj);
	int query(Quadtree *root, ShapeRectangle* obj);

	float getBoxX();
	float getBoxY();
	float getBoxWidth();
	float getBoxHeight();
	int getDepth();

	int showEverything(Quadtree* root);
	Quadtree* updateNode(Quadtree *root, ShapeRectangle *obj);

};

Quadtree::Quadtree(int depthLevel, Quadtree* parent, int x, int y, int width, int height){
		_level = depthLevel;
		_parent = parent;
		_box = new Rectangle2(x, y, width, height);
		memset(_children, NULL, sizeof(_children));
	}

Quadtree* Quadtree::updateNode(Quadtree *root, ShapeRectangle *obj){

	if(! root -> contains(obj))
	{
		
		auto it = find (root -> _objects.begin(), root -> _objects.end(), obj);
		if (it == root -> _objects.end()) return root;

		root -> _objects.erase(it);
		//Logger::write("Yeees");
		return (root -> _parent) -> insert(obj);
	}
	else
	{
		for(int i = 0; i < 4; ++ i)
		{
			//Logger::write(toString(child -> getBoxX()) + " " + toString(child -> getBoxY()) + \
    		//	" " + toString(child -> getBoxWidth()) + " " + toString(child -> getBoxHeight()) + \
    		//	" " + toString(child -> getDepth()));
			if(root -> _children[i] == NULL)
			{
				//Logger::write("Yeees2");
				// create new child
				float W = root -> getBoxWidth();
				float H = root -> getBoxHeight();

				float xp = root -> getBoxX() + (i & 1) * (W / 2);
				float yp = root -> getBoxY() + ((i & 2) > 0) * (H / 2);
				float wp = W - W/2;
				float hp = H - H/2;

				//Logger::write(toString(xp) + " " + toString(yp) + " " + toString(wp) + " " + toString(hp));
				//Logger::write("creaatee");
				root -> _children[i] = new Quadtree(root -> getDepth() + 1, root, xp, yp, wp, hp);
			}

			if(root -> _children[i] -> contains(obj))
			{
				auto it = find (root -> _objects.begin(), root -> _objects.end(), obj);
				if (it == root -> _objects.end()) return root;

				root -> _objects.erase(it);
				
				return root -> _children[i] -> insert(obj);
			}		
		}
			
	}

	return root;
}

Quadtree* Quadtree::insert(Quadtree *root, ShapeRectangle* obj){

	for(int i = 0; i < 4; ++ i)
	{
		//Logger::write(toString(root -> getDepth()) + " " +  toString(MAX_DEPTH));
		if(root -> getDepth() >= MAX_DEPTH) continue;
		//Logger::write("yeee");
		if(root -> _children[i] == NULL)
		{
			// create new child
			float W = root -> getBoxWidth();
			float H = root -> getBoxHeight();

			float xp = root -> getBoxX() + (i & 1) * (W / 2);
			float yp = root -> getBoxY() + ((i & 2) > 0) * (H / 2);
			float wp = W - W/2;
			float hp = H - H/2; 

			//Logger::write(toString(xp) + " " + toString(yp) + " " + toString(wp) + " " + toString(hp));

			root -> _children[i] = new Quadtree(root -> getDepth() + 1, root, xp, yp, wp, hp);
		}

		if(root -> _children[i] -> contains(obj))
		{
			//Logger::write(toString(root -> getDepth()));
			//Logger::write("yeee");
			return insert(root -> _children[i], obj);
		}
	}

	
	root -> _objects.push_back(obj);
	return root;
}

int Quadtree::query(Quadtree *root, ShapeRectangle* obj){

	//Logger::write(toString(root -> getDepth()));

	for(int i = 0; i < 4; ++ i)
	{
		//Logger::write(toString(root -> getDepth()));
		if(root -> _children[i] == NULL) return 0;

		if(root -> _children[i] -> contains(obj))
		{
			return query(root -> _children[i], obj);
			
			//break;
		}
	}

	return showEverything(root);

	//for(auto object : root -> _objects)
	//	Logger::write(toString(object -> getLocationX()) + " " + toString(object -> getLocationY()));

}

int Quadtree::showEverything(Quadtree* root){
	int cnt = 0;

	for(int i = 0; i < 4; ++ i)
	{
		if(root -> _children[i] == NULL) return cnt;

		cnt += showEverything(root -> _children[i]);
	}

	for(auto object : root -> _objects)
	{
		++cnt;
		//Logger::write(toString(object -> getLocationX()) + " " + toString(object -> getLocationY()));
	}
		
	return cnt;
}

Quadtree* Quadtree::insert(ShapeRectangle* obj){
	return this -> insert(this, obj);
}

int Quadtree::query(ShapeRectangle* obj){
	return this -> query(this, obj);
}

bool Quadtree::contains(ShapeRectangle* obj){
	return this -> _box -> contains(obj);
}

float Quadtree::getBoxX(){
	return this -> _box -> getX();
}

float Quadtree::getBoxY(){
	return this -> _box -> getY();
}

float Quadtree::getBoxWidth(){
	return this -> _box -> getWidth();
}

float Quadtree::getBoxHeight(){
	return this -> _box -> getHeight();
}

int Quadtree::getDepth(){
	return this -> _level;
}

#endif // QUADTREE_H