#ifndef MESH_H_
#define MESH_H_

#include "MeshStructs.h"
#include <vector>

namespace object {

class Mesh {
private:
	std::vector<vertex> vertexes;
	std::vector<face> faces;
public:
	Mesh();
	void addVertex(float x, float y, float z);
	std::vector<vertex> getVertexes();
	void addFace(float a, float b, float c);
	std::vector<face> getFaces();
	virtual ~Mesh();
};

}
#endif
