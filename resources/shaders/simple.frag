#version 330

out vec4 color;
in vec2 texCoord_f;
uniform sampler2D tex_0;

struct material {
	vec3 ambientColor;
	vec3 diffuseColor;
	vec3 specularColor;
};

uniform material materialProperties;

void main(void) {
	//color = texture2D(tex_0, texCoord_f);
	//color = vec4(materialProperties.diffuseColor, 1.0);
	color = vec4(0.5, 0.5, 0.5, 1.0);
}