#include "Model.h"
#include "../manager/Shader.h"
#include "../manager/CameraManager.h"
#include "../gl/ShaderProgram.h"
namespace model {

Model::Model() {
	this->modelToWorld = glm::mat4(1.0);

}

void Model::setName(std::string name) {
	this->name = name;
}

std::string Model::getName() {
	return this->name;
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
	gl::ShaderProgram* program = manager::Shader::inst()->getProgram("simple");
	glUseProgram(program->get());
	GLuint uMVP = glGetUniformLocation(program->get(), "mvp");
	glm::mat4 mvp = manager::Camera::inst()->get("world")->cameraToScreen() * manager::Camera::inst()->get("world")->worldToCamera() * this->modelToWorld;
	glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(mvp));
	for (int i = 0; i < (int)this->meshes.size(); i++) {
		this->meshes.at(i)->draw();
	}
}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

}
