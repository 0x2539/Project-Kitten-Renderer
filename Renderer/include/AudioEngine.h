#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <irrKlang.h>
#include <string>
#include "Logger.h"
#include "Sounds.h"

using namespace irrklang;

class AudioEngine{

private:
	ISoundEngine* engine;

public:

	void playSound(const char *path){
		engine = createIrrKlangDevice();

		ISoundSource* someSound = engine->addSoundSourceFromFile(path);

		// TO DO: Make SOUNDS.h LOAD ISoundSource instead of path to songs

		if (!engine)
		{
			Logger::write("Could not startup engine\n"); 
			return ;
		}
		engine->play2D(someSound);
		//Logger::write(Sounds::COOL_FLAC);
	}

};

#endif // AUDIO_ENGINE_H