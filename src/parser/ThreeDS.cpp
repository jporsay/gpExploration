#include "ThreeDS.h"

namespace parser {

ThreeDS::ThreeDS() {
	// TODO Auto-generated constructor stub

}

model::Model* ThreeDS::parse() {
	unsigned short chunkId;
	unsigned int chunkLength;
	model::Model* obj = 0;
	model::Mesh* mesh = 0;
	std::ifstream file (this->file.c_str(), std::ios::in | std::ios::binary);

	while (file.good()) {
		file.read((char*)&chunkId, sizeof(unsigned short));
		file.read((char*)&chunkLength, sizeof(unsigned int));
		switch (chunkId) {
		case MAIN3DS:
			break;
		case EDITOR3DS:
			break;
		case EDIT_OBJECT:
			obj = new model::Model();
			this->readName(&file, obj);
			break;
		case OBJECT_TRIMESH:
			mesh = new model::Mesh();
			obj->addMesh(mesh);
			break;
		case TRI_VERTEXL:
			this->readVertexes(&file, mesh);
			break;
		case TRI_FACEL1:
			this->readFaces(&file, mesh);
			break;
		case TRI_MAPPINGCOORS:
			this->readMappingCoordinates(&file, mesh);
			break;
		default:
			file.seekg(chunkLength - 6, std::ios_base::cur);
			break;
		}
	}
	file.close();
	return obj;
}

ThreeDS::~ThreeDS() {
	// TODO Auto-generated destructor stub
}

void ThreeDS::readName(std::ifstream* stream, model::Model* obj) {
	char name[MAX_NAME_LENGTH];
	char* curChar = name;
	int i = 0;
	do {
		stream->read(curChar, 1);
		i++;
	} while (*(curChar++) != '\0' && i < MAX_NAME_LENGTH);
	obj->setName(std::string(name));
	return;
}

void ThreeDS::readVertexes(std::ifstream* stream, model::Mesh* mesh) {
	unsigned short amount;
	stream->read((char*)&amount, sizeof(unsigned short));
	float vertex[3];
	for (int i = 0; i < amount; i++) {
		stream->read((char*)vertex, sizeof(float) * 3);
		mesh->addVertex(vertex[0], vertex[1], vertex[2]);
	}
	return;
}

void ThreeDS::readFaces(std::ifstream* stream, model::Mesh* mesh) {
	unsigned short amount;
	unsigned short face_flags; // Unused but necessarily parsed
	stream->read((char*)&amount, sizeof(unsigned short));
	unsigned short face[3];
	for (int i = 0; i < amount; i++) {
		stream->read((char*)face, sizeof(unsigned short) * 3);
		stream->read((char*)&face_flags, sizeof(unsigned short));
		mesh->addFace(face[0], face[1], face[2]);
	}
	return;
}

void ThreeDS::readMappingCoordinates(std::ifstream* stream, model::Mesh* mesh) {
	unsigned short amount;
	stream->read((char*)&amount, sizeof(unsigned short));
	float mapCoordinate[2];
	stream->read((char*)mapCoordinate, sizeof(float) * 2);
	mesh->addMapCoord(mapCoordinate[0], mapCoordinate[1]);
	return;
}

}
