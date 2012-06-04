#include "Model.h"
#include "../manager/Shader.h"
#include "../gl/ShaderProgram.h"

namespace model {

Model::Model() {
	// TODO Auto-generated constructor stub

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
	for (int i = 0; i < (int)this->meshes.size(); i++) {
		this->meshes.at(i)->draw();
	}
}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

}
