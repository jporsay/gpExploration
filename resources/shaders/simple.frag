#version 330

out vec4 color;
in vec2 texCoord;
uniform sampler2D tex_0;

void main(void) {
	color = texture2D(tex_0, texCoord);
}