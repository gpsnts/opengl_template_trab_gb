#version 460 core
layout(location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 projection;

void main ()
{
	mat4 mat_mult = projection * model;
	gl_Position = mat_mult * vec4(aPos, 1.0);
}