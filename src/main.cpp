#include "headers/shader.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"
#include "headers/game_object.hpp"

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
	// "Game Object" -- Triangle
	GameObject *triangle = new GameObject(
		HEIGHT, 
		WIDTH,
		Vertex{ 0.f, 0.f, 0.f },
		Vertex{ -0.85f, 0.85f, 0.f },
		Vertex{ 0.85f, 0.85f, 0.f }
	); 

	if (!app->init())
	{
		glfwTerminate();
		return EXIT_FAILURE;
	}

	triangle->init();
	triangle->projection(true, true); // Best practice

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		// May change the value
		glfwGetFramebufferSize(app->get_window(), &WIDTH, &HEIGHT);
		triangle->events(app->get_window());
		triangle->transformations();
		glViewport(0, 0, WIDTH, HEIGHT);

		glfwPollEvents();
		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		triangle->build();

		glfwSwapBuffers(app->get_window());
	}

	delete triangle, app;
	Resources::clean();
	glfwTerminate();

	return EXIT_SUCCESS;
}