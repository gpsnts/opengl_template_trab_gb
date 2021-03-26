#include "headers/callback_window.hpp"

void callback_window::process_input(GLFWwindow *window_refference)
{
	if (glfwGetKey(window_refference, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window_refference, true);
	}
}

void callback_window::framebuffer_size_callback(GLFWwindow *window_refference, int width, int height)
{
	glViewport(0, 0, width, height);
}