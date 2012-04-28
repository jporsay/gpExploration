#ifndef OBJECT_H_
#define OBJECT_H_

#include "Mesh.h"
#include <vector>
#include <string>

namespace object {

class Object {
private:
	std::vector<Mesh*> meshes;
	std::string name;
public:
	void setName(std::string name);
	std::string getName();
	void addMesh(Mesh*);
	Object();
	virtual ~Object();
};

}
#endif
