#pragma once

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#define MAX_SHADER_FILE_LENGTH 262144

#include <string.h>
#include <stdio.h>
#include <iostream>

#include "pch/glfw_pch.hpp"
#include "pch/glad_pch.hpp"

using namespace std;

extern "C"
{
	bool shader_compile(const char *file_name, GLuint *shader, GLenum type);
}

bool create_program(GLuint *program, GLuint vertex_shader, GLuint fragment_shader);

#endif // __UTILS_HPP__