#ifndef MESH_H_
#define MESH_H_

#include "MeshStructs.h"
#include <vector>

namespace object {

class Mesh {
private:
	std::vector<vertex> vertexes;
	std::vector<face> faces;
	std::vector<mapCoord> mapCoords;
public:
	Mesh();
	void addVertex(float x, float y, float z);
	void addFace(float a, float b, float c);
	void addMapCoord(float u, float v);
	std::vector<vertex> getVertexes();
	std::vector<face> getFaces();
	std::vector<mapCoord> getMapCoords();

	virtual ~Mesh();
};

}
#endif
