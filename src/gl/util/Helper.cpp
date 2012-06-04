#include "Helper.h"

namespace gl {
namespace util {

void printShaderOrProgramLog(GLuint object) {
	GLint logLength = 0;
	if (glIsShader(object)) {
		glGetShaderiv(object, GL_INFO_LOG_LENGTH, &logLength);
	} else if (glIsProgram(object)) {
		glGetProgramiv(object, GL_INFO_LOG_LENGTH, &logLength);
	} else {
		LOG_ERROR("Given object isn't a shader or a program");
	}

	char* log = new char[logLength];
	if (glIsShader(object)) {
		glGetShaderInfoLog(object, logLength, NULL, log);
	} else if (glIsProgram(object)) {
		glGetProgramInfoLog(object, logLength, NULL, log);
	}

	LOG_ERROR("Compile error " + string(log));
	delete [] log;
	return;
}

}
}
