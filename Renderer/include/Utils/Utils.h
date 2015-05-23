/**
    Utils.h
    Purpose: Implements basic utilities.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <iostream>

/**
	Convert any object into a string.

    @param t the object to convert to string
    @return the object as a string
*/
template <typename Cons>
std::string toString(const Cons& t)
{
	std::ostringstream os;
	os << t;
	std::string s(os.str());
	return s;
}

#endif // UTILS_H
