#version 330

in vec3 vert;
uniform mat4 vp;

void main(void) {
	vec4 position = vp * vec4(vert, 1.0);
	gl_Position = position;
}