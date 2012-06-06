#include "Camera.h"
#include "../app/GraphicSettings.h"
namespace world {

Camera::Camera() {
	this->up = glm::vec3(0.0, 1.0, 0.0);
	this->position = glm::vec3(0.0, 0.0, 4.0);
	this->lookAt = glm::vec3(0.0);
}

Camera::Camera(glm::vec3 position) {
	this->up = glm::vec3(0.0, 1.0, 0.0);
	this->position = position;
	this->lookAt = glm::vec3(0.0);
}

Camera::Camera(glm::vec3 position, glm::vec3 lookDirection) {
	this->up = glm::vec3(0.0, 1.0, 0.0);
	this->position = position;
	this->lookAt = lookDirection;
}
Camera::Camera(glm::vec3 position, glm::vec3 lookDirection, glm::vec3 upDirection) {
	this->position = position;
	this->lookAt = lookDirection;
	this->up = upDirection;
}

glm::mat4 Camera::worldToCamera() {
	return glm::lookAt(this->position, this->lookAt, this->up);
}

glm::mat4 Camera::cameraToScreen() {
	return glm::perspective(45.0f, 1.0f*app::GraphicSettings::screenWidth/app::GraphicSettings::screenHeight, 0.1f, 100.0f);
}

Camera::~Camera() {

}

}
