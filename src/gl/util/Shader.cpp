#include "Shader.h"

namespace gl {
namespace util {

Shader::Shader() {
	// TODO Auto-generated constructor stub

}


GLuint Shader::create(GLenum type, std::string fileName) {
	const GLchar* source = utilities::readFile(fileName).c_str();

	if (source == NULL) {
		Logger::inst()->logError("Error reading shader: " + fileName);
		return 0;
	}

	GLuint resource = glCreateShader(type);
	glShaderSource(resource, 1, &source, NULL);
	glCompileShader(resource);

	GLint compileOk;
	glGetShaderiv(resource, GL_COMPILE_STATUS, &compileOk);
	if (compileOk == GL_FALSE) {
		printShaderOrProgramLog(resource);
		return 0;
	}
	return resource;

}

bool Shader::link(GLuint program) {
	GLint linkOk;
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linkOk);
	if (linkOk == GL_FALSE) {
		printShaderOrProgramLog(program);
		return false;
	}
	return true;
}

Shader::~Shader() {
	// TODO Auto-generated destructor stub
}

}
}
