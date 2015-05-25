/**
    Logger.h
    Purpose: Manages a basic logging system.

    @author Ion Ureche
    @version 1.0
*/
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

    /**
        Writes a message to output.

        @param message the message to print
        @return
    */
	static void write(string message){
		cout << message << '\n';
	}

    /**
        Writes a message to output.

        @param message the message to print
        @return
    */
	static void write(const unsigned char* message){
		cout << message << '\n';
	}

    /**
        Writes a message to output.

        @param message the message to print
        @return
    */
	static void write(const char* message){
		cout << message << '\n';
	}

    /**
        Writes a message to output.

        @param message the message to print
        @return
    */
	static void write(char* message){
		cout << message << '\n';
	}

    /**
        Writes a message to output.

        @param message the message to print
        @return
    */
	static void write(int value){
		cout << value << '\n';
	}
};

#endif // LOGGER_H