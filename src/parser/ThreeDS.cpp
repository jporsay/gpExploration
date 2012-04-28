#include "ThreeDS.h"

namespace parser {

ThreeDS::ThreeDS() {
	// TODO Auto-generated constructor stub

}

object::Object* ThreeDS::parse() {
	unsigned short chunkId;
	unsigned int chunkLength;
	object::Object* obj = 0;
	object::Mesh* mesh = 0;
	std::ifstream file (this->file.c_str(), std::ios::in | std::ios::binary);
	while (file.good()) {
		file.read((char*)&chunkId, sizeof(unsigned short));
		file.read((char*)&chunkLength, sizeof(unsigned int));
		switch (chunkId) {
		case MAIN_CHUNK:
		case EDITOR_CHUNK:
			break;
		case OBJECT_BLOCK:
			obj = new object::Object();
			this->readName(&file, obj);
			break;
		case TRIANGULAR_MESH:
			mesh = new object::Mesh();
			obj->addMesh(mesh);
			break;
		case VERTEX_LIST:
			this->readVertexes(&file, mesh);
			break;
		case FACE_DESCRIPTION:
			this->readFaces(&file, mesh);
			break;
		case MAPPING_COORDINATE_LIST:
			this->readMappingCoordinates(&file, mesh);
			break;
		default:
			file.seekg(chunkLength - (sizeof(unsigned short) + sizeof(unsigned int)));
			break;
		}
	}
	file.close();
	return true;
}

ThreeDS::~ThreeDS() {
	// TODO Auto-generated destructor stub
}

void ThreeDS::readName(std::ifstream* stream, object::Object* obj) {
	char name[MAX_NAME_LENGTH];
	char* curChar = name;
	int i;
	do {
		stream->read(curChar, 1);
		curChar++; i++;
	} while (*curChar != '\0' && i < MAX_NAME_LENGTH);
	obj->setName(std::string(name));
	Logger::inst()->logInfo("Found object: " + obj->getName());
	return;
}

void ThreeDS::readVertexes(std::ifstream* stream, object::Mesh* mesh) {
	unsigned short amount;
	stream->read((char*)&amount, sizeof(unsigned char));
	Logger::inst()->logInfo("Read " + utilities::toString(amount) + " vertexes.");
	float vertex[3];
	for (int i = 0; i < amount; i++) {
		stream->read((char*)vertex, sizeof(float) * 3);
		mesh->addVertex(vertex[0], vertex[1], vertex[2]);
	}
	return;
}

void ThreeDS::readFaces(std::ifstream* stream, object::Mesh* mesh) {
	unsigned short amount;
	unsigned short face_flags; // Unused but necessarily parsed
	stream->read((char*)&amount, sizeof(unsigned char));
	Logger::inst()->logInfo("Read " + utilities::toString(amount) + " faces.");
	unsigned short face[3];
	for (int i = 0; i < amount; i++) {
		stream->read((char*)face, sizeof(unsigned short) * 3);
		stream->read((char*)&face_flags, sizeof(unsigned short));
		mesh->addFace(face[0], face[1], face[2]);
	}
	return;
}

void ThreeDS::readMappingCoordinates(std::ifstream* stream, object::Mesh* mesh) {
}

}
