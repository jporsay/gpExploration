#ifndef MANAGER_CAMERAMANAGER_H
#define MANAGER_CAMERAMANAGER_H

#include <string>
#include <map>
#include "../world/Camera.h"

namespace manager {

class Camera {
protected:
	Camera();
	static Camera* instance;
	std::map<std::string, world::Camera*> cameras;
public:
	static Camera* inst();
	void add(world::Camera* camera, std::string name);
	world::Camera* get(std::string name);
	virtual ~Camera();
};

}
#endif
