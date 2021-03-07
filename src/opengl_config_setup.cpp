#include "headers/opengl_config_setup.hpp"

int OpenGLConfigSetup::create_window(GLFWwindow* window)
{
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return 0;
	}
	return 1;
}

void OpenGLConfigSetup::set_callbacks_and_context(GLFWwindow* window)
{
	glfwMakeContextCurrent(window);

	// ! Set framebuffer size change adjust callback
	glfwSetFramebufferSizeCallback(window, GameSetup::framebuffer_size_callback);
	
	// ! Set close window callback
	glfwSetKeyCallback(window, GameSetup::close_window_callback);
}

int OpenGLConfigSetup::init_glad()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return 0;
	}
	return 1;
}