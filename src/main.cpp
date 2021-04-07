#include <iostream>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/glm.hpp>

#include "headers/shader_wrapper.hpp"
#include "headers/gl_config.hpp"
#include "headers/callback_window.hpp"

#include "headers/pch/glad_pch.hpp"
#include "headers/pch/glfw_pch.hpp"

#define GL_CALC_STRIDE(x) (x * sizeof(GLfloat))
#define GL_CALC_OFFSET(x) ((GLvoid *)(x * sizeof(GLfloat)))

int WIDTH = 800, HEIGHT = 600;
GLFWwindow *window;

#include "headers/shader.hpp"
#include "headers/renderer.hpp"
#include "headers/resources.hpp"


// TODO: Remove
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	// Init config
	if (!gl_config::init_glfw())
	{
		cerr << "Can't initialize Glad" << endl;
		return -1;
	}

	gl_config::set_opengl_version_profile();

	window = glfwCreateWindow(800, 600, "Triangle Example", NULL, NULL);
	
	if (!gl_config::check_window_creation(window)) return -1;

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, callback_window::framebuffer_size_callback);

	if (!gl_config::init_glad()) return -1;

	// End - Init config

	// TODO: WIP (Renderer)

	Resources::assign_shader(
		"../src/shaders/triangle_vs.glsl",
		"../src/shaders/triangle_fs.glsl",
		"application_shaders"
	);


	Resources::clean();
}

// int main(int argc, char *argv[])
// {
// 	if (!gl_config::init_glfw())
// 	{
// 		cerr << "Can't initialize Glad" << endl;
// 		return 1;
// 	}

// 	gl_config::set_opengl_version_profile();

// 	window = glfwCreateWindow(800, 600, "Triangle Example", NULL, NULL);
	
// 	if (!gl_config::check_window_creation(window)) return -1;

// 	glfwMakeContextCurrent(window);
// 	glfwSetFramebufferSizeCallback(window, callback_window::framebuffer_size_callback);

// 	if (!gl_config::init_glad()) return -1;

// 	// BUFFERS
// 	GLfloat positions[] = {
// 	   0.0f,  0.0f,  0.0f,
// 	   0.33f, 0.50f, 0.0f,
// 	  -0.33f, 0.50f, 0.0f,

// 	   0.0f,   0.0f,  0.0f,
// 	  -0.33f, -0.50f, 0.0f,
// 	   0.33f, -0.50f, 0.0f
// 	};

// 	GLfloat colors[] = {
// 		1.0f, 0.0f, 0.0f,
// 		1.0f, 0.0f, 1.0f,
// 		0.0f, 0.0f, 1.0f,

// 		0.0f, 0.0f, 1.0f,
// 		0.0f, 1.0f, 1.0f,
// 		0.0f, 1.0f, 0.0f
// 	};

// 	GLuint attribPos = 0, attribColor = 1;
// 	GLuint VBO_Position, VBO_Position_2, VBO_Color, VAO;

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
// 		callback_window::process_input(window);

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