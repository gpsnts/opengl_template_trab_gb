#include "headers/gl_config.hpp"

bool gl_config::check_window_creation(GLFWwindow *window_refference)
{
	if (window_refference == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return false;
	}
	return true;
}

bool gl_config::init_glad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return false;
	}
	return true;
}

bool gl_config::init_glfw()
{
	if (!glfwInit())
	{
		cerr << "Cann't init GLFW" << endl;;
		return false;
	}
	return true;
}

void gl_config::set_opengl_version_profile()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}