#include "headers/game.hpp"

Renderer *renderer;
Shader selected_shader;
mat4 projection;
vec2 LENA_SIZE(1366, 768), LENA_POSITION(0, 0);

GameObject *lena;
GameObject *doge;

const GLfloat PLAYER_VELOCITY(375.f);

Game::~Game()
{
	cout << "Deleting game itens (Renderer, GameObject(s), Shader)" << endl;
	delete renderer;
	delete lena, doge;
}

void Game::init()
{
	Resources::assign_shader(
		"../src/shaders/tga.vert",
		"../src/shaders/tga.frag",
		"tga"
	);

	
	projection = glm::ortho(
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
	

	Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
	Resources::assign_texture("../src/textures/doge.png", GL_TRUE, "doge");

	lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	doge = new GameObject(Resources::get_texture("doge"), vec2(0, this->ref_height), vec2(250, 250));
}

void Game::handle_input(GLfloat delta, GLint selection, GLboolean action, GLint width, GLint height)
{
	if (selection == -1)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/tga.frag", "tga");
		Resources::get_shader("tga").use().set_int("image", 0);
		Resources::get_shader("tga").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("tga");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 0)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_a.frag", "1_a");
		Resources::get_shader("1_a").use().set_int("image", 0);
		Resources::get_shader("1_a").use().set_int("code", 1);
		Resources::get_shader("1_a").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_a");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 1)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_a.frag", "1_a");
		Resources::get_shader("1_a").use().set_int("image", 0);
		Resources::get_shader("1_a").use().set_int("code", 2);
		Resources::get_shader("1_a").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_a");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 2)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_a.frag", "1_a");
		Resources::get_shader("1_a").use().set_int("image", 0);
		Resources::get_shader("1_a").use().set_int("code", 3);
		Resources::get_shader("1_a").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_a");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 3)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_b.frag", "1_b");
		Resources::get_shader("1_b").use().set_int("image", 0);
		Resources::get_shader("1_b").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_b");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 4)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_c.frag", "1_c");
		Resources::get_shader("1_c").use().set_int("image", 0);
		Resources::get_shader("1_c").use().set_vec3("spriteColor", vec3(1.0, 0.0, 1.0));
		Resources::get_shader("1_c").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_c");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 5)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_d.frag", "1_d");
		Resources::get_shader("1_d").use().set_int("image", 0);
		Resources::get_shader("1_d").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_d");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 6)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_e.frag", "1_e");
		Resources::get_shader("1_e").use().set_int("image", 0);
		Resources::get_shader("1_e").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_e");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		delete lena;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	}

	if (selection == 7)
	{
		Resources::assign_shader("../src/shaders/tga.vert", "../src/shaders/1_f.frag", "1_f");
		Resources::get_shader("1_f").use().set_int("image1", 0);
		Resources::get_shader("1_f").use().set_int("image2", 0);
		Resources::get_shader("1_f").use().set_vec3("iColor", vec3(1.0, 1.0, 0.0));
		Resources::get_shader("1_f").set_mat4("projection", projection);
		Shader sprite;
		sprite = Resources::get_shader("1_f");
		renderer = new Renderer(sprite);
		Resources::assign_texture("../src/textures/lena.png", GL_TRUE, "lena");
		Resources::assign_texture("../src/textures/doge.png", GL_TRUE, "doge");

		delete lena, doge;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
		doge = new GameObject(Resources::get_texture("doge"), vec2(0, this->ref_height), vec2(250, 250));
	}
}

void Game::build()
{
	// Texture text_floor;
	// text_floor = Resources::get_texture("floor_asset");
	// renderer->draw_texture(text_floor, vec2(0, (this->ref_height - 320)), vec2(6000, 320));
	lena->draw(*renderer);
}