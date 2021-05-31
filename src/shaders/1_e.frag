// Binarização clear
#version 450 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image;
uniform int limit;
void main()
{
	color = texture(image, TexCoords);
  float average = color.r * 0.2125 + color.g * 0.7154 + color.b * 0.0721;
  color.r = average;
  color.g = average;
  color.b = average;
  float normal_limit = limit / 255.0;
  if(average < normal_limit) color = vec4(0.0, 0.0, 0.0, color.a);
  else color = vec4(1.0, 1.0, 1.0, color.a);
}