#version 460 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aCol;
out vec3 vert_Color;
void main ()
{
	vert_Color = aCol;
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
