#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#define GL_CALC_STRIDE(x) (x * sizeof(GLfloat))
#define GL_CALC_OFFSET(x) ((GLvoid *)(x * sizeof(GLfloat)))

#include <iostream>
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
	GLuint vao, vbo, ebo;
	Shader shader;
	void bind_vertex();
	void bind_buffer(vector<GLfloat> data, vector<GLuint> ebo_indexes);

	void vbo_attrib(GLuint index, GLuint stride, GLuint offset);
public:
	~Render();
	Render(Shader &shader);
	
	GLuint get_vao();

	void render_data(
		initializer_list<GLfloat> data,
		initializer_list<GLuint> ebo_indexes
	);
};

#endif // __RENDER_HPP__
