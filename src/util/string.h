
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


}

#endif
