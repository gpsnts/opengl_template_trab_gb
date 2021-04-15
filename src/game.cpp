#include "headers/game.hpp"

Render *render;
Shader selected_shader;

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

void Game::transformations()
{
	glm::mat4 model(1.0f);
	model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
	model = glm::rotate(model, (float) glfwGetTime() * -5.0f, glm::vec3(50.0f, 0.0f, 0.0f));

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
			-1.f, -1.f, 0.f,
			 1.f, -1.f, 0.f,
			 0.f,  1.f, 0.f
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