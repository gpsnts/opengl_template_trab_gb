#version 450 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image;
uniform vec3 spriteColor;
void main()
{
	vec4 TexColor = vec4(spriteColor, 0.) * texture(image, TexCoords);
	color = TexColor;
}