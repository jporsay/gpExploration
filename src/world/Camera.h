#ifndef CAMERA_H_
#define CAMERA_H_

#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtc/matrix_transform.hpp"

namespace world {

class Camera {
protected:
	glm::vec3 lookAt;
	glm::vec3 position;
	glm::vec3 up;
public:
	Camera();
	Camera(glm::vec3 position);
	Camera(glm::vec3 position, glm::vec3 lookDirection);
	Camera(glm::vec3 position, glm::vec3 lookDirection, glm::vec3 upDirection);
	glm::mat4 worldToCamera();
	glm::mat4 cameraToScreen();
	virtual ~Camera();
};

}
#endif
