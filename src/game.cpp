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
			-1.f, -1.f, 0.f,
			1.f, -1.f, 0.f,
			0.f, 1.f, 0.f
			//  0.0f, 0.0f, 0.0f,
			//  0.33f, 0.50f, 0.0f,
			// -0.33f, 0.50f, 0.0f
		},
		{}
	);
}

void Game::build() {
}