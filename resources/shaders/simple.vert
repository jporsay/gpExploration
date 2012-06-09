#version 330

in vec3 vert;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void) {
 	vec4 pos = projection * view * model * vec4(vert, 1.0);
	gl_Position = pos;
}