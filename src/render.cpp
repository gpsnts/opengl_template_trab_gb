#include "headers/render.hpp"

void Render::bind_vertex()
{
	glGenVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);
}

void Render::bind_buffer(vector<GLfloat> data, vector<GLuint> ebo_indexes)
{
	GLfloat clone[data.size()];
	
	copy(
		data.begin(),
		data.end(),
		clone
	);

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(clone), clone, GL_STATIC_DRAW);
}

Render::Render(Shader &shader)
{
	this->shader = shader;
}

Render::~Render()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
}

void Render::render_data(
	initializer_list<GLfloat> data,
	initializer_list<GLuint> ebo_indexes
)
{
	this->bind_vertex();
	this->bind_buffer(data, ebo_indexes);
}

void Render::render_data(
	initializer_list<GLfloat> vertices,
	initializer_list<GLfloat> colors,
	initializer_list<GLuint> ebo
)
{
	
}