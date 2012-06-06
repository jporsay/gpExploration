#version 330

in vec3 vert;

uniform mat4 mvp;

void main(void) {
 	vec4 pos = mvp * vec4(vert, 1.0);
	gl_Position = pos;
}