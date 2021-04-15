#include <cmath>

#include "headers/shader.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"
#include "headers/game.hpp"

#define HEIGHT 800
#define WIDTH 600
#define APP_NAME "Test"

int main(int argc, char *argv[])
{
	bool show_fps = false;

	if (argc >= 2)
	{
		string show_fps_flag(argv[1]);
		if (show_fps_flag == "show_fps") show_fps = true;
	}

	Application *app = new Application(HEIGHT, WIDTH, APP_NAME);
	Game *game = new Game();

	if (!app->init()) return -1;

	game->init();

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);

		// game->build();
		glUseProgram(game->get_shader().getProgram());

		// GLuint modelLoc = glGetUniformLocation(game->get_shader().getProgram(), "model");
		// glm::mat4 trans = glm::mat4(1.0f);
		// trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
		// GLuint transformLoc = glGetUniformLocation(game->get_shader().getProgram(), "transform");
		// glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
		
		GLint colorLoc = glGetUniformLocation(
			game->get_shader().getProgram(),
			"inputColor"
		);
		glUniform4f(colorLoc, 1.0f, 1.0f, 0.0f, 1.0f);

		glBindVertexArray(game->get_render()->get_vao());

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glUseProgram(0);

		glfwSwapBuffers(app->get_window());

		glfwPollEvents();
	}

	delete game, app;
	Resources::clean();
	glfwTerminate();

	return EXIT_SUCCESS;
}
