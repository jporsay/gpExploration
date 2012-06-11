#include "Model.h"
#include "../manager/CameraManager.h"
#include "../gl/ShaderProgram.h"

namespace model {

Model::Model() {
	this->modelToWorld = glm::scale(glm::mat4(1.0f), glm::vec3(0.2));

}

void Model::setName(std::string name) {
	this->name = name;
}

std::string Model::getName() {
	return this->name;
}

void Model::addMaterial(material mat) {
	this->materials.push_back(mat);
	for (vector<Mesh*>::iterator it = this->meshes.begin(); it != this->meshes.end(); ++it) {
		(*it)->addMaterial(&mat);
	}
}

material Model::getMaterial(int i) {
	return this->materials.at(i);
}

std::vector<material> Model::getMaterials() {
	return this->materials;
}

void Model::addMesh(Mesh* mesh) {
	this->meshes.push_back(mesh);
}

void Model::upload() {
	for (int i = 0; i < (int)this->meshes.size(); i++) {
		this->meshes.at(i)->upload();
	}
}

void Model::draw() {
	this->modelToWorld = glm::rotate(this->modelToWorld, 0.033f, glm::vec3(1, 1, 0));
	gl::ShaderProgram* program = manager::Shader::inst()->getProgram("simple");
	glUseProgram(program->get());
	GLuint model, view, projection;
	model = glGetUniformLocation(program->get(), "model");
	view = glGetUniformLocation(program->get(), "view");
	projection = glGetUniformLocation(program->get(), "projection");
	glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(this->modelToWorld));
	glUniformMatrix4fv(view, 1, GL_FALSE, glm::value_ptr(manager::Camera::inst()->get("world")->worldToCamera()));
	glUniformMatrix4fv(projection, 1, GL_FALSE, glm::value_ptr(manager::Camera::inst()->get("world")->cameraToScreen()));
	for (int i = 0; i < (int)this->meshes.size(); i++) {
		this->meshes.at(i)->draw();
	}
}

unsigned int Model::getVertexCount() {
	unsigned int vertexCount = 0;
	for (int i = 0; i < (int)this->meshes.size(); i++) {
		vertexCount += this->meshes.at(i)->getVertexCount();
	}
	return vertexCount;
}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

}
