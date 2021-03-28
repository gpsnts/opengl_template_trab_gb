#include <iostream>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/glm.hpp>

#include "headers/shader_wrapper.hpp"
#include "headers/gl_config.hpp"
#include "headers/callback_window.hpp"

#include "headers/pch/glad_pch.hpp"
#include "headers/pch/glfw_pch.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(int argc, char *argv[])
{
	if (!gl_config::init_glfw())
	{
		cerr << "Can't initialize Glad" << endl;
		return 1;
	}

	gl_config::set_opengl_version_profile();

	GLFWwindow *window = glfwCreateWindow(800, 600, "Triangle Example", NULL, NULL);
	
	if (!gl_config::check_window_creation(window)) return -1;

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, callback_window::framebuffer_size_callback);

	if (!gl_config::init_glad()) return -1;

	GLuint frag_shader, vert_shader, program;

	bool can_compile_program = true;

	can_compile_program &= shader_compile(
		"../src/shaders/triangle_vs.glsl",
		&vert_shader,
		GL_VERTEX_SHADER
	);

	can_compile_program &= shader_compile(
		"../src/shaders/triangle_fs.glsl",
		&frag_shader,
		GL_FRAGMENT_SHADER
	);

	if (!can_compile_program)
	{
		cerr << "ERROR: Can't compile shaders" << endl;
		return -1;
	}

	if (!create_program(&program, vert_shader, frag_shader)) 
	{
		cerr << "ERROR: Can't create program (shaders ok)" << endl;
		return -1;
	}

	// GLfloat vertices[] = {
  //   -0.25f, -0.25f, 0.0f, // Esq
  //    0.25f, -0.25f, 0.0f, // Dir
  //    0.0f,  0.5f, 0.0f  // Topo
  // };

	GLfloat vertices[] = {
    -0.25f, 0.25f, 0.0f, // Esq
     0.25f, 0.25f, 0.0f, // Dir
     0.0f,  -0.25f, 0.0f  // Topo
  };

	GLuint attribPos = 0;
	GLuint VBO, VAO;

	// VBO
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(attribPos);
	glVertexAttribPointer(attribPos, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

	while (!glfwWindowShouldClose(window))
	{
		gl_config::frames_per_second(window);
		callback_window::process_input(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}