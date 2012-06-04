#ifndef OBJECT_H_
#define OBJECT_H_

#include "Mesh.h"
#include <vector>
#include <string>

namespace model {

class Model {
private:
	std::vector<Mesh*> meshes;
	std::string name;
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
