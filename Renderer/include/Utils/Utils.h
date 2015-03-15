#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <iostream>

template <typename Cons>
std::string toString(const Cons& t)
{
	std::ostringstream os;
	os << t;
	std::string s(os.str());
	return s;
}

#endif // UTILS_H
