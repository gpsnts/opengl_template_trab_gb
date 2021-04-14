#include "headers/game.hpp"

Game::~Game()
{
	delete render;
}

void Game::init()
{
	Resources::assign_shader(
		"../src/shaders/triangle.vert",
		"../src/shaders/triangle_uniform.frag",
		"shader_uniform"
	);

	Shader selected_shader = Resources::get_shader("shader_uniform");
	
	render = new Render(selected_shader);
	render->render_data({1.0, 1.0}, {});
	
	delete render;
}

void Game::build() {}