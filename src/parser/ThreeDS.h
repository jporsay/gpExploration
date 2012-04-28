#ifndef THREEDS_H_
#define THREEDS_H_

#include <fstream>
#include <ios>

#include "Parser.h"
#include "../object/Object.h"
#include "../object/Mesh.h"
#include "../util/Logger.h"
#include "../util/string.h"

#define MAIN_CHUNK					0x4D4D
#define EDITOR_CHUNK				0x3D3D
#define OBJECT_BLOCK 				0x4000
#define TRIANGULAR_MESH 			0x4100
#define VERTEX_LIST 				0x4110
#define FACE_DESCRIPTION		 	0x4120
#define MAPPING_COORDINATE_LIST 	0x4130

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
