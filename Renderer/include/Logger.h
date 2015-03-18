#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <string>

using namespace std;

class Logger
{
private:
	// TO DO: Logger Message history

public:

	static void write(string message){
		cout << message << '\n';
	}

	static void write(const unsigned char* message){
		cout << message << '\n';
	}

	static void write(const char* message){
		cout << message << '\n';
	}

	static void write(char* message){
		cout << message << '\n';
	}

	static void write(int value){
		cout << value << '\n';
	}
};

#endif // LOGGER_H