// Grayscale
#version 450 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image;
void main()
{
  color = texture(image, TexCoords);
  float media = color.r * 0.2125 + color.g * 0.7154 + color.b * 0.0721;
	color.r = media;
  color.g = media;
  color.b = media;
}