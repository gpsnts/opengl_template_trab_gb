#include <cmath>

#include "headers/shader.hpp"
#include "headers/renderer.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"

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
	Renderer render;

	if (!app->init()) return -1;

	Resources::assign_shader(
		"../src/shaders/triangle.vert",
		"../src/shaders/triangle.frag",
		"shader"
	);

	Resources::assign_shader(
		"../src/shaders/triangle.vert",
		"../src/shaders/triangle_uniform.frag",
		"shader_uniform"
	);

	render.set_data(
		POSITION,
		"Positions_1",
		{
			 0.0f, 0.0f, 0.0f,
			 0.33f, 0.50f, 0.0f,
			-0.33f, 0.50f, 0.0f,

			 0.0f, 0.0f, 0.0f,
			-0.33f, -0.50f, 0.0f,
			 0.33f, -0.50f, 0.0f
		}
	);

	render.set_data(
		POSITION,
		"Positions_2",
		{
			 0.0f, 0.0f, 0.0f,
			 0.33f, 0.50f, 0.0f,
			-0.33f, 0.50f, 0.0f,

			 0.0f, 0.0f, 0.0f,
			-0.33f, -0.50f, 0.0f,
			 0.33f, -0.50f, 0.0f,

			 0.0f, 0.0f, 0.0f,
			 0.33f, 0.50f, 0.0f,
			 0.33f, -0.50f, 0.0f
		}
	);

	render.set_data(
		POSITION,
		"Positions_3b",
		{
		 	 0.0f, 0.0f, 0.0f,
		   0.33f, 0.50f, 0.0f,
		  -0.33f, 0.50f, 0.0f,

		   0.0f, 0.0f, 0.0f,
		  -0.33f, -0.50f, 0.0f,
		   0.33f, -0.50f, 0.0f
		}
	);

	render.set_data(
		COLOR,
		"Colors_3b",
		{
			1.0f, 0.0f, 0.0f,
		 	1.0f, 0.0f, 1.0f,
		 	0.0f, 0.0f, 1.0f,

		 	0.0f, 0.0f, 1.0f,
		 	0.0f, 1.0f, 1.0f,
		 	0.0f, 1.0f, 0.0f
		}
	);

	render.set_data(
		DATA,
		"Data_3a",
		{
			 0.0f, 0.0f, 0.0f,
		   0.33f, 0.50f, 0.0f,
		  -0.33f, 0.50f, 0.0f,

		   0.0f, 1.0f, 1.0f,
		   0.0f, 1.0f, 1.0f,
		   0.0f, 1.0f, 1.0f
		}
	);

	render.set_data(
		POSITION,
		"Positions_4",
		{
			 0.33f, 0.33f, 0.0f,
		 	 0.50f, -0.50f, 0.0f,
		 	-0.50f, -0.50f, 0.0f,
		 	-0.33f, 0.33f, 0.0f
		}
	);

	render.set_ebo_data(
		"EBO_4",
		{
			0, 1, 3,
			1, 2, 3
		}
	);

	// Attrib
	// Ex - 1
	render.bind_vertex("VAO_1");
	render.bind_buffer(POSITION, "VBO_Position_1", "Positions_1");
	render.vbo_attrib("VBO_Position_1", 0, 0, 0);
	//
	// Ex - 2
	render.bind_vertex("VAO_2");
	render.bind_buffer(POSITION, "VBO_Position_2", "Positions_2");
	render.vbo_attrib("VBO_Position_2", 0, 0, 0);
	//
	// Ex - 3a
	render.bind_vertex("VAO_3a");
	render.bind_buffer(DATA, "VBO_Data_3a", "Data_3a");
	render.vbo_attrib("VBO_Data_3a", 0, 0, 0);
	render.vbo_attrib("VBO_Data_3a", 1, 0, 9);
	//
	// Ex - 3b
	render.bind_vertex("VAO_3b");
	render.bind_buffer(POSITION, "VBO_Position_3b", "Positions_3b");
	render.bind_buffer(COLOR, "VBO_Color_3b", "Colors_3b");
	render.vbo_attrib("VBO_Position_3b", 0, 0, 0);
	render.vbo_attrib("VBO_Color_3b", 1, 0, 0);
	//
	// Ex - 4
	render.bind_vertex("VAO_4");
	render.bind_buffer(POSITION, "VBO_Position_4", "Positions_4");
	render.bind_ebo_buffer("EBO_Buffer_4", "EBO_4");
	render.vbo_attrib("VBO_Position_4", 0, 3, 0);
	//
	// End - Attrib

	// Ex - 5
	GLuint N = 360;
	GLfloat pos_x = 0.0f, pos_y = 0.0f, radius = 0.5f;
	GLfloat DELTA_ANGLE = M_PI / N, CURR_ANGLE = DELTA_ANGLE;

	// e.g [x, y, z] para funcionar como as matrizes "vetorizadas" da OpenGL 
  GLfloat VERTICES[N * 3];
	for (int i = 0; i < N * 3; i += 3)
	{
  	VERTICES[i] 		= pos_y + sin(CURR_ANGLE) * radius;
  	VERTICES[i + 1] = pos_x + cos(CURR_ANGLE) * radius;
  	VERTICES[i + 2] = 0.0f; // Z-index
  	CURR_ANGLE += 2 * DELTA_ANGLE;
  }

	GLuint INDICES[3 * (N - 2)];
  int K = 1;
  for (int i = 0; i < 3 * (N - 2) - 2; i += 3) {
    INDICES[i] 		 = 0;
    INDICES[i + 1] = K;
    INDICES[i + 2] = K + 1; // Z-index
    ++K;
  }

	// TODO - Refatorar para fazer com que métodos como a criação de círculo sejam integrados
	GLuint VBO_5, EBO_5;
	render.bind_vertex("VAO_5");
	glGenBuffers(1, &VBO_5);
	glGenBuffers(1, &EBO_5);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_5);
  glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), VERTICES, GL_DYNAMIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_5);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, GL_CALC_STRIDE(3), GL_CALC_OFFSET(0));
  glEnableVertexAttribArray(0);
	//
	// End - Ex - 5

	// Ex - 7
	render.set_data(
		POSITION,
		"Positions_7_Telhado",
		{
			-0.5f, 0.25f, 0.0f,  
       0.5f, 0.25f, 0.0f, 
       0.0f, 0.75f, 0.0f
		}
	);

	render.set_data(
		POSITION,
		"Positions_7_Casa",
		{
			-0.5f, 0.75f, 0.0f,
       0.5f, 0.75f, 0.0f, 
       0.5f, 1.25f, 0.0f,

			-0.5f, 0.75f, 0.0f,
			 0.5f, 1.25f, 0.0f,
			-0.5f, 1.25f, 0.0f
		}
	);

	render.bind_vertex("VAO_7_Telhado");
	render.bind_buffer(POSITION, "VBO_Positions_7_Telhado", "Positions_7_Telhado");
	render.vbo_attrib("VBO_Positions_7_Telhado", 0, 0, 0);

	render.bind_vertex("VAO_7_Telhado");
	render.bind_buffer(POSITION, "VBO_Positions_7_Casa", "Positions_7_Casa");
	render.vbo_attrib("VBO_Positions_7_Casa", 0, 0, 0);
	//
	// End - Ex - 7

	bool show_1 = false,
			 show_2 = false,
			 show_3a = false,
			 show_3b = false,
			 show_4 = false,
			 show_5 = false,
			 show_7 = true;

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		Application::process_input(app->get_window());

		if (glfwGetKey(app->get_window(), GLFW_KEY_Q) == GLFW_PRESS) show_1 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_A) == GLFW_PRESS) show_1 = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_W) == GLFW_PRESS) show_2 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_S) == GLFW_PRESS) show_2 = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_E) == GLFW_PRESS) show_3a = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_D) == GLFW_PRESS) show_3a = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_R) == GLFW_PRESS) show_3b = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_F) == GLFW_PRESS) show_3b = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_T) == GLFW_PRESS) show_4 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_G) == GLFW_PRESS) show_4 = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_Y) == GLFW_PRESS) show_5 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_H) == GLFW_PRESS) show_5 = true;

		if (glfwGetKey(app->get_window(), GLFW_KEY_U) == GLFW_PRESS) show_7 = false;
		if (glfwGetKey(app->get_window(), GLFW_KEY_J) == GLFW_PRESS) show_7 = true;

		glClearColor(0.33f, 0.1f, 0.25f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (show_1)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_1"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 0.0f, 1.0f);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}

		if (show_2)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_2"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 1.0f, 1.0f, 1.0f);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 0.0f, 1.0f, 1.0f);
			glDrawArrays(GL_LINE_LOOP, 3, 6);
			if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 1.0f, 1.0f, 1.0f);
			glDrawArrays(GL_LINE_LOOP, 6, 9);

			glBindVertexArray(0);
		}

		if (show_3a)
		{
			glUseProgram(Resources::get_current_shaders()["shader"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_3a"]);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glBindVertexArray(0);
		}

		if (show_3b)
		{
			glLineWidth(15);
			glPointSize(10);
			glUseProgram(Resources::get_current_shaders()["shader"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_3b"]);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}

		if (show_4)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_4"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 1.0f, 1.0f);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 0.0f, 0.0f, 10.0f);
			glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		if (show_5)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			glBindVertexArray(render.get_vaos()["VAO_5"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 1.0f, 10.0f);
			glDrawElements(GL_TRIANGLES, 3 * (N - 2), GL_UNSIGNED_INT, nullptr);
			glBindVertexArray(0);
		}

		if (show_7)
		{
			GLint colorLoc = glGetUniformLocation(
				Resources::get_current_shaders()["shader_uniform"].getProgram(),
				"inputColor"
			);
			glUseProgram(Resources::get_current_shaders()["shader_uniform"].getProgram());
			// Telhado
			glBindVertexArray(render.get_vaos()["VAO_7_Telhado"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 0.0f, 10.0f);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			// Casa
			glBindVertexArray(render.get_vaos()["VAO_7_Casa"]);
			if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 1.0f, 0.0f, 10.0f);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}

		glfwSwapBuffers(app->get_window());
		glfwPollEvents();
	}

	Resources::clean();
	render.clean();
	delete app, render;
	glfwTerminate();
	return 0;
}