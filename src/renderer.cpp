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
	AssignOption selected,
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