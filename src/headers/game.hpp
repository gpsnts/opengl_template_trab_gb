#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>

#include "game.hpp"
#include "resources.hpp"
#include "render.hpp"
#include "shader.hpp"
class Game
{
private:
	GLint ref_height, ref_width;
public:
	~Game();
	Game(GLint s_height, GLint s_width) {
		this->ref_height = s_height;
		this->ref_width = s_width;
	};

	void events(GLFWwindow *window);
	void projection(bool enabled = false, bool aspect_projection = false);
	void transformations(bool enabled = false);
	void init();
	void build();

	GLint get_height();
	GLint get_width();
	Render *get_render();
	Shader get_shader();
};

#endif // __GAME_HPP__
