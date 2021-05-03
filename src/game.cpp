#include "headers/game.hpp"

Renderer *renderer;
Shader selected_shader;

GameObject *player;

const GLfloat PLAYER_VELOCITY(500.f);

Game::~Game()
{
	cout << "Deleting game itens (Renderer, GameObject(s), Shader)" << endl;
	delete renderer;
	delete player;
}

void Game::init()
{
	Resources::assign_shader(
		"../src/shaders/tga.vert",
		"../src/shaders/tga.frag",
		"tga"
	);

	
	mat4 projection = glm::ortho(
		0.0f,
		static_cast<GLfloat>(this->ref_width), 
  	static_cast<GLfloat>(this->ref_height),
		0.0f,
		-1.0f,
		1.0f
	);

	Resources::get_shader("tga").use().set_int("image", 0);
	Resources::get_shader("tga").set_mat4("projection", projection);

	Shader sprite;
	sprite = Resources::get_shader("tga");
	renderer = new Renderer(sprite);
	
	Resources::assign_texture("../src/textures/dino_chrome_spreadsheet_v2.png", GL_TRUE, "character");
	Resources::assign_texture("../src/textures/dino_chrome_floor_compose.png", GL_TRUE, "floor_asset");
	
	vec2 PLAYER_SIZE(800, 215);
	
	vec2 player_pos = vec2(
		0,
		(this->ref_height - (215 + 50))
	);

	player = new GameObject(Resources::get_texture("character"), player_pos, PLAYER_SIZE);
}

void Game::handle_input(GLfloat delta, GLint movement, GLboolean action, GLint width, GLint height)
{
	std::cout << "DELTA: " << delta << std::endl;

  GLfloat velocity = PLAYER_VELOCITY * delta;
  if (movement == -1)
    {
      if (player->obj_position.x >= 0) {
        player->obj_position.x -= velocity;
      }
    }
  if (movement == 1)
  {
    if (player->obj_position.x <=  width - player->obj_size.x) {
      player->obj_position.x += velocity;
    }
  }
}

void Game::update()
{

}

void Game::build()
{
	Texture text_floor;
	text_floor = Resources::get_texture("floor_asset");
	renderer->draw_texture(text_floor, vec2(0, (this->ref_height - 320)), vec2(6000, 320));
	player->draw(*renderer);
}