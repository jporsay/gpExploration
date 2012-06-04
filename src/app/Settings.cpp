#include "Settings.h"

namespace app {

Settings* Settings::instance = 0;

Settings::Settings() {
	// TODO Auto-generated constructor stub

}

Settings* Settings::inst() {
	if (instance == 0) {
		instance = new Settings();
	}
	return instance;
}

void Settings::setResourcePath(std::string path) {
	this->resources = path;
}

std::string Settings::getResourcePath() {
	return this->resources;
}

void Settings::setShaderPath(std::string path) {
	this->shaders = path;
}

std::string Settings::getShaderPath() {
	return this->shaders;
}

void Settings::setModelPath(std::string path) {
	this->models = path;
}

std::string Settings::getModelPath() {
	return this->models;
}

Settings::~Settings() {
	// TODO Auto-generated destructor stub
}

}
