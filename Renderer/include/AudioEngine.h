/**
    AudioEngine.h
    Purpose: Manages the audio of the engine.

    @author Ion Ureche
    @version 1.0
*/
#ifndef AUDIO_ENGINE_H
#define AUDIO_ENGINE_H

#include <irrKlang.h>
#include <string>
#include "Logger.h"
#include "Sounds.h"

using namespace irrklang;

class AudioEngine{

private:
	//The sound engine
	static ISoundEngine* engine;

public:

    /**
        Play a sound.

        @param path the path of the sound to play
        @param defaultVolume the volume of the sound
        @return
    */
	static void playSound(const string path, float defaulVolume = 1.0f){

		if(!engine) engine = createIrrKlangDevice();
		
		ISoundSource* soundtrack = engine->addSoundSourceFromFile(path.c_str());
		soundtrack -> setDefaultVolume(defaulVolume);

		if (!engine)
		{
			Logger::write("Could not startup engine\n"); 
			return ;
		}
		
		engine->play2D(soundtrack);
	}

    /**
        Stop all the sounds.

        @param
        @return
    */
	static void stopAllSounds(){

		if (!engine)
		{
			Logger::write("Could not startup engine\n"); 
			return ;
		}

		engine -> stopAllSounds();
	}

};

ISoundEngine* AudioEngine::engine = NULL;

#endif // AUDIO_ENGINE_H