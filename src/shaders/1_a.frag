// Apenas canais selecionados
#version 450 core
//in vec3 iColor;
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image;
uniform int code;
void main()
{
	color = texture(image, TexCoords);
  if (code == 1) 			color = vec4(color.r, color.r, color.r, 0.0);
	else if (code == 2) color = vec4(color.g, color.g, color.g, 0.0);
	else if (code == 3) color = vec4(color.b, color.b, color.b, 0.0);
}