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
	std::string file(this->path + "shaders");
	std::ifstream ifs(file.c_str());
	std::string shader;

	while (getline(ifs, shader)) {
		if (!this->loadShader(shader)) {
			ifs.close();
			LOG_ERROR("Error loading shader: " + shader);
			return false;
		}
	}
	ifs.close();
	return true;
}

bool Shader::loadShader(std::string shader) {
	std::string vert, frag;
	vert = this->path + shader + "." + this->vertexExtension;
	frag = this->path + shader + "." + this->fragmentExtension;
	gl::ShaderProgram* program = new gl::ShaderProgram();
	if (!program->addVertexShader(vert)) {
		LOG_ERROR("Error adding vertex shader");
		return false;
	}
	if (!program->addFragmentShader(frag)) {
		LOG_ERROR("Error adding fragment shader");
		return false;
	}
	this->programs.insert(std::pair<std::string, gl::ShaderProgram*>(shader, program));
	return true;
}

bool Shader::compile(std::string shader) {
	std::map<std::string, gl::ShaderProgram*>::iterator it = this->programs.find(shader);
	if (it != this->programs.end()) {
		return it->second->compile();
	}
	LOG_INFO("Shader not found");
	return true;
}

gl::ShaderProgram* Shader::getProgram(std::string shader) {
	return this->programs.find(shader)->second;
}

Shader::~Shader() {

}

}
