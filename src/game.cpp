#include "headers/game.hpp"

Game::~Game()
{
	std::cout << "Destruct game" << std::endl;
	Resources::clean();
}

void Game::init()
{
	Resources::assign_shader(
		"../src/shaders/triangle.vert",
		"../src/shaders/triangle_uniform.frag",
		"shader_uniform"
	);
}