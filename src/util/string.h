
#ifndef STRING_H_
#define STRING_H_

#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

namespace utilities {

std::string readFile(std::string fileName);

template <class T>
inline std::string toString(const T& t) {
	std::stringstream ss;
	ss << t;
	return ss.str();
}

template <class T>
inline std::string toHexString(const T& t) {
	std::stringstream ss;
	ss << std::hex << t;
	return ss.str();
}


}

#endif
