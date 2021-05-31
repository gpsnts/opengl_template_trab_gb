// Inversão
#version 450 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image;
void main()
{
	color = texture(image, TexCoords);
	color = vec4(1.0 - color.rgb, color.a);
}