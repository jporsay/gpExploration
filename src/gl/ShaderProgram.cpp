#include "ShaderProgram.h"

namespace gl {

ShaderProgram::ShaderProgram() {
	this->program = glCreateProgram();
}

bool ShaderProgram::addFragmentShader(string shader) {
	GLuint resource = util::Shader::create(GL_FRAGMENT_SHADER, shader);
	if (resource != 0) {
		this->fragmentShader.push_back(resource);
		return true;
	}
	return false;
}

bool ShaderProgram::addVertexShader(string shader) {
	GLuint resource = util::Shader::create(GL_VERTEX_SHADER, shader);
	if (resource != 0) {
		this->vertexShader.push_back(resource);
		return true;
	}
	return false;
}

//bool ShaderProgram::bindAttribute(string name) {
//	GLint resource;
//	resource = glGetAttribLocation(this->program, name.c_str());
//	if (resource == -1) {
//		Logger::inst()->logError("Error binding attribute" + name);
//		return false;
//	}
//	this->attribute.insert(pair<string, GLint>(name, resource));
//	return true;
//}
//
//GLint ShaderProgram::getAttribute(string name) {
//	return this->attribute.at(name);
//}
//
//bool ShaderProgram::bindUniform(string name) {
//	GLint resource;
//	resource = glGetUniformLocation(this->program, name.c_str());
//	if (resource == -1) {
//		Logger::inst()->logError("Error binding uniform" + name);
//	}
//	this->uniform.insert(pair<string, GLint>(name, resource));
//	return true;
//}
//
//GLint ShaderProgram::getUniform(string name) {
//	return this->uniform.at(name);
//}

void ShaderProgram::bindAttribLocation(string name, GLuint location) {
	glBindAttribLocation(this->program, location, name.c_str());
}

bool ShaderProgram::compile() {
	for (int i = 0; i < (int)this->vertexShader.size(); i++) {
		glAttachShader(this->program, this->vertexShader.at(i));
	}
	for (int i = 0; i < (int)this->fragmentShader.size(); i++) {
		glAttachShader(this->program, this->fragmentShader.at(i));
	}
	return true;
}

bool ShaderProgram::link() {
	GLint linkOk;
	glLinkProgram(this->program);
	glGetProgramiv(this->program, GL_LINK_STATUS, &linkOk);
	if (linkOk == GL_FALSE) {
		gl::util::printShaderOrProgramLog(this->program);
		return false;
	}
	return true;
}

GLuint ShaderProgram::get() {
	return this->program;
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(this->program);
	for (int i = 0; i < (int)this->vertexShader.size(); i++) {
		glDeleteShader(this->vertexShader.at(i));
	}
	for (int i = 0; i < (int)this->fragmentShader.size(); i++) {
		glDeleteShader(this->fragmentShader.at(i));
	}

}

}
