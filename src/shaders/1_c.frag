// Colorização
#version 450 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image;
uniform vec3 spriteColor;
void main()
{
	color = texture(image, TexCoords);
  color = color + vec4(spriteColor, 0.0);
}