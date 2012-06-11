#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <string>

namespace app {

class Settings {
private:
	Settings();
	static Settings* instance;

	std::string resources;
	std::string shaders;
	std::string models;
	std::string textures;
public:

	void setResourcePath(std::string path);
	std::string getResourcePath();
	void setShaderPath(std::string path);
	std::string getShaderPath();
	void setModelPath(std::string path);
	std::string getModelPath();
	void setTexturePath(std::string path);
	std::string getTexturePath();
	static Settings* inst();
	virtual ~Settings();

};

}
#endif
