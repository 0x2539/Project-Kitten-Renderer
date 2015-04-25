/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL OpenGL, standard IO, and, strings
#include "SDL2/SDL.h"
#include <stdio.h>
#include <string>
#include <algorithm>
#include "GLUtils.h"
#include "Shapes/ShapeRectangle.h"
#include "TextureLoader.h"
#include "Logger.h"
#include "AudioEngine.h"
#include "Timer.h"
#include "Animation.h"
#include "TransformAnimations/ScaleAnimation.h"
#include "AnimatedSprite.h"
#include "Input.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
GLuint tx,tx2;
ShapeRectangle *rect1, *rect2, *efRec1, *efRec2;
TextureLoader *TL;
Animation *testAnimation;
ScaleAnimation *sA;
AnimatedSprite *AS, *AS2;

vector <AnimatedSprite*> walls;

float x = 100, y = 600;
float width = 100, height = 100;

int ScreenX = 0, ScreenY = 0;
int speed = 2;

void LoadSampleLevel(GLuint texture);

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


void handleKeys()
{
  static bool ok = 0;
  //Logger::write((int) Input::isKeyPressed('q'));  
  //Toggle quad
  if( Input::isKeyPressed('w'))
  {
      y -= speed;
      ok = 1;
     // Logger::write(toString("x = " + toString(x)));
  }
  else
  if(Input::isKeyPressed('s'))
  {
      y += speed;
      ok = 1;
      //Logger::write(toString("y = " + toString(y)));
  }
  else
  if(Input::isKeyPressed('d'))
  {
      x += speed;
      ok = 1;
      //Logger::write(toString("y = " + toString(y)));
  }
  else
  if(Input::isKeyPressed('a'))
  {
      x -= speed;
      ok = 1;
      //Logger::write(toString("y = " + toString(y)));
  }

  if(ok)
  {
      static float newX, newY;
      if(x + width / 2 - Camera::getX() > (SCREEN_WIDTH / 2))
      {
          newX = min(799.0f, (x + width / 2));
          Camera::setX(newX);// ScreenX = (x + width) - (SCREEN_WIDTH / 2);
      }
        
      if(y + height / 2 - Camera::getY() > (SCREEN_HEIGHT / 2))
      {
          newY = min(799.0f, (y + height / 2));
          Logger::write(newY);
          Camera::setY(newY);
      }
      
      if(y - Camera::getY() + height / 2 < (SCREEN_HEIGHT / 2))
      {
          newY = max(0.0f, (y + height / 2) - (SCREEN_HEIGHT / 2));
          Camera::setY(newY);
      }     

      if(x - Camera::getX() + width / 2 < (SCREEN_WIDTH / 2))
      {
          newX = max(0.0f, (x + width / 2) - (SCREEN_WIDTH / 2));
          Camera::setX(newX);
      }
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
  
  //rect1 -> update();
  //rect1 -> draw();

  for(auto wall : walls)
  {
    wall -> draw();
  }
    
    //Logger::write(toString(Camera::getX()) + " " + toString(Camera::getY()));
  
  //AS -> draw();
  AS2 -> draw();
}

void TestingMethod(){
  Logger::write("Sample message");

  // This is the usage of TextureLoader class
  //string path = "imgs.png";
  TL = TextureLoader::getInstance();
  //TL -> addTexture(path);
  TL -> addTexture("effect6.png");

  TL -> addTexture("Assets/e1.png");
  GLuint e1Tex = TL -> getTexture("Assets/e1.png");

  TL -> addTexture("Assets/e2.png");
  GLuint e2Tex = TL -> getTexture("Assets/e2.png");

  TL -> addTexture("Assets/Wall.png");
  GLuint e3Tex = TL -> getTexture("Assets/Wall.png");

  //tx = TL -> getTexture(path);
  //tx2 = TL -> getTexture("Assets/effect6.png");
  //AudioEngine::playSound(Sounds::COOL_FLAC);
  //AudioEngine::playSound(Sounds::COOL_MP3, 1.0f);
  //GLUtils::loadTexture("img.png");

  //rect1 = new ShapeRectangle(Point(0, 0), 100, 100);
  //rect2 = new ShapeRectangle(Point(200, 200), 100, 100);
  
  //rect1 -> setTexture(tx);
  //rect2 -> setTexture(tx2);

  //sA = new ScaleAnimation();
  //sA -> setScale(1, 1.0f/3.0f, 1, 1.0f/3.0f);
  //sA -> setDuration(1000);
  //sA -> setFillAfter(false);

  //rect1 -> addAndStartAnimation(sA);
  

  //AS = new AnimatedSprite(200, 200, 100, 100, e3Tex, 1000, 1, 1, false);

  //AS -> addEffectAnimation(200, 200, 100, 100, e1Tex, 3000, 7, 7, false);
  //AS -> addEffectAnimation(200, 200, 100, 100, e2Tex, 4000, 4, 5, false);
  //AS -> start();
  x = y = 0;
  AS2 = new AnimatedSprite(&x, &y, &width, &height, 0, 3000, 1, 1, false);
  AS2 -> addEffectAnimation(&x, &y, &width, &height, e1Tex, 3000, 7, 7, true);

  LoadSampleLevel(e3Tex);
  //AS2 -> start();
}

void LoadSampleLevel(GLuint texture){
  ifstream fin ("Assets/LevelTextMap/Level1.txt");

  char x;
  int N, M, i, j;

  fin >> N >> M;
  for(i=0;i<N;++i)
  {
      for(j=0;j<M;++j)
      {
          fin >> x;
          if(x == 'x') // add a wall texture
          {
            walls.push_back(
              new AnimatedSprite(j * 100, i * 100, 100, 100, texture, 1000, 1, 1, false)
              );
          }
      }
  }
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
            handleKeys();

    	      //User requests quit
    	      if( e.type == SDL_QUIT )
            {
        		  quit = true;
        		}
    	      //Handle keypress with current mouse position
    	      else 
              if( e.type == SDL_KEYDOWN )
              {
                  Input::keyDown(e.key.keysym.sym);
              }
              else
              if( e.type == SDL_KEYUP )
              {
                  Input::keyUp(e.key.keysym.sym);
              }
              else                        
              if( e.type == SDL_TEXTINPUT )
        		  {
                  int x = 0, y = 0;
                  SDL_GetMouseState( &x, &y );
                  //Input::handleInput(e.text.text[ 0 ], x, y)
                   
                  //Input::keyDown(e.text.text[ 0 ]);      		    
        					//handleKeys( e.text.text[ 0 ], x, y );
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
