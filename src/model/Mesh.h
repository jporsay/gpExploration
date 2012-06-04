#ifndef MESH_H_
#define MESH_H_

#include <vector>
#include <GL/glew.h>
#include "MeshStructs.h"

namespace model {

class Mesh {
private:
	std::vector<vertex> vertexes;
	std::vector<face> faces;
	std::vector<mapCoord> mapCoords;
	GLuint
		vao, // Vertex Array Object
		vbo, // Vertex buffer object
		ibo, // Index buffer object
		nbo; // Normal buffer object
public:
	Mesh();
	void addVertex(float x, float y, float z);
	void addFace(GLuint a, GLuint b, GLuint c);
	void addMapCoord(float u, float v);
	std::vector<vertex> getVertexes();
	std::vector<face> getFaces();
	std::vector<mapCoord> getMapCoords();
	void upload();
	void draw();
	virtual ~Mesh();
};

}
#endif
