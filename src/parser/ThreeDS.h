#ifndef THREEDS_H_
#define THREEDS_H_

#include <fstream>
#include <ios>

#include "Parser.h"
#include "../object/Object.h"
#include "../object/Mesh.h"
#include "../util/Logger.h"
#include "../util/string.h"

#define MAIN3DS				0x4D4D
#define EDITOR3DS			0x3D3D

#define EDIT_OBJECT 		0x4000
#define OBJECT_TRIMESH 		0x4100
#define TRI_VERTEXL 		0x4110
#define TRI_FACEL1			0x4120
#define TRI_MAPPINGCOORS	0x4140

#define MAX_VERTEXES 8000
#define MAX_POLYGONS 8000
#define MAX_NAME_LENGTH 20
namespace parser {

class ThreeDS: public parser::Parser {
private:
	void readName(std::ifstream* stream, object::Object* obj);
	void readVertexes(std::ifstream* stream, object::Mesh* mesh);
	void readFaces(std::ifstream* stream, object::Mesh* mesh);
	void readMappingCoordinates(std::ifstream* stream, object::Mesh* mesh);
public:
	ThreeDS();
	object::Object* parse();
	virtual ~ThreeDS();
};

}
#endif
