/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL OpenGL, standard IO, and, strings
#include "SDL2/SDL.h"
#include <stdio.h>
#include <string>
#include "GLUtils.h"
#include "Shapes.h"
#include "TextureLoader.h"
#include "Logger.h"
#include "AudioEngine.h"
#include "Timer.h"
#include "Animation.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
GLuint tx,tx2;
Rectangle1 *rect1, *rect2;
TextureLoader *TL;
Animation *testAnimation;
//Input handler
void handleKeys( unsigned char key, int x, int y );

//Per frame update
void update();

//Renders quad to the screen
void render();

//Frees media and shuts down SDL
void close();
//Render flag
bool gRenderQuad = true;


void handleKeys( unsigned char key, int x, int y )
{
  //Toggle quad
  if( key == 'q' )
    {
      gRenderQuad = !gRenderQuad;
    }
}

void update()
{
  //No per frame update needed
}

void render()
{
  //Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );
  
  rect1 -> draw();
  testAnimation -> play();
}

void TestingMethod(){
  Logger::write("Sample message");

  // This is the usage of TextureLoader class
  string path = "img.png";
  TL = TextureLoader::getInstance();
  TL -> addTexture(path);
  TL -> addTexture("effect6.png");
  tx = TL -> getTexture(path);
  tx2 = TL -> getTexture("effect6.png");
  //AudioEngine::playSound(Sounds::COOL_FLAC);
  //AudioEngine::playSound(Sounds::COOL_MP3, 1.0f);
  //GLUtils::loadTexture("img.png");

  rect1 = new Rectangle1(Point(0, 0), 100, 100);
  rect2 = new Rectangle1(Point(-100, -100), 100, 100);
  
  rect1 -> setTexture(tx);
  rect2 -> setTexture(tx2);


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
      
      TestingMethod();

      start = SDL_GetTicks();

       //While application is running
       while( !quit )
	     {
	       //Handle evens on queue
	       while( SDL_PollEvent( &e ) != 0 )
	       {
    	      //User requests quit
    	      if( e.type == SDL_QUIT )
            {
        		  quit = true;
        		}
    	      //Handle keypress with current mouse position
    	      else if( e.type == SDL_TEXTINPUT )
        		{
        		      int x = 0, y = 0;
        					SDL_GetMouseState( &x, &y );
        					handleKeys( e.text.text[ 0 ], x, y );
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
