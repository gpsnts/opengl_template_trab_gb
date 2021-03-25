#include <iostream>

#include "headers/utils.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Foo", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	if (!GLAD_GL_ARB_direct_state_access)
	{
		std::cout << "DSA not supported!" << std::endl;
		return -1;
	}

	float vertices[] = {
			-1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	GLuint attribPos = 0;
	GLuint attribCol = 1;

	unsigned int hctVBO;
	glCreateBuffers(1, &hctVBO);

	glNamedBufferStorage(hctVBO, sizeof(vertices), vertices, GL_DYNAMIC_STORAGE_BIT);

	unsigned int hctVAO;
	glCreateVertexArrays(1, &hctVAO);

	GLuint vaoBindingPoint = 0;
	glVertexArrayVertexBuffer(hctVAO, vaoBindingPoint, hctVBO, 0, 6 * sizeof(float));

	glEnableVertexArrayAttrib(hctVAO, attribPos);
	glEnableVertexArrayAttrib(hctVAO, attribCol);

	glVertexArrayAttribFormat(hctVAO, attribPos, 3, GL_FLOAT, false, 0);
	glVertexArrayAttribFormat(hctVAO, attribCol, 3, GL_FLOAT, false, 3 * sizeof(float));

	glVertexArrayAttribBinding(hctVAO, attribPos, vaoBindingPoint);
	glVertexArrayAttribBinding(hctVAO, attribCol, vaoBindingPoint);

	bool
			can_link_program = true,
			can_use_program = true;

	GLuint frag_shader, vert_shader, program;
	can_link_program &= shader_compile("../src/shaders/triangle_fs.glsl", &frag_shader, GL_FRAGMENT_SHADER);
	can_link_program &= shader_compile("../src/shaders/triangle_vs.glsl", &vert_shader, GL_VERTEX_SHADER);

	if (can_link_program)
	{
		can_use_program &= create_program(frag_shader, vert_shader, &program);
	}

	if (can_use_program)
	{
		glUseProgram(program);
	}

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(hctVAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// glCompileShader(vertexShader);

	// int success;
	// char infoLog[512];
	// glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	// if (!success)
	// {
	// 	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	// 	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
	// 						<< infoLog << std::endl;
	// }

	// while (!glfwWindowShouldClose(window))
	// {
	// 	glfwSwapBuffers(window);
	// 	glfwPollEvents();
	// }

	glfwTerminate();
	return 0;
}

// #include "headers/pch/opengl_libs.hpp"

// #include "headers/utils.hpp"
// #include <iostream>

// int main()
// {
// 	if (!glfwInit())
// 	{
// 		std::cerr << "Can't init GLFW" << std::endl;
// 	}

// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
// 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
// 	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// 	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

// 	GLuint _shader = glCreateShader(GL_FRAGMENT_SHADER);

// 	// shader_compile("../src/shaders/triangle_fs.glsl", GL_FRAGMENT_SHADER);
// }
