#ifndef SHADER_H_
#define SHADER_H_

#include <fstream>
#include <string>
#include <map>
#include <GL/glew.h>
#include "../util/string.h"
#include "../gl/ShaderProgram.h"

namespace manager {

class Shader {
private:
	static Shader* instance;
	Shader();
	std::string path;
	std::string vertexExtension;
	std::string fragmentExtension;
	std::map<std::string, GLuint> shaders;
public:
	static Shader* inst();
	void setExtensions(std::string vertexExtension, std::string fragmentExtension);
	void setPath(std::string path);
	bool loadShaders();
	bool loadShader(std::string shader);
	virtual ~Shader();
};

}
#endif
