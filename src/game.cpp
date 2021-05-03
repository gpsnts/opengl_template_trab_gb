#include "headers/game.hpp"

Renderer *renderer;
Shader selected_shader;

GameObject *player;
GameObject *cloud_1;

const GLfloat PLAYER_VELOCITY(500.f);

Game::~Game()
{
	cout << "Deleting game itens (Renderer, GameObject(s), Shader)" << endl;
	delete renderer;
	delete player, cloud_1;
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
	
	Resources::assign_texture("../src/textures/dino_chrome_dinossaur.png", GL_TRUE, "character");
	Resources::assign_texture("../src/textures/dino_chrome_floor_compose.png", GL_TRUE, "floor_asset");
	Resources::assign_texture("../src/textures/dino_chrome_cloud.png", GL_TRUE, "cloud_1");

	// vec2 PLAYER_SIZE(800, 215);
	vec2 PLAYER_SIZE(200, 215);
	vec2 CLOUD_1_SIZE(230, 70);
	
	vec2 player_pos = vec2(
		0,
		(this->ref_height - (215.f + 55.47225f))
	);

	vec2 cloud_1_pos(
		this->ref_width - 500,
		125
		
		// 25,
		// (this->ref_height - (this->ref_height * 0.67f))
	);

	player 	= new GameObject(Resources::get_texture("character"), player_pos, PLAYER_SIZE);
	cloud_1 = new GameObject(Resources::get_texture("cloud_1"), cloud_1_pos, CLOUD_1_SIZE);
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
	cloud_1->draw(*renderer);
}