#include "headers/callback_window.hpp"

void callback_window::process_input(GLFWwindow *window_reference)
{
	if (glfwGetKey(window_reference, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window_reference, true);
	}
}

void callback_window::framebuffer_size_callback(GLFWwindow *window_reference, int width, int height)
{
	glViewport(0, 0, width, height);
}