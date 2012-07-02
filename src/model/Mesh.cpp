#include "Mesh.h"
#include "../gl/util/Helper.h"
namespace model {
Mesh::Mesh() {

}

void Mesh::setName(std::string name) {
	this->name = name;
}

std::string Mesh::getName() {
	return this->name;
}

void Mesh::addVertex(float x, float y, float z) {
	vec3d v = { x, y, z };
	this->vertexes.push_back(v);
}

std::vector<vec3d> Mesh::getVertexes() {
	return this->vertexes;
}

void Mesh::addNormal(float x, float y, float z) {
	vec3d n = { x, y, z };
	this->normals.push_back(n);
}

void Mesh::addMaterial(material* m) {
	this->materials.push_back(m);
}

std::vector<vec3d> Mesh::getNormals() {
	return this->normals;
}

void Mesh::addFace(GLuint v1, GLuint v2, GLuint v3, GLint material) {
	face f = { v1, v2, v3, material };
	this->faces.push_back(f);
}

std::vector<face> Mesh::getFaces() {
	return this->faces;
}

void Mesh::addTexCoord(float u, float v) {
	texCoord mc = { u, v };
	this->texCoords.push_back(mc);
}

std::vector<texCoord> Mesh::getTexCoords() {
	return this->texCoords;
}

void Mesh::upload() {
	if (this->vertexes.size() > 0) {
		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(GL_ARRAY_BUFFER, this->vertexes.size() * sizeof(vec3d), this->vertexes.data(), GL_STATIC_DRAW);
	}
	if (this->texCoords.size() > 0) {
		glGenBuffers(1, &this->texVbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->texVbo);
		glBufferData(GL_ARRAY_BUFFER, this->texCoords.size() * sizeof(texCoord), this->texCoords.data(), GL_STATIC_DRAW);
	}
	if (this->faces.size() > 0) {
		glGenBuffers(1, &this->ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->faces.size() * sizeof(face), this->faces.data(), GL_STATIC_DRAW);
	}
	if (this->materials.size() > 0) {
		material* m = this->materials.at(0);
		Texture* t = manager::Texture::inst()->get(m->textureFile);
		if (t) {
			glGenTextures(1, &this->textureId);
			const unsigned char *pixels = t->getPixelPtr();
			glBindTexture(GL_TEXTURE_2D, this->textureId);
			glTexImage2D(GL_TEXTURE_2D,
					0,
					GL_RGBA,
					t->getWidth(),
					t->getHeight(),
					0,
					GL_RGBA,
					GL_UNSIGNED_BYTE,
					pixels
			);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		}

	}
}

void Mesh::draw(GLuint currProgram) {
	GLuint textureUniform;
	GLuint m_diffuseUniform;
	if (this->ibo != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glEnableVertexAttribArray(gl::util::GL_ATTRIB_VERTEX);
		glVertexAttribPointer(gl::util::GL_ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, 0, 0);
		if (this->texVbo) {
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, this->textureId);
			textureUniform = glGetUniformLocation(currProgram, "tex_0");
			glUniform1i(textureUniform, 0);
			glBindBuffer(GL_ARRAY_BUFFER, this->texVbo);
			glEnableVertexAttribArray(gl::util::GL_ATTRIB_TEXTURE);
			glVertexAttribPointer(gl::util::GL_ATTRIB_TEXTURE, 2, GL_FLOAT, GL_FALSE, 0, 0);
		}
		if (this->materials.size() > 0) {
			material* m = this->materials.at(0);
			m_diffuseUniform = glGetUniformLocation(currProgram, "materialProperties.diffuseColor");
//			LOG_INFO(utilities::toString(m->diffuse.x) + " " + utilities::toString(m->diffuse.y) + " " + utilities::toString(m->diffuse.z));
			glUniform3f(m_diffuseUniform, m->diffuse.x, m->diffuse.y, m->diffuse.z);
		}
		GLint size;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
		glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
		glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
	}
}

unsigned int Mesh::getVertexCount() {
	return this->vertexes.size();
}

Mesh::~Mesh() {
	if (this->textureId) {
		glDeleteTextures(1, &this->textureId);
	}
	if (this->vbo) {
		glDeleteBuffers(1, &this->vbo);
	}
	if (this->ibo) {
		glDeleteBuffers(1, &this->ibo);
	}
	if (this->texVbo) {
		glDeleteBuffers(1, &this->texVbo);
	}
}

}
