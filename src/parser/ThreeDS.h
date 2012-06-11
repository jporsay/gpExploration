#ifndef THREEDS_H_
#define THREEDS_H_

#include <fstream>
#include <ios>
#include <lib3ds.h>

#include "Parser.h"
#include "../model/Model.h"
#include "../model/Mesh.h"
#include "../util/Logger.h"
#include "../util/string.h"

namespace parser {

class ThreeDS: public parser::Parser {
private:
	Lib3dsFile* model;
	model::Mesh* processMesh(Lib3dsMesh* mesh);
	material processMaterial(Lib3dsMaterial* material);
public:
	ThreeDS();
	model::Model* parse();
	virtual ~ThreeDS();
};

}
#endif
