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
			 0.0f, 0.0f, 0.0f,
			 0.33f, 0.50f, 0.0f,
			-0.33f, 0.50f, 0.0f
		},
		{}
	);
}

int c_flag = 0; 

bool flag = true;

void Game::build() {
	if (c_flag % 200 == 0) flag = !flag;

	// GLint colorLoc = glGetUniformLocation(
	// 	selected_shader.getProgram(),
	// 	"inputColor"
	// );

	// glUseProgram(selected_shader.getProgram());

	// glBindVertexArray(render->get_vao());
	
	// if (colorLoc > -1)
	// {
	// 	if (flag) glUniform4f(colorLoc, 1.0f, 0.0f, 0.0f, 10.0f);
	// 	else glUniform4f(colorLoc, 0.0f, 0.0f, 1.0f, 10.0f);
	// }
	// glDrawArrays(GL_TRIANGLES, 0, 3);

	// glBindVertexArray(0);
	// glUseProgram(0);
}