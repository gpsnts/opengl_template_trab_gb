#include "headers/render.hpp"

void Render::bind_vertex()
{
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);
}

void Render::bind_buffer(vector<GLfloat> &data)
{
	GLfloat clone[data.size()];
	copy(
		data.begin(),
		data.end()
		clone
	);
}

Render::Render(Shader &shader)
{
	this->shader = shader;
}

Render::~Render()
{
	glDeleteVertexArrays(1, &this->vao);
}

void Render::render_data(
	initializer_list<GLfloat> data
	// GLboolean using_ebo
)
{

}

void Render::render_data(
	initializer_list<GLfloat> vertices,
	initializer_list<GLfloat> colors
	// GLboolean using_ebo
)
{
	
}