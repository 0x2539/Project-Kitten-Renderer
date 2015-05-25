/**
    Input.h
    Purpose: Manages basic input.

    @author Ion Ureche
    @version 1.0
*/
#ifndef Input_H
#define Input_H
#include "SDL2/SDL.h"
#include "Logger.h"

using namespace std;

class Input
{
private:
	// TO DO: Logger Message history
	//The mouse x coordinate
	static int _MouseX;
	//The mouse y coordinate
	static int _MouseY;
	//If the key is beeing pressed
	static bool keys[256];

public:

    /**
        When a key has been pressed.

        @param key the key that is being pressed
        @return
    */
	static void keyDown(unsigned char key)
	{
		keys[key] = true;
	}

    /**
        When a key is not beeing pressed.

        @param key the key that is not being pressed
        @return
    */
	static void keyUp(unsigned char key)
	{
		keys[key] = false;
	}

    /**
        Check if a key is pressed.

        @param key the key to check if it is pressed
        @return true if the key is pressed, false
        otherwise
    */
	static bool isKeyPressed(unsigned char key)
	{
		return keys[key];
	}
};

int Input::_MouseX, Input::_MouseY;
bool Input::keys[256];

#endif // Input_H