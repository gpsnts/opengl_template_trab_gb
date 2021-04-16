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

	bool rotate = false; 

	game->init();
	game->projection(); // Best practice

	GLfloat left = 0.f, right = 0.f, up = 0.f, bottom = 0.f;

	bool flag = true;

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		game->events(app->get_window(), left, right, up, bottom);

		game->transformations(
			{
				glm::translate(glm::mat4(1.f), glm::vec3(right, 0.f, 0.f)),
				glm::translate(glm::mat4(1.f), glm::vec3(0.f, up, 0.f)),
				glm::translate(glm::mat4(1.f), glm::vec3(left * -1, 0.f, 0.f)),
				glm::translate(glm::mat4(1.f), glm::vec3(0.f, bottom * -1, 0.f)),
				glm::rotate(glm::mat4(1.f), (float) glfwGetTime() * -5.f, glm::vec3(0.f, 15.f, 0.f))
			},
			false
		);

		glfwPollEvents();
		
		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(app->get_window(), &WIDTH, &HEIGHT);

		glViewport(30, 30, WIDTH, HEIGHT);
		game->build();

		game->transformations(
			{
				glm::rotate(glm::mat4(1.f), (float) glfwGetTime() * -5.f, glm::vec3(15.f, 0.f, 0.f))
			},
			false
		);

		glViewport(20, 20, CALC_QUAD_WIDTH(WIDTH), CALC_QUAD_HEIGHT(HEIGHT));
		game->build();

		game->transformations(
			{
				glm::rotate(glm::mat4(1.f), (float) glfwGetTime() * -5.f, glm::vec3(0.f, 0.f, 10.f))
			},
			false
		);

		glViewport(10, 10, CALC_QUAD_WIDTH(WIDTH) / 2, CALC_QUAD_HEIGHT(HEIGHT) / 2);
		game->build();

		glfwSwapBuffers(app->get_window());
	}

	delete game, app;
	Resources::clean();
	glfwTerminate();

	return EXIT_SUCCESS;
}