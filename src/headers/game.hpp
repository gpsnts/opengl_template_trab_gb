#ifndef GAME_HPP_
#define GAME_HPP_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>

using namespace std;

namespace Game {
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void close_window_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void setup_opengl_glfw();
	void frames_per_second(GLFWwindow* window);
}

// class Game {
// 	public:
// 		Game() {};
		// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		// void close_window_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// };

#endif // !GAME_HPP_