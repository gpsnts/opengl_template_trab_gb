#define HEIGHT 768
#define WIDTH 1366
#define APP_NAME "Test"

#include "headers/shader.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"
#include "headers/game.hpp"

void fps_view(int argc, char *argv[], bool flag)
{
	if (argc >= 2)
	{
		string show_fps_flag(argv[1]);
		if (show_fps_flag == "show_fps") flag = true;
		else flag = false;
	}
}

int main(int argc, char *argv[])
{
	bool show_fps = false;
	fps_view(argc, argv, show_fps);

	// if (argc >= 2)
	// {
	// 	string show_fps_flag(argv[1]);
	// 	if (show_fps_flag == "show_fps") show_fps = true;
	// }

	Application *app = new Application(HEIGHT, WIDTH, APP_NAME);
	Game *game = new Game(HEIGHT, WIDTH);

	if (!app->init())
	{
		glfwTerminate();
		return EXIT_FAILURE;
	}

	game->init();
	game->projection(true); // Best practice

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		game->events(app->get_window());
		game->transformations(true);

		glfwPollEvents();
		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		game->build();

		glfwSwapBuffers(app->get_window());
	}

	delete game, app;
	Resources::clean();
	glfwTerminate();

	return EXIT_SUCCESS;
}
