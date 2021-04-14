#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#include <vector>
#include <algorithm>
#include <numeric>
#include <initializer_list>

#include "pch/glfw_pch.hpp"
#include "pch/glad_pch.hpp"
#include "shader.hpp"

using namespace std;

class Render
{
private:
	GLuint vao, ebo;
	Shader shader;
	void bind_vertex();
	void bind_buffer(vector<GLfloat> &data);
	void bind_ebo_buffer();
public:
	~Render();
	Render(Shader &shader);
	
	GLuint get_vao();

	void render_data(
		initializer_list<GLfloat> data
		// GLboolean using_ebo
	);
	void render_data(
		initializer_list<GLfloat> vertices,
		initializer_list<GLfloat> colors
		// GLboolean using_ebo
	);
	// TODO: Texture Draw
};

#endif // __RENDER_HPP__
