#include "headers/renderer.hpp"

std::map<std::string, GLuint> Renderer::get_vaos()
{
	return vaos;
}

std::map<std::string, GLuint> Renderer::get_vbos()
{
	return vbos;
}

std::map<std::string, GLuint> Renderer::get_uniforms_indexes()
{
	return uniforms_indexes;
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

void Renderer::bind_buffer(Type type, string key_buffer, string key_array)
{
	GLfloat clone[type == DATA ? data[key_array].size() : positions[key_array].size()];
	
	std::copy(
		type == DATA ? data[key_array].begin() : positions[key_array].begin(),
		type == DATA ? data[key_array].end() : positions[key_array].end(),
		clone
	);
}