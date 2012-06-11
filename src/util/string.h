
#ifndef UTIL_STRING_H
#define UTIL_STRING_H

#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <algorithm>

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

inline std::string toLower(const std::string text) {
	std::string lText(text);
	std::transform(lText.begin(), lText.end(), lText.begin(), ::tolower);
	return lText;
}

}

#endif
