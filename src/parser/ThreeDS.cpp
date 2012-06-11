#include "ThreeDS.h"
#include "../model/MeshStructs.h"
namespace parser {

ThreeDS::ThreeDS() {
	// TODO Auto-generated constructor stub

}

model::Model* ThreeDS::parse() {
	model::Model* obj;
	this->model = lib3ds_file_open(this->file.c_str());
	if (!this->model) {
		LOG_ERROR("Error parsing model!");
		return 0;
	}
	obj = new model::Model();
	for (int i = 0; i < this->model->nmeshes; ++i) {
		obj->addMesh(this->processMesh(this->model->meshes[i]));
	}
	for (int i = 0; i < this->model->nmaterials; ++i) {
		obj->addMaterial(this->processMaterial(this->model->materials[i]));
	}
	return obj;
}

material ThreeDS::processMaterial(Lib3dsMaterial* mat) {
	material m;
	vec3d a = { mat->ambient[0], mat->ambient[1], mat->ambient[2] },
		d = { mat->diffuse[0], mat->diffuse[1], mat->diffuse[2] },
		s = { mat->specular[0], mat->specular[1], mat->specular[2] };
	m.ambient = a;
	m.diffuse = d;
	m.specular = s;
	m.self_illum_flag = mat->self_illum_flag == 1;
	m.self_illum = mat->self_illum;
	m.shininess = mat->shininess;
	m.shininess_strength = mat->shin_strength;
	m.textureFile = mat->texture1_map.name;
	return m;
}

model::Mesh* ThreeDS::processMesh(Lib3dsMesh* mesh) {
	model::Mesh* out = new model::Mesh();
	out->setName(mesh->name);
//	float normals[mesh->nvertices][3];
//	lib3ds_mesh_calculate_vertex_normals(mesh, normals);
	LOG_INFO("Mesh with " + utilities::toString(mesh->nvertices) + " vertexes");
	for (int i = 0; i < mesh->nvertices; ++i) {
		out->addVertex(mesh->vertices[i][0], mesh->vertices[i][1], mesh->vertices[i][2]);
//		out->addNormal(normals[i][0], normals[i][1], normals[i][2]);
		if (mesh->texcos) {
			out->addTexCoord(mesh->texcos[i][0], mesh->texcos[i][1]);
		}
	}
	for (int j = 0; j < mesh->nfaces; ++j) {
		out->addFace(mesh->faces[j].index[0], mesh->faces[j].index[1], mesh->faces[j].index[2], mesh->faces[j].material);
	}
	return out;
}

ThreeDS::~ThreeDS() {
	// TODO Auto-generated destructor stub
}

}
