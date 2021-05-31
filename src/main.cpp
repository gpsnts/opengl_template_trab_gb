// Ler o que é definido no cabeçalho "stb_image.h" para entender o porquê disso
#define STB_IMAGE_IMPLEMENTATION

#include "headers/shader.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"
#include "headers/game.hpp"

#define CALC_QUAD_WIDTH(x) (x / 2)
#define CALC_QUAD_HEIGHT(y) (y / 2)

void high_level_filter_mapping(GLFWwindow  *ref_window, GLint &ref_selection)
{
	if (glfwGetKey(ref_window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		cout << "Default" << endl;
		ref_selection = -1;
	}

	if (glfwGetKey(ref_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cout << "Apenas vermelho" << endl;
		ref_selection = 0;
	}
	
	if (glfwGetKey(ref_window, GLFW_KEY_E) == GLFW_PRESS)
	{
		cout << "Apenas verde" << endl;
		ref_selection = 1;
	}

	if (glfwGetKey(ref_window, GLFW_KEY_R) == GLFW_PRESS)
	{
		cout << "Apenas azul" << endl;
		ref_selection = 2;
	}

	if (glfwGetKey(ref_window, GLFW_KEY_T) == GLFW_PRESS)
	{
		cout << "Grayscale" << endl;
		ref_selection = 3;
	}

	if (glfwGetKey(ref_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cout << "Colorização (roxo)" << endl;
		ref_selection = 4;
	}

	if (glfwGetKey(ref_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cout << "Inversão" << endl;
		ref_selection = 5;
	}

	if (glfwGetKey(ref_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cout << "Binarização" << endl;
		ref_selection = 6;
	}	
}

int main(int argc, char *argv[])
{
	GLint HEIGHT = 768;
	GLint WIDTH = 1366;
	const GLchar *APP_NAME = "TEST";

	Application *app = new Application(HEIGHT, WIDTH, APP_NAME);
	
	Game *game = new Game(
		HEIGHT, 
		WIDTH
	);

	if (!app->init())
	{
		glfwTerminate();
		return EXIT_FAILURE;
	}

	bool rotate = false; 

	game->init();

	GLfloat delta 			= 0.f;
  GLfloat last_frame 	= 0.f;
	GLint selection			= -1;
  GLboolean action 		= false;

	while (!glfwWindowShouldClose(app->get_window()))
	{
		Application::frames_per_second(app->get_window());
		
		Application::process_input(app->get_window());
		
		glfwPollEvents();

		high_level_filter_mapping(app->get_window(), selection);

		GLfloat current = glfwGetTime();
    delta 					= current - last_frame;
    last_frame 			= current;
		
		game->handle_input(delta, selection, action, WIDTH, HEIGHT);

		glClearColor(1.f, 1.f, 1.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwGetFramebufferSize(app->get_window(), &WIDTH, &HEIGHT);

		game->build();
		
		glfwSwapBuffers(app->get_window());
	}

	delete game, app;
	Resources::clean();
	glfwTerminate();

	return EXIT_SUCCESS;
}