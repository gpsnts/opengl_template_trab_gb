#pragma once

#ifndef __SHADER_WRAPPER_HPP__
#define __SHADER_WRAPPER_HPP__

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

#endif // __SHADER_WRAPPER_HPP__