/**
    Sounds.h
    Purpose: Manages basic sound system.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef SOUNDS_H
#define SOUNDS_H
#include <string>

using namespace std;

class Sounds{
public:
	static const string COOL_FLAC;
	static const string COOL_MP3;
	static const string EXPLOSION;
	static const string BELLS;
};

const string Sounds::COOL_FLAC = "libs/irrKlang/irrKlang-32bit-1.5.0/media/2.flac";
const string Sounds::COOL_MP3 = "libs/irrKlang/irrKlang-32bit-1.5.0/media/1.mp3";
const string Sounds::EXPLOSION = "libs/irrKlang/irrKlang-32bit-1.5.0/media/explosion.wav";
const string Sounds::BELLS = "libs/irrKlang/irrKlang-32bit-1.5.0/media/bell.wav";

#endif // SOUNDS_H