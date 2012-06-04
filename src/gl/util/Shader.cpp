#include "Shader.h"

namespace gl {
namespace util {

Shader::Shader() {
	// TODO Auto-generated constructor stub

}


GLuint Shader::create(GLenum type, std::string fileName) {
	std::string fileContents = utilities::readFile(fileName);
	const GLchar* source = fileContents.c_str();
	if (source == NULL) {
		LOG_ERROR("Error reading shader: " + fileName);
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

Shader::~Shader() {
	// TODO Auto-generated destructor stub
}

}
}
