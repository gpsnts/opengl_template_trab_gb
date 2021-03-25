#pragma once

#ifndef __UTILS_H__
#define __UTILS_H__

#define MAX_SHADER_FILE_LENGTH 262144

#include <stdio.h>

#include "pch/opengl_libs.hpp"

extern "C"
{
	bool shader_compile(const char *file_name, GLuint *shader, GLenum type);
}

bool shader_assign(char *shader_content, GLuint *shader, GLenum type);

bool create_program(GLuint frag_shader, GLuint vert_shader, GLuint *program);

#endif // __UTILS_H__