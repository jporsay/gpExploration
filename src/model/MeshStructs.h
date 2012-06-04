#ifndef MESHSTRUCTS_H_
#define MESHSTRUCTS_H_

#include <GL/glew.h>

typedef struct {
	float x;
	float y;
	float z;
} vertex;

typedef struct {
	GLuint a;
	GLuint b;
	GLuint c;
} face;

typedef struct {
	float u;
	float v;
} mapCoord;

#endif
