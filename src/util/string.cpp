#include <string>
#include <fstream>
#include <streambuf>

namespace util {

std::string readFile(std::string fileName) {
	std::ifstream t(fileName.c_str());
	std::string ret((std::istreambuf_iterator<char>(t)),
            std::istreambuf_iterator<char>());
	t.close();
	return ret;
}

}
