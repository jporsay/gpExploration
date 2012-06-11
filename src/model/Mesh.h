#ifndef MESH_H_
#define MESH_H_

#include <vector>
#include <string>
#include <GL/glew.h>
#include "MeshStructs.h"
#include "../gl/ShaderProgram.h"
#include "../manager/Texture.h"
#include "../manager/Shader.h"
#include "Texture.h"

namespace model {

class Mesh {
private:
	std::string name;
	std::vector<vec3d> vertexes;
	std::vector<vec3d> normals;
	std::vector<face> faces;
	std::vector<texCoord> texCoords;
	std::vector<material*> materials;
	GLuint textureId;
	GLuint
		vao, // Vertex Array Object
		vbo, // Vertex buffer object
		texVbo, // Texture buffer object
		ibo, // Index buffer object
		nbo; // Normal buffer object
public:
	Mesh();
	void addVertex(float x, float y, float z);
	void addNormal(float x, float y, float z);
	void addFace(GLuint v1, GLuint v2, GLuint v3, GLint material);
	void addTexCoord(float u, float v);
	void addMaterial(material* m);
	void setName(std::string name);
	std::string getName();
	std::vector<vec3d> getVertexes();
	std::vector<vec3d> getNormals();
	std::vector<face> getFaces();
	std::vector<texCoord> getTexCoords();
	void upload();
	void draw();
	unsigned int getVertexCount();
	virtual ~Mesh();
};

}
#endif
