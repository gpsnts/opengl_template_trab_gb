#pragma once

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#define MAX_SHADER_FILE_LENGTH 262144

#include <string.h>
#include <stdio.h>

#include "pch/glfw_pch.hpp"
#include "pch/glad_pch.hpp"

extern "C"
{
	bool shader_compile(const char *file_name, GLuint *shader, GLenum type);
}

#endif // __UTILS_HPP__