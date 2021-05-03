#include "headers/game.hpp"

Renderer *renderer;
Shader selected_shader;

GameObject *player;
GameObject *obj1;
const GLfloat PLAYER_VELOCITY(500.0f);

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
		0.0f, static_cast<GLfloat>(this->ref_width), 
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
	
	Resources::assign_texture("../src/textures/dino_chrome_spreadsheet.png", GL_TRUE, "char");
	
	vec2 OBJECT_SIZE(800, 215);
	
	vec2 player_pos = vec2(
		0,
		0
	);

	player = new GameObject(Resources::get_texture("char"), player_pos, OBJECT_SIZE);
}

void Game::build()
{
	player->draw(*renderer);
}

void Game::events(
	GLFWwindow *window,
	GLfloat &left,
	GLfloat &right,
	GLfloat &up,
	GLfloat &bottom
)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) 	left 		+= 0.01f;
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) right 	+= 0.01f;
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) 		up 			+= 0.01f;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) 	bottom 	+= 0.01f;
}