#ifndef Input_H
#define Input_H
#include "SDL2/SDL.h"
#include "Logger.h"

using namespace std;

class Input
{
private:
	// TO DO: Logger Message history
	static int _MouseX, _MouseY;
	static bool keys[256];

public:

	static void keyDown(unsigned char key)
	{
		keys[key] = true;
	}

	static void keyUp(unsigned char key)
	{
		keys[key] = false;
	}

	static bool isKeyPressed(unsigned char key)
	{
		return keys[key];
	}
};

int Input::_MouseX, Input::_MouseY;
bool Input::keys[256];

#endif // Input_H