// Ler o que é definido no cabeçalho "stb_image.h" para entender o porquê disso
#define STB_IMAGE_IMPLEMENTATION

#include "headers/shader.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"
#include "headers/game.hpp"

#define CALC_QUAD_WIDTH(x) (x / 2)
#define CALC_QUAD_HEIGHT(y) (y / 2)

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

	GLfloat left = 0.f, right = 0.f, up = 0.f, bottom = 0.f;

	bool flag = true;

	while (!glfwWindowShouldClose(app->get_window()))
	{
		Application::frames_per_second(app->get_window());
		
		Application::process_input(app->get_window());
		glfwPollEvents();
		
		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
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