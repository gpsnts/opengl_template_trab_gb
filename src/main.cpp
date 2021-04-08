#include <iostream>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/glm.hpp>

#include "headers/callback_window.hpp"

#include "headers/pch/glad_pch.hpp"
#include "headers/pch/glfw_pch.hpp"

#define GL_CALC_STRIDE(x) (x * sizeof(GLfloat))
#define GL_CALC_OFFSET(x) ((GLvoid *)(x * sizeof(GLfloat)))

#include "headers/shader.hpp"
#include "headers/renderer.hpp"
#include "headers/resources.hpp"
#include "headers/application.hpp"

// TODO: Remove
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	// Hides the app name - "Test"
	bool show_fps = true;
	
	Application *app = new Application(800, 600, "Test");
	Renderer render;
	
	if (!app->init()) return -1;

	Resources::assign_shader(
		"../src/shaders/triangle_vs.glsl",
		"../src/shaders/triangle_fs.glsl",
		"application_shaders"
	);

	while (!glfwWindowShouldClose(app->get_window()))
	{
		if (show_fps) Application::frames_per_second(app->get_window());
		callback_window::process_input(app->get_window());
		glClearColor(0.33f, 0.1f, 0.5f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(app->get_window());
		glfwPollEvents();
	}

	// Clean
	Resources::clean();
	delete app, render;
}





























































































































































































































































































// int main(int argc, char *argv[])
// {
// 	// BUFFERS
	// GLfloat positions[] = {
	//    0.0f,  0.0f,  0.0f,
	//    0.33f, 0.50f, 0.0f,
	//   -0.33f, 0.50f, 0.0f,

	//    0.0f,   0.0f,  0.0f,
	//   -0.33f, -0.50f, 0.0f,
	//    0.33f, -0.50f, 0.0f
	// };

	// GLfloat colors[] = {
	// 	1.0f, 0.0f, 0.0f,
	// 	1.0f, 0.0f, 1.0f,
	// 	0.0f, 0.0f, 1.0f,

	// 	0.0f, 0.0f, 1.0f,
	// 	0.0f, 1.0f, 1.0f,
	// 	0.0f, 1.0f, 0.0f
	// };

// 	/** ! VBO(s) */
	
// 	// Loc
// 	glGenBuffers(1, &VBO_Position);
// 	glBindBuffer(GL_ARRAY_BUFFER, VBO_Position);
// 	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

// 	// Colors
// 	glGenBuffers(1, &VBO_Color);
// 	glBindBuffer(GL_ARRAY_BUFFER, VBO_Color);
// 	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

// 	/** VAO(s) */ 
// 	glGenVertexArrays(1, &VAO);
// 	glBindVertexArray(VAO);

// 	//  Attrib
// 	glBindBuffer(GL_ARRAY_BUFFER, VBO_Position);
// 	glVertexAttribPointer(attribPos, 3, GL_FLOAT, GL_FALSE, GL_CALC_STRIDE(0), GL_CALC_OFFSET(0));
// 	glEnableVertexAttribArray(attribPos);

// 	glBindBuffer(GL_ARRAY_BUFFER, VBO_Color);
// 	glVertexAttribPointer(attribColor, 3, GL_FLOAT, GL_FALSE, GL_CALC_STRIDE(0), GL_CALC_OFFSET(0));
// 	glEnableVertexAttribArray(attribColor);

// 	// SHADER|PROGRAM
// 	GLuint frag_shader, vert_shader, program;

// 	bool can_compile_program = true;

// 	can_compile_program &= shader_compile(
// 		"../src/shaders/triangle_vs.glsl",
// 		&vert_shader,
// 		GL_VERTEX_SHADER
// 	);

// 	can_compile_program &= shader_compile(
// 		"../src/shaders/triangle_fs.glsl",
// 		&frag_shader,
// 		GL_FRAGMENT_SHADER
// 	);

// 	if (!can_compile_program) return -1;

// 	if (!create_program(&program, vert_shader, frag_shader)) return -1;

// 	// Uniform vars assign
// 	// GLfloat R = 0.0f, G = 1.0f, B = 200.0f;
// 	// GLint colorLoc = glGetUniformLocation(program, "inputColor");
// 	// if (colorLoc > -1) glUniform4f(colorLoc, R, G, B, 1.0f);
// 	// End - Uniform vars assign

// 	glDeleteShader(vert_shader);
// 	glDeleteShader(frag_shader);

// 	while (!glfwWindowShouldClose(window))
// 	{
// 		gl_config::frames_per_second(window);
		// callback_window::process_input(window);

// 		glClearColor(0.33f, 0.1f, 0.5f, 0.5f);
// 		glClear(GL_COLOR_BUFFER_BIT);

// 		glUseProgram(program);
// 		glBindVertexArray(VAO);
// 		glDrawArrays(GL_TRIANGLES, 0, 6);
// 		glBindVertexArray(0);

// 		glfwSwapBuffers(window);
// 		glfwPollEvents();
// 	}

// 	glDeleteProgram(program);
// 	glDeleteVertexArrays(1, &VAO);
// 	glDeleteBuffers(1, &VBO_Position);
// 	glDeleteBuffers(1, &VBO_Color);

// 	glfwTerminate();
// 	return 0;
// }