#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#define USED_GL_ENUM(type) (type == GL_FRAGMENT_SHADER ? "GL_FRAGMENT_SHADER" : "GL_VERTEX_SHADER")

#include <string.h>
#include <stdio.h>
#include <iostream>

#include "pch/glad_pch.hpp"
#include "pch/glfw_pch.hpp"

using namespace std;

class Shader
{
private:
	GLuint program;
	void compile_selected(const char *file_name, GLuint *shader, GLenum type);
public:
	void compile(
		const char *file_name_vertex,
		const char *file_name_fragment
	);

	GLuint getProgram();
};

#endif // __SHADER_HPP__