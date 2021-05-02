#include "headers/render.hpp"

GLuint Render::get_vao()
{
	return this->vao;
}

void Render::vbo_attrib(GLuint index, GLuint stride, GLuint offset)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glVertexAttribPointer(
		index,
		3,
		GL_FLOAT,
		GL_FALSE, 
		GL_CALC_STRIDE(stride),
		GL_CALC_OFFSET(offset)
	);
	glEnableVertexAttribArray(index);
}


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

	if (ebo_indexes.size() > 0)
	{
		GLuint clone_ebo[ebo_indexes.size()];

		copy(
			ebo_indexes.begin(),
			ebo_indexes.end(),
			clone_ebo	
		);

		glGenBuffers(1, &this->ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(clone_ebo), clone_ebo, GL_STATIC_DRAW);
	}
}

Render::Render(Shader &shader)
{
	this->shader = shader;
}

Render::~Render()
{
	cout << "Deleting shader VAO, VBO, EBO" << endl;
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
	this->vbo_attrib(0, 0, 0);
}