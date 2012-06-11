#ifndef MESHSTRUCTS_H_
#define MESHSTRUCTS_H_

#include <GL/glew.h>
#include <string>

typedef struct {
	float x;
	float y;
	float z;
} vec3d;

typedef struct {
	vec3d ambient;
	vec3d diffuse;
	vec3d specular;
	float shininess;
	float shininess_strength;
	bool self_illum_flag;
	float self_illum;
	std::string textureFile;
} material;

typedef struct {
	GLushort v1;
	GLushort v2;
	GLushort v3;
	GLint material;
} face;

typedef struct {
	float u;
	float v;
} texCoord;

#endif
