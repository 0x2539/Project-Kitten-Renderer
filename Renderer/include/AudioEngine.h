#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <irrKlang.h>
#include <string>
#include "Logger.h"

using namespace irrklang;

class AudioEngine{

private:
	ISoundEngine* engine;

public:

	void doStuff(const char *path){
		engine = createIrrKlangDevice();

		if (!engine)
		{
			Logger::write("Could not startup engine\n"); 
			return ;
		}
		engine->play2D(path);
	}

};

#endif