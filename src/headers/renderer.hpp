#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "pch/glad_pch.hpp"
#include "pch/glfw_pch.hpp"

#include "shader.hpp"
#include "texture.hpp"

using namespace glm;

class Renderer
{
private:
	Shader shader;
	GLuint VAO;
	void render_data();

public:
	Renderer(Shader &shader);
	~Renderer();
	
	void draw_texture(
		Texture &texture,
		vec2 position,
		vec2 size = vec2(10, 10),
		GLfloat rotate = 0.0f,
		vec3 color = vec3(1.0f)
	);
};

#endif // __RENDERER_HPP__