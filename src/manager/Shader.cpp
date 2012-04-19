#include "Shader.h"

namespace manager {

Shader* Shader::instance = NULL;

Shader::Shader() {
	this->vertexExtension = "vert";
	this->fragmentExtension = "frag";
}

Shader* Shader::inst() {
	if (Shader::instance == NULL) {
		Shader::instance = new Shader();
	}
	return Shader::instance;
}

void Shader::setPath(std::string path) {
	const char lastChar = path.at(path.size() - 1);
	if (lastChar != '/') {
		path += "/";
	}
	this->path = path;
}

bool Shader::loadShaders() {
	std::ifstream ifs(this->path.append("shaders").c_str());
	std::string shader;

	while (getline(ifs, shader)) {
		if (!this->loadShader(this->path + shader)) {
			return false;
		}
	}
	ifs.close();
	return true;
}

bool Shader::loadShader(std::string shader) {
	std::string vert, frag;
	vert = utilities::readFile(shader + "." + this->vertexExtension);
	frag = utilities::readFile(shader + "." + this->fragmentExtension);
	// compile shaders and add them to map
	return true;
}

Shader::~Shader() {

}

}
