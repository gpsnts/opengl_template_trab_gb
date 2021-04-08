// #include <glm/glm.hpp>

#include "headers/shader.hpp"
#include "headers/renderer.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"

int main(int argc, char *argv[])
{
	bool show_fps = false;

	if (argc >= 2)
	{
		string show_fps_flag(argv[1]);
		if (show_fps_flag == "show_fps") show_fps = true;
	}
	
	Application *app = new Application(800, 600, "Test");
	Renderer render;
	
	if (!app->init()) return -1;

	Resources::assign_shader(
		"../src/shaders/triangle_vs.glsl",
		"../src/shaders/triangle_fs.glsl",
		"shader"
	);

	render.set_data(
		POSITION,
		"Positions",
		{
			 0.0f,  0.0f,  0.0f,
       0.33f, 0.50f, 0.0f,
      -0.33f, 0.50f, 0.0f,

       0.0f,   0.0f,  0.0f,
      -0.33f, -0.50f, 0.0f,
       0.33f, -0.50f, 0.0f
		}
	);

	render.set_data(
		COLOR,
		"Colors",
		{
			1.0f, 0.0f, 0.0f,
      1.0f, 0.0f, 1.0f,
      0.0f, 0.0f, 1.0f,

      0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 1.0f,
      0.0f, 1.0f, 0.0f
		}
	);

	render.bind_buffer(POSITION, "VBO_Position", "Positions");
	render.bind_buffer(COLOR, "VBO_Color", "Colors");
	render.bind_vertex("VAO");

	render.vbo_attrib("VBO_Position", "attribPosition", 0, 0, 0);
	render.vbo_attrib("VBO_Color", "attribColor", 1, 0, 0);

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());
		
		glClearColor(0.33f, 0.1f, 0.5f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(Resources::get_current_shaders()["shader"].getProgram());
		glBindVertexArray(render.get_vaos()["VAO"]);
  	glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);

		glfwSwapBuffers(app->get_window());
		glfwPollEvents();
	}

	Resources::clean();
	render.clean();
	delete app, render;
	glfwTerminate();
	return 0;
}