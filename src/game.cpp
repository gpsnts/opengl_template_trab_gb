#include "headers/game.hpp"

Render *render;
Shader selected_shader;

void debug_mat4(glm::mat4 to_view)
{
	cout << "DEBUG: " << glm::to_string(to_view) << endl;
}

Render *Game::get_render()
{
	return render;
}

Shader Game::get_shader()
{
	return selected_shader;
}

Game::~Game()
{
	cout << "Deleting render" << endl;
	delete render;
}

void Game::projection(bool enabled)
{
	glm::mat4 projection(1.0f);
	
	if (enabled)
	{
		projection = glm::ortho(
			-10.0f, 	10.0f,  // X (min-max)
			-10.0f, 	10.0f,  // Y (min-max)
			-1.0f,  	1.0f    // Z (min-max)
		);
	}

	glUseProgram(selected_shader.getProgram());
	glUniformMatrix4fv(
		glGetUniformLocation(selected_shader.getProgram(), "projection"),
		1,
		GL_FALSE,
		glm::value_ptr(projection)
	);
	glUseProgram(0);
}

void Game::transformations(bool enabled)
{
	glm::mat4 model(1.0f);

	if (enabled)
	{
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, (float) glfwGetTime() * -5.0f, glm::vec3(50.0f, 0.0f, 0.0f));
	}

	glUseProgram(selected_shader.getProgram());
	glUniformMatrix4fv(
		glGetUniformLocation(selected_shader.getProgram(), "model"),
		1,
		GL_FALSE,
		glm::value_ptr(model)
	);
	glUseProgram(0);
}

void Game::init()
{
	Resources::assign_shader(
		"../src/shaders/triangle.vert",
		"../src/shaders/triangle.frag",
		"shader_uniform"
	);

	selected_shader = Resources::get_shader("shader_uniform");
	
	render = new Render(selected_shader);
	render->render_data(
		{
			0.f,  0.f,  0.f,
		 -0.3f, 0.5f, 0.f,
			0.3f, 0.5f, 0.f
		},
		{}
	);
}

void Game::build() {
	glUseProgram(selected_shader.getProgram());
		
	GLint colorLoc = glGetUniformLocation(
		selected_shader.getProgram(),
		"inputColor"
	);

	glUniform4f(colorLoc, 1.f, 0.f, 0.f, 1.f);

	glBindVertexArray(render->get_vao());

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glUseProgram(0);
}

void Game::events(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) cout << "Pressed A" << endl;
}