#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>

namespace app {

class Settings {
private:
	Settings();
	static Settings* instance;

	std::string resources;
	std::string shaders;
	std::string models;
public:

	void setResourcePath(std::string path);
	std::string getResourcePath();
	void setShaderPath(std::string path);
	std::string getShaderPath();
	void setModelPath(std::string path);
	std::string getModelPath();
	static Settings* inst();
	virtual ~Settings();

};

}
#endif
