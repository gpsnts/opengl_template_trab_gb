#include "headers/renderer.hpp"

std::map<std::string, GLuint> Renderer::get_vaos()
{
	return vaos;
}

std::map<std::string, GLuint> Renderer::get_vbos()
{
	return vbos;
}

std::map<std::string, GLuint> Renderer::get_ebos()
{
	return ebos;
}

std::map<std::string, std::vector<GLuint>> Renderer::get_ebos_indexes()
{
	return ebos_indexes;
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

void Renderer::set_data(
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
	case POSITION:
		positions[key_selected].assign(payload);
	case COLOR:
		colors[key_selected].assign(payload);
	default:
		return;
	}
}

void Renderer::set_ebo_data(
	string key_selected,
	std::initializer_list<GLuint> payload
)
{
	ebos_indexes[key_selected].assign(payload);
}

void Renderer::bind_buffer(
	Type type,
	string key_buffer,
	string key_array
)
{
	size_t size = -1;

	switch (type)
	{
	case DATA:
		size = data[key_array].size();
		break;
	case POSITION:
		size = positions[key_array].size();
		break;
	case COLOR:
		size = colors[key_array].size();
		break;
	default:
		cout << "ERROR - Getting Type vector size" << endl;
		return;
	}
	
	GLfloat clone[size];

	switch (type)
	{
	case DATA:
		 std::copy(
			data[key_array].begin(),
			data[key_array].end(),
			clone
		);
		break;
	case POSITION:
		std::copy(
			positions[key_array].begin(),
			positions[key_array].end(),
			clone
		);
		break;
	case COLOR:
		std::copy(
			colors[key_array].begin(),
			colors[key_array].end(),
			clone
		);
		break;
	default:
		cout << "ERROR - Cloning vec to array" << endl;
		return;
	}
         
	glGenBuffers(1, &vbos[key_buffer]);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[key_buffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(clone), clone, GL_STATIC_DRAW);
}

void Renderer::bind_ebo_buffer(
	string key_ebo_buffer,
	string key_array
)
{
	size_t size =  ebos_indexes[key_array].size();
	GLuint clone[size];

	std::copy(
		ebos_indexes[key_array].begin(),
		ebos_indexes[key_array].end(),
		clone
	);

	glGenBuffers(1, &ebos[key_ebo_buffer]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebos[key_ebo_buffer]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(clone), clone, GL_STATIC_DRAW);
}


void Renderer::bind_vertex(string key_vertex)
{
	glGenVertexArrays(1, &vaos[key_vertex]);
	glBindVertexArray(vaos[key_vertex]);
}

void Renderer::vbo_attrib(
	string key_buffer,
	GLuint layout_index,
	int stride,
	int offset
)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbos[key_buffer]);
	glVertexAttribPointer(
		layout_index,
		3,
		GL_FLOAT,
		GL_FALSE, 
		GL_CALC_STRIDE(stride),
		GL_CALC_OFFSET(offset)
	);
	glEnableVertexAttribArray(layout_index);
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

	for (auto ebo : ebos)
	{
		glDeleteBuffers(1, &ebo.second);
	}
}