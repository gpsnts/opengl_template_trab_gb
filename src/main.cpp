#include "headers/opengl_config_setup.hpp"

using namespace std;

const char* APP_NAME = "OpenGL WIP GameSetup";
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	GameSetup::setup_opengl_glfw();

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, APP_NAME, NULL, NULL);

	if (!OpenGLConfigSetup::create_window(window)) return -1;
	
	OpenGLConfigSetup::set_callbacks_and_context(window);

	if (!OpenGLConfigSetup::init_glad()) return -1;

	while (!glfwWindowShouldClose(window))
	{
		// ! FPS Info
		GameSetup::frames_per_second(window);
		
		glfwPollEvents();
		glfwSwapBuffers(window);

		glClearColor(0.23f, 0.01f, 0.45f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	glfwTerminate();
	return 0;
}
