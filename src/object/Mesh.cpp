#include "Mesh.h"

namespace object {

Mesh::Mesh() {
	// TODO Auto-generated constructor stub

}

void Mesh::addVertex(float x, float y, float z) {
	vertex v = { x, y, z };
	this->vertexes.push_back(v);
}

std::vector<vertex> Mesh::getVertexes() {
	return this->vertexes;
}

void Mesh::addFace(float a, float b, float c) {
	face f = { a, b, c };
	this->faces.push_back(f);
}

std::vector<face> Mesh::getFaces() {
	return this->faces;
}

Mesh::~Mesh() {
	// TODO Auto-generated destructor stub
}

}
