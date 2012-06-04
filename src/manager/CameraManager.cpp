#include "CameraManager.h"

namespace manager {

Camera* Camera::instance = 0;

Camera::Camera() {
	// TODO Auto-generated constructor stub

}

Camera* Camera::inst() {
	if (instance == 0) {
		instance = new Camera();
	}
	return instance;
}

void Camera::add(world::Camera* camera, std::string name) {
	this->cameras.insert(std::pair<std::string, world::Camera*>(name, camera));
}
world::Camera* Camera::get(std::string name) {
	return this->cameras.find(name)->second;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

}
