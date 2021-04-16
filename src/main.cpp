#include "headers/shader.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"
#include "headers/game.hpp"

#define CALC_QUAD_WIDTH(x) (x / 2)
#define CALC_QUAD_HEIGHT(y) (y / 2)

int main(int argc, char *argv[])
{
	bool show_fps = false;

	if (argc >= 2)
	{
		string show_fps_flag(argv[1]);
		if (show_fps_flag == "show_fps") show_fps = true;
	}

	GLint HEIGHT = 768;
	GLint WIDTH = 1366;
	const GLchar *APP_NAME = "TEST";

	// cout << "\n\n\n" << CALC_QUAD_WIDTH(WIDTH) << "\n\n\n" << endl;
	// cout << "\n\n\n" << CALC_QUAD_HEIGHT(HEIGHT) << "\n\n\n" << endl;

	Application *app = new Application(HEIGHT, WIDTH, APP_NAME);
	// TODO: GameObject here
	Game *game = new Game(
		HEIGHT, 
		WIDTH,
		Vertex{  0.f,  	 0.5f,	0.f },
		Vertex{ -0.85f, -0.25f, 0.f },
		Vertex{  0.85f, -0.25f, 0.f }
	);

	if (!app->init())
	{
		glfwTerminate();
		return EXIT_FAILURE;
	}

	bool ex1 = false, ex2 = false, ex4 = false, ex5 = false; 

	game->init();
	// game->projection(); // Best practice

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		game->transformations();
		game->events(app->get_window(), ex1, ex2, ex4, ex5);

		glfwPollEvents();
		
		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (ex1)
		{
			game->projection(true, true);
			glfwGetFramebufferSize(app->get_window(), &WIDTH, &HEIGHT);
			glViewport(
				0,
				0,
				WIDTH,
				HEIGHT
			);
			game->build();
		}

		if (ex2)
		{
			game->projection(false, false, true);
			glfwGetFramebufferSize(app->get_window(), &WIDTH, &HEIGHT);
			glViewport(
				0,
				0,
				WIDTH,
				HEIGHT
			);
			game->build();
		}
		
		if (ex4)
		{
			game->projection();
			glfwGetFramebufferSize(app->get_window(), &WIDTH, &HEIGHT);
			glViewport(
				CALC_QUAD_WIDTH(WIDTH),
				CALC_QUAD_HEIGHT(HEIGHT),
				CALC_QUAD_WIDTH(WIDTH),
				CALC_QUAD_HEIGHT(HEIGHT)
			);
			game->build();
		}
		
		if (ex5)
		{
			game->projection();
			glfwGetFramebufferSize(app->get_window(), &WIDTH, &HEIGHT);
			glViewport(
				CALC_QUAD_WIDTH(WIDTH),
				CALC_QUAD_HEIGHT(HEIGHT),
				CALC_QUAD_WIDTH(WIDTH),
				CALC_QUAD_HEIGHT(HEIGHT)
			);
			game->build();

			glViewport(
				0,
				0,
				CALC_QUAD_WIDTH(WIDTH),
				CALC_QUAD_HEIGHT(HEIGHT)
			);
			game->build();

			glViewport(
				0,
				CALC_QUAD_HEIGHT(HEIGHT),
				CALC_QUAD_WIDTH(WIDTH),
				CALC_QUAD_HEIGHT(HEIGHT)
			);
			game->build();

			glViewport(
				CALC_QUAD_HEIGHT(WIDTH),
				0,
				CALC_QUAD_WIDTH(WIDTH),
				CALC_QUAD_HEIGHT(HEIGHT)
			);
			game->build();
		}

		glfwSwapBuffers(app->get_window());
	}

	delete game, app;
	Resources::clean();
	glfwTerminate();

	return EXIT_SUCCESS;
}