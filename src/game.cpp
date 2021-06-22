#include "headers/game.hpp"

string selected_image;
vector<string> available_images;

Renderer *renderer;
Shader selected_shader;
mat4 projection;
vec2 LENA_SIZE(800, 600), LENA_POSITION(800 * .33f, 600 * .15f);
vec2 INPUT_SIZE(1366 * 0.1, 768 * 0.15);

GameObject *lena;
GameObject *doge;
GameObject *filtro_1, *filtro_2, *filtro_3, *filtro_4, *filtro_5, *filtro_6, *filtro_7;

Game::~Game()
{
	cout << "Deleting game itens (Renderer, GameObject(s), Shader)" << endl;
	delete renderer;
	delete lena, doge,
				 filtro_1, filtro_2, filtro_3,
				 filtro_4, filtro_5, filtro_6,
				 filtro_7;
}

void Game::init()
{
	for (const auto &file : filesystem::directory_iterator("../src/textures/edit")) {
		cout << file.path().stem() << endl;
	}

	for (auto item : available_images) cout << item << endl; 

	cout << "Escolha uma das imagens a cima" << endl;
	cin >> selected_image;

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
	
	Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
	Resources::assign_texture("../src/textures/edit/doge.png", GL_TRUE, "doge");
	Resources::assign_texture("../src/textures/filtro_1.png", GL_TRUE, "filtro_1");
	Resources::assign_texture("../src/textures/filtro_2.png", GL_TRUE, "filtro_2");
	Resources::assign_texture("../src/textures/filtro_3.png", GL_TRUE, "filtro_3");
	Resources::assign_texture("../src/textures/filtro_4.png", GL_TRUE, "filtro_4");
	Resources::assign_texture("../src/textures/filtro_5.png", GL_TRUE, "filtro_5");
	Resources::assign_texture("../src/textures/filtro_6.png", GL_TRUE, "filtro_6");
	Resources::assign_texture("../src/textures/filtro_7.png", GL_TRUE, "filtro_7");

	lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
	doge = new GameObject(Resources::get_texture("doge"), vec2(0, this->ref_height), vec2(250, 250));

	filtro_1 = new GameObject(Resources::get_texture("filtro_1"), INPUT_SIZE, vec2(120, 60));
	filtro_2 = new GameObject(Resources::get_texture("filtro_2"), vec2(INPUT_SIZE.x, INPUT_SIZE.y + 90), vec2(120, 60));
	filtro_3 = new GameObject(Resources::get_texture("filtro_3"), vec2(INPUT_SIZE.x, INPUT_SIZE.y + 180), vec2(120, 60));
	filtro_4 = new GameObject(Resources::get_texture("filtro_4"), vec2(INPUT_SIZE.x, INPUT_SIZE.y + 270), vec2(120, 60));
	filtro_5 = new GameObject(Resources::get_texture("filtro_5"), vec2(INPUT_SIZE.x, INPUT_SIZE.y + 360), vec2(120, 60));
	filtro_6 = new GameObject(Resources::get_texture("filtro_6"), vec2(INPUT_SIZE.x, INPUT_SIZE.y + 450), vec2(120, 60));
	filtro_7 = new GameObject(Resources::get_texture("filtro_7"), vec2(INPUT_SIZE.x, INPUT_SIZE.y + 540), vec2(120, 60));
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
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
		Resources::assign_texture(("../src/textures/edit/" + selected_image + ".png").c_str(), GL_TRUE, "lena");
		Resources::assign_texture("../src/textures/edit/doge.png", GL_TRUE, "doge");

		delete lena, doge;
		lena = new GameObject(Resources::get_texture("lena"), LENA_POSITION, LENA_SIZE);
		doge = new GameObject(Resources::get_texture("doge"), vec2(0, this->ref_height), vec2(250, 250));
	}
}

void Game::build()
{
	lena->draw(*renderer);
	filtro_1->draw(*renderer);
	filtro_2->draw(*renderer);
	filtro_3->draw(*renderer);
	filtro_4->draw(*renderer);
	filtro_5->draw(*renderer);
	filtro_6->draw(*renderer);
	filtro_7->draw(*renderer);
}