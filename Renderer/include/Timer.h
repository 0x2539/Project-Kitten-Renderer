#ifndef TIMER_H
#define TIMER_H

/* 
	The Usage of Timer class

Actually, it ticks every 10 milliseconds
and for every tick he call te GameLoopTimer function
where we increment _ticks variable

So, real time from the start of the game is  _ticks * _timerFireRate

When we want to count how many millisecond passed between two time events, one should use the following

1) int Time1 = Timer::getTime(); // we take how many second passed since the beginning of the game
	// here we do stuff
	// ...
	// some time passed
	int Time2 = Timer::getTime();

	print : (Time2 - Time1) milliseconds have passed between

or
2) int Time1 = Timer::getTime(); // we take how many second passed since the beginning of the game
	// here we do stuff
	// ...
	// some time passed
	print : Timer::getDeltaTime(Time1) // which returns number of millisecond between current time and Time1
*/

#include "SDL2/SDL.h"
#include "Logger.h"

class Timer{
private:
	static SDL_TimerID _timer_id;
	static const int _timerFireRate;
	static int _ticks;

public:

	static int getTime(){
		return _ticks * _timerFireRate;
	}

	static int getDeltaTime(int milliseconds){
		return _ticks * _timerFireRate - milliseconds;
	}

	static Uint32 GameLoopTimer(Uint32 interval, void* param)
	{
		// Create a user event to call the game loop.
	    SDL_Event event;
	    
	    event.type = SDL_USEREVENT;
	    event.user.code = 1;
	    event.user.data1 = 0;
	    event.user.data2 = 0;
	    
	    ++ _ticks;

	    SDL_PushEvent(&event);

	    return interval;
	}
};

int Timer::_ticks = 0;
const int Timer::_timerFireRate = 10;
SDL_TimerID Timer::_timer_id = SDL_AddTimer(Timer::_timerFireRate, GameLoopTimer, 0);

#endif // TIMER_H