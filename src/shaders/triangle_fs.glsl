#version 460 core
in vec3 vert_Color;
out vec4 color;
void main()
{
	color = vec4(vert_Color, 1.0f);
}
