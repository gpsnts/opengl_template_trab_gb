#pragma once

#ifndef __GL_CONFIG_HPP__
#define __GL_CONFIG_HPP__

#include <iostream>

#include "pch/glfw_pch.hpp"

using namespace std;

namespace gl_config
{
	bool init_glad();
	bool init_glfw();
	bool check_window_creation(GLFWwindow *window_refference);
	void set_opengl_version_profile();
} // namespace gl_config

#endif // __GL_CONFIG_HPP__