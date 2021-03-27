#pragma once

#ifndef __WINDOW_CALLBACK_HPP__
#define __WINDOW_CALLBACK_HPP__

#include "pch/glfw_pch.hpp"

namespace callback_window
{
	void process_input(GLFWwindow *window_reference);
	void framebuffer_size_callback(GLFWwindow *window_reference, int width, int height);	
} // namespace callback_window


#endif // __WINDOW_CALLBACK_HPP__