#ifndef OBJECT_H_
#define OBJECT_H_

#include "Mesh.h"
#include <vector>
#include <string>
#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"

namespace model {

class Model {
private:
	std::vector<Mesh*> meshes;
	std::string name;
	glm::mat4 modelToWorld;
public:
	void setName(std::string name);
	std::string getName();
	void addMesh(Mesh*);
	void upload();
	void draw();
	Model();
	virtual ~Model();
};

}
#endif
