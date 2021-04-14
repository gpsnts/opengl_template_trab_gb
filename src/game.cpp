#include "headers/game.hpp"

Render *render;
Shader selected_shader;

Game::~Game()
{
	cout << "Deleting render" << endl;
	delete render;
}

void Game::init()
{
	Resources::assign_shader(
		"../src/shaders/triangle.vert",
		"../src/shaders/triangle_uniform.frag",
		"shader_uniform"
	);

	selected_shader = Resources::get_shader("shader_uniform");
	
	render = new Render(selected_shader);
	render->render_data(
		{
			 0.0f, 0.0f, 0.0f,
			 0.33f, 0.50f, 0.0f,
			-0.33f, 0.50f, 0.0f,

			 0.0f, 0.0f, 0.0f,
			-0.33f, -0.50f, 0.0f,
			 0.33f, -0.50f, 0.0f,

			 0.0f, 0.0f, 0.0f,
			 0.33f, 0.50f, 0.0f,
			 0.33f, -0.50f, 0.0f,

			 0.0f,   0.0f,  0.0f,
			-0.33f,  0.50f, 0.0f,
			-0.33f, -0.50f, 0.0f,
		},
		{}
	);
}

void Game::build() {
	GLint colorLoc = glGetUniformLocation(
		selected_shader.getProgram(),
		"inputColor"
	);
	
	glUseProgram(selected_shader.getProgram());
	glBindVertexArray(render->get_vao());
	
	if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 0.0f, 10.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 1.0f, 0.0f, 10.0f);
	glDrawArrays(GL_TRIANGLES, 3, 6);
	
	if (colorLoc > -1) glUniform4f(colorLoc, 0.0f, 0.0f, 1.0f, 10.0f);
	glDrawArrays(GL_TRIANGLES, 6, 9);

	if (colorLoc > -1) glUniform4f(colorLoc, 1.0f, 0.0f, 1.0f, 10.0f);
	glDrawArrays(GL_TRIANGLES, 9, 12);

	glBindVertexArray(0);
}