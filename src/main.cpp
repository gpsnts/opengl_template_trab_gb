#include <cmath>

#include "headers/shader.hpp"
#include "headers/renderer.hpp"
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
	Game game;

	if (!app->init()) return -1;

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);

		// if (show_5)
		// {
		// 	GLint colorLoc = glGetUniformLocation(
		// 		Resources::get_current_shaders()["shader_uniform"].getProgram(),
		// 		"inputColor"
		// 	);
		// 	glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
		// 	glBindVertexArray(render.get_vaos()["VAO_5"]);
		// 	if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 1.0f, 10.0f);
		// 	glDrawElements(GL_TRIANGLES, 3 * (N - 2), GL_UNSIGNED_INT, nullptr);
		// 	glBindVertexArray(0);
		// }

		game.build();

		glfwSwapBuffers(app->get_window());
		glfwPollEvents();
	}

	Resources::clean();
	glfwTerminate();
	return 0;
}
