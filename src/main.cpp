// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
#include "headers/game.hpp"
#include <iostream>

using namespace std;

const char* APP_NAME = "OpenGL WIP Game";
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main()
{
	Game::setup_opengl_glfw();

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, APP_NAME, NULL, NULL);

	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// ! Set framebuffer size change adjust callback
	glfwSetFramebufferSizeCallback(window, Game::framebuffer_size_callback);
	
	// ! Set close window callback
	glfwSetKeyCallback(window, Game::close_window_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		// ! FPS Info
		Game::frames_per_second(window);
		
		glfwPollEvents();
		glfwSwapBuffers(window);

		glClearColor(0.23f, 0.01f, 0.45f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	glfwTerminate();
	return 0;
}
