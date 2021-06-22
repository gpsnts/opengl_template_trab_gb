// Ler o que é definido no cabeçalho "stb_image.h" para entender o porquê disso
#define STB_IMAGE_IMPLEMENTATION

#include "headers/shader.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"
#include "headers/game.hpp"

GLint selection = -1;

vec2 RANGE_BUTTON(1366 * 0.1, 768 * 0.15);

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

	if (glfwGetKey(ref_window, GLFW_KEY_F) == GLFW_PRESS)
	{
		cout << "Custom" << endl;
		ref_selection = 7;
	}
}

bool valid_range(double x, double y, double boundary_x, double boundary_y, double offset_x, double offset_y) {
	double MIN_X = boundary_x + offset_x;
	double MIN_Y = boundary_y + offset_y;
	double MAX_X = MIN_X + 115 + offset_x;
	double MAX_Y = MIN_Y + 40 + offset_y;

	return (MIN_X <= x && x <= MAX_X) && (MIN_Y <= y && y <= MAX_Y);
}

void mouse_callback(GLFWwindow *window, double x, double y)
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) selection = -1;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 0)) selection = 0;
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 60)) selection = 1;
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 150)) selection = 2;
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 240)) selection = 3;
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 320)) selection = 4;
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 410)) selection = 5;
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 500)) selection = 6;
		if(valid_range(x, y, RANGE_BUTTON.x, RANGE_BUTTON.y, 0, 590)) selection = 7;
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
  GLboolean action 		= false;

	while (!glfwWindowShouldClose(app->get_window()))
	{
		glfwSetInputMode(app->get_window(), GLFW_STICKY_KEYS, GL_TRUE );

		glfwSetCursorPosCallback(app->get_window(), &mouse_callback);

		Application::frames_per_second(app->get_window());
		
		Application::process_input(app->get_window());
		
		glfwPollEvents();

		high_level_filter_mapping(app->get_window(), selection);

		GLfloat current = glfwGetTime();
    delta 					= current - last_frame;
    last_frame 			= current;
		
		game->handle_input(delta, selection, action, WIDTH, HEIGHT);

		glClearColor(1.f, 0.f, 15.f, 1.f);
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