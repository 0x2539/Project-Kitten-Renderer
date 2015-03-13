#ifndef SOUNDS_H
#define SOUNDS_H
#include <string>
using namespace std;

class Sounds{
public:
	static const string COOL_FLAC;
	static const string COOL_MP3;
};

const string Sounds::COOL_FLAC = "libs/irrKlang/irrKlang-32bit-1.5.0/media/2.flac";
const string Sounds::COOL_MP3 = "libs/irrKlang/irrKlang-32bit-1.5.0/media/1.mp3";
//
#endif // SOUNDS_H