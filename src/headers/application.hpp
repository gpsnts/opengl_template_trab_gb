#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "pch/glfw_pch.hpp"
#include "pch/glad_pch.hpp"

#include <iostream>
#include <sstream>

using namespace std;

class Application
{
private:
	GLFWwindow *window;
	string name;
	int width, height;

	Application () {}

	void static framebuffer_size_callback(
		GLFWwindow *window,
		int width,
		int height
	);

	bool init_glfw();
	void set_profile();
	bool validate_window(GLFWwindow *window);
	bool init_glad();
public:
	Application (int s_width, int s_height, string s_name);
	
	void static frames_per_second(GLFWwindow *window);
	void static process_input(GLFWwindow *window);
	void static process_mouse_pos_input(GLFWwindow *window, int button, int action, int mods);
	bool init();
	GLFWwindow *get_window();
};

#endif // __APPLICATION_HPP__