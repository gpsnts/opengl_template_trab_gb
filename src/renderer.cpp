#include "headers/renderer.hpp"

std::map<std::string, GLuint> Renderer::get_vaos()
{
	return vaos;
}

std::map<std::string, GLuint> Renderer::get_vbos()
{
	return vbos;
}

std::map<std::string, GLuint> Renderer::get_layout_indexes()
{
	return layout_indexes;
}

std::map<std::string, std::vector<GLfloat>> Renderer::get_data()
{
	return data;
}

std::map<std::string, std::vector<GLfloat>> Renderer::get_positions()
{
	return positions;
}

std::map<std::string, std::vector<GLfloat>> Renderer::get_colors()
{
	return colors;
}

bool Renderer::set_data(
	Type selected,
	string key_selected,
	std::initializer_list<GLfloat> payload
)
{
	// Não usei ponteiro por fins de economia de mem/performance
	// Já que, majoritariamente, a class Renderer não é usada com um "new"
	switch (selected)
	{
	case DATA:
		data[key_selected].assign(payload);
		return true;
	case POSITION:
		positions[key_selected].assign(payload);
		return true;
	case COLOR:
		colors[key_selected].assign(payload);
		return true;
	default:
		return false;
	}
}

// TODO: Refatorar -- !!! HARD-CODED
void Renderer::bind_buffer(Type type, string key_buffer, string key_array)
{
	GLfloat clone[type == DATA ? data[key_array].size() : type == POSITION ? positions[key_array].size() : colors[key_array].size()];
	
	std::copy(
		type == DATA ? data[key_array].begin() : type == POSITION ? positions[key_array].begin() : colors[key_array].begin(),
		type == DATA ? data[key_array].end() : type == POSITION ? positions[key_array].end() : colors[key_array].end(),
		clone
	);

	glGenBuffers(1, &vbos[key_buffer]);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[key_buffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(clone), clone, GL_STATIC_DRAW);
}


void Renderer::bind_vertex(string key_vertex)
{
	glGenVertexArrays(1, &vaos[key_vertex]);
	glBindVertexArray(vaos[key_vertex]);
}

void Renderer::vbo_attrib(
	string key_buffer,
	string key_layout,
	GLuint layout_index,
	int stride,
	int offset
)
{
	layout_indexes[key_layout] = layout_index;

	glBindBuffer(GL_ARRAY_BUFFER, vbos[key_buffer]);
	glVertexAttribPointer(
		layout_indexes[key_layout],
		3,
		GL_FLOAT,
		GL_FALSE, 
		GL_CALC_STRIDE(stride),
		GL_CALC_OFFSET(offset)
	);
	glEnableVertexAttribArray(layout_indexes[key_layout]);
}

void Renderer::clean()
{
	for (auto vao : vaos){
		glDeleteVertexArrays(1, &vao.second);
	}	

	for (auto vbo : vbos)
	{
		glDeleteBuffers(1, &vbo.second);
	}
}