// Inversão
#version 450 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image;
void main()
{
	vec4 texture_color = texture2D(image, TexCoords);
	color = vec4(1.0 - texture_color.r, 1.0 - texture_color.g, 1.0 - texture_color.b, 1.0 - texture_color.a);
}