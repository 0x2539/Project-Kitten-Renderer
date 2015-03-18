# Project-Kitten-Renderer

This is how sounds should work:

```c++
#include "AudioEngine.h"
class AudioEngine
{
public:
	static void playSound(string sound_path);
	static void loadSound(string sound_path);
};

#include "Sounds.h"
{
public:
	static constant string PLAYER_DIES = "sounds/player_die.wav";
	static constant string MONSTER_DIES = "sounds/monster_die.wav";
	static constant string FINISHED_LEVEL = "sounds/finished_level.wav";
	...
}

#include "SomeGameLogicClass.h"
void checkMonsterCollision()
{
	...
	if(monster was killed by user)
	{
		AudioEngine::playSound(Sounds::MONSTER_DIES);
	}
	...
}
```
