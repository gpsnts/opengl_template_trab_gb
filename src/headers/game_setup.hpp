#ifndef GAME_HPP_
#define GAME_HPP_

#include "pch/opengl_libs.hpp"

#include <sstream>

using namespace std;

namespace GameSetup {
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void close_window_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void setup_opengl_glfw();
	void frames_per_second(GLFWwindow* window);
}

#endif // !GAME_HPP_