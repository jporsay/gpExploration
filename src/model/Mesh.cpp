#include "Mesh.h"
#include "../gl/util/Helper.h"

namespace model {

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

void Mesh::addFace(GLuint a, GLuint b, GLuint c) {
	face f = { a, b, c };
	this->faces.push_back(f);
}

std::vector<face> Mesh::getFaces() {
	return this->faces;
}

void Mesh::addMapCoord(float u, float v) {
	mapCoord mc = { u, v };
	this->mapCoords.push_back(mc);
}

std::vector<mapCoord> Mesh::getMapCoords() {
	return this->mapCoords;
}

void Mesh::upload() {
//	glGenVertexArrays(1, &this->vao);
//	glBindVertexArray(this->vao);
	if (this->vertexes.size() > 0) {
		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(GL_ARRAY_BUFFER, this->vertexes.size() * sizeof(vertex), this->vertexes.data(), GL_STATIC_DRAW);
	}
	if (this->faces.size() > 0) {
		glGenBuffers(1, &this->ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->faces.size() * sizeof(face), this->faces.data(), GL_STATIC_DRAW);
	}
//	glBindVertexArray(0);
}

void Mesh::draw() {
//	glBindVertexArray(this->vao);
	if (this->ibo != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glEnableVertexAttribArray(gl::util::GL_ATTRIB_VERTEX);
		glVertexAttribPointer(gl::util::GL_ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, 0, 0);
		GLint size;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
		glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
		LOG_INFO("Size: " + utilities::toString(size / sizeof(GLushort)));
		glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
	}
}

unsigned int Mesh::getVertexCount() {
	return this->vertexes.size();
}

Mesh::~Mesh() {
	// TODO Auto-generated destructor stub
}

}
