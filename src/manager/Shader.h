#ifndef MANAGER_SHADER_H
#define MANAGER_SHADER_H

#include <fstream>
#include <string>
#include <map>
#include <GL/glew.h>
#include "../util/string.h"
#include "../gl/ShaderProgram.h"
#include "../util/Logger.h"

namespace manager {

class Shader {
private:
	static Shader* instance;
	Shader();
	std::string path;
	std::string vertexExtension;
	std::string fragmentExtension;
	std::map<std::string, gl::ShaderProgram*> programs;
public:
	static Shader* inst();
	void setExtensions(std::string vertexExtension, std::string fragmentExtension);
	void setPath(std::string path);
	bool loadShaders();
	gl::ShaderProgram* getProgram(std::string shader);
	bool compile(std::string shader);
	bool loadShader(std::string shader);
	virtual ~Shader();
};

}
#endif
