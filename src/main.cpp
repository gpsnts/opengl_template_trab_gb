#include <iostream>

#include "headers/utils.hpp"
#include "headers/gl_config.hpp"
#include "headers/callback_window.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	if (!gl_config::init_glfw()) return -1;

	gl_config::set_opengl_version_profile();

	GLFWwindow *window = glfwCreateWindow(800, 600, "Hello Colorful Triangle", NULL, NULL);
	
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

	if (!can_compile_program) return -1;

	program = glCreateProgram();
	glAttachShader(program, frag_shader);
	glAttachShader(program, vert_shader);

	glLinkProgram(program);

	GLint compile_flag = -1;

	glGetProgramiv(program, GL_LINK_STATUS, &compile_flag);

	glUseProgram(program);

	glDeleteShader(frag_shader);
	glDeleteShader(vert_shader);

	float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		callback_window::process_input(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}