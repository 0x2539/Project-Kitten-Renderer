/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL OpenGL, standard IO, and, strings
#include "SDL2/SDL.h"
#include <stdio.h>
#include <string>
#include "GLUtils.h"
#include "Shapes/ShapeRectangle.h"
#include "TextureLoader.h"
#include "Logger.h"
#include "Input.h"
#include "AudioEngine.h"
#include "Timer.h"
#include "Animation.h"
#include "TransformAnimations/ScaleAnimation.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
GLuint tx,tx2;
ShapeRectangle *rect1, *rect2;
TextureLoader *TL;
Animation *testAnimation;
ScaleAnimation *sA;
Input myInput;
//Input handler

//Per frame update
void update();

//Renders quad to the screen
void render();

//Frees media and shuts down SDL
void close();
//Render flag
bool gRenderQuad = true;

void update()
{
  //No per frame update needed
}

void render()
{
  //Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );
  
  rect1 -> update();
  rect1 -> draw();
  testAnimation -> play();

}

void TestingMethod(){
  Logger::write("Sample message");

  // This is the usage of TextureLoader class
  string path = "imgs.png";
  TL = TextureLoader::getInstance();
  TL -> addTexture(path);
  TL -> addTexture("effect6.png");
  tx = TL -> getTexture(path);
  tx2 = TL -> getTexture("effect6.png");
  //AudioEngine::playSound(Sounds::COOL_FLAC);
  //AudioEngine::playSound(Sounds::COOL_MP3, 1.0f);
  //GLUtils::loadTexture("img.png");

  rect1 = new ShapeRectangle(Point(0, 0), 100, 100);
  rect2 = new ShapeRectangle(Point(200, 200), 100, 100);
  
  rect1 -> setTexture(tx);
  rect2 -> setTexture(tx2);


  sA = new ScaleAnimation();
  sA -> setScale(1, 1.0f/3.0f, 1, 1.0f/3.0f);
  sA -> setDuration(1000);
  sA -> setFillAfter(false);

  rect1 -> addAndStartAnimation(sA);

  testAnimation = new Animation(rect2, 1000, 8, 5, true);
  testAnimation -> start();
}

void close()
{
  //Destroy window
  SDL_DestroyWindow( BasicWindow::getWindow() );
  BasicWindow::setWindow(NULL);
  
  //Quit SDL subsystems
  SDL_Quit();
}

int main( int argc, char* args[] )
{
  myInput += {SDLK_w, {[](){ cout << "Ai apasat w\n"; }, "w"}};
  myInput += {SDLK_a, {[](){ cout << "Ai apasat a\n"; }, "a"}};
  myInput += {SDLK_s, {[](){ cout << "Ai apasat s\n"; }, "s"}};
  myInput += {SDLK_d, {[](){ cout << "Ai apasat d\n"; }, "d"}};
  
    //The timer starting time
    Uint32 start = 0;

    //The timer start/stop flag
    bool running = true;
    
  //Start up SDL and create window
  if( !GLUtils::initGraphics(SCREEN_WIDTH, SCREEN_HEIGHT)) //init() )
    {
      printf( "Failed to initialize!\n" );
    }
  else
    {
      //Main loop flag
      bool quit = false;
      
      //Event handler
      SDL_Event e;
      
      //Enable text input
      SDL_StartTextInput();

      // *************
      
	start = SDL_GetTicks();
      
      //While application is running
      while( !quit )
	{
	  //Handle events on queue
	  while( SDL_PollEvent( &e ) != 0 )
	    {
	      //User requests quit
	      if( e.type == SDL_QUIT )
		{
		  quit = true;
		}
	      //Handle keypress with current mouse position
	      else if( e.type == SDL_KEYDOWN )
		{
		  myInput.Invoke (e.key.keysym.sym);
		}
	    }

	  
	     //Render quad
	     render();
	  
	     //Update screen
	     SDL_GL_SwapWindow( BasicWindow::getWindow() );
	     }
      
      //Disable text input
      SDL_StopTextInput();
    }
  
  //Free resources and close SDL
  close();
  
  return 0;
}
