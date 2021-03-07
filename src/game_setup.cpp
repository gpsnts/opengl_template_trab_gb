#include "headers/game_setup.hpp"

void GameSetup::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GameSetup::close_window_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key  == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}	
}

void GameSetup::setup_opengl_glfw()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void GameSetup::frames_per_second(GLFWwindow* window)
{
	static double previous_time = 0.0;
	static int frame_count = 0;
	double elapsed_time, current_time = glfwGetTime();

	elapsed_time = current_time - previous_time;

	if (elapsed_time > 0.25) // 4x p/sec
	{
		previous_time = current_time;
		double 
			frames_per_second = (double) frame_count / elapsed_time,
			millis_per_frame 	= 1000.0 / frames_per_second;

		ostringstream out;
		out.precision(3);
		out << fixed
				<< "FPS:  " << frames_per_second << " - "
				<< "Time (Frame) " << millis_per_frame << " millis";

		glfwSetWindowTitle(window, out.str().c_str());
		
		frame_count = 0;
	}

	frame_count++;
}