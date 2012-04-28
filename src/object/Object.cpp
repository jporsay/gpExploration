#include "Object.h"

namespace object {

Object::Object() {
	// TODO Auto-generated constructor stub

}

void Object::setName(std::string name) {
	this->name = name;
}

std::string Object::getName() {
	return this->name;
}

void Object::addMesh(Mesh* mesh) {
	this->meshes.push_back(mesh);
}

Object::~Object() {
	// TODO Auto-generated destructor stub
}

}
