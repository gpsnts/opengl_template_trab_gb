#pragma once

#ifndef __GL_CONFIG_HPP__
#define __GL_CONFIG_HPP__

#include <iostream>
#include <sstream>

#include "pch/glfw_pch.hpp"

using namespace std;

namespace gl_config
{
	bool init_glad();
	bool init_glfw();
	bool check_window_creation(GLFWwindow *window_reference);
	void set_opengl_version_profile();
	void frames_per_second(GLFWwindow *window_reference);
} // namespace gl_config

#endif // __GL_CONFIG_HPP__