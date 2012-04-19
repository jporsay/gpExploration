#ifndef SHADERPROGRAM_H_
#define SHADERPROGRAM_H_

#include <map>
#include <string>
#include <vector>
#include <GL/glew.h>
#include "../util/Logger.h"
#include "util/Shader.h"

namespace gl {

using namespace std;

class ShaderProgram {
private:
	GLuint program;
	vector<GLuint> vertexShader;
	vector<GLuint> fragmentShader;
	map<string, GLint> attribute;
	map<string, GLint> uniform;

public:
	ShaderProgram();
	virtual ~ShaderProgram();
	void addVertexShader(string shader);
	void addFragmentShader(string shader);
	bool bindUniform(string name);
	GLint getUniform(string name);
	bool bindAttribute(string name);
	GLint getAttribute(string name);
	GLuint get();
	bool build();
};

}
#endif
