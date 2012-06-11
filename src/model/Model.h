#ifndef OBJECT_H_
#define OBJECT_H_

#include <vector>
#include <string>
#include "../glm/glm.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "Mesh.h"

namespace model {
class Mesh;
class Model {
private:
	std::vector<Mesh*> meshes;
	std::string name;
	std::vector<material> materials;
	glm::mat4 modelToWorld;
public:
	void setName(std::string name);
	std::string getName();
	void addMesh(Mesh*);
	void addMaterial(material mat);
	material getMaterial(int i);
	std::vector<material> getMaterials();
	void upload();
	void draw();
	unsigned int getVertexCount();
	Model();
	virtual ~Model();
};

}
#endif
